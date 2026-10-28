// Export static function/string evidence and focused pseudocode. Never execute the input.
// @category AudioDriver
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.Reference;
import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class ExportAudioDriver extends GhidraScript {
    private final Gson gson = new GsonBuilder().setPrettyPrinting().create();

    private Map<String,Object> identify(Function function) {
        Map<String,Object> result = new LinkedHashMap<>();
        result.put("address", "0x" + function.getEntryPoint());
        result.put("name", function.getName());
        result.put("signature", function.getSignature().toString());
        return result;
    }

    public void run() throws Exception {
        String[] arguments = getScriptArgs();
        if (arguments.length < 1) throw new IllegalArgumentException("Provide output directory");
        Path output = Paths.get(arguments[0]);
        Files.createDirectories(output);
        Set<Address> selected = new LinkedHashSet<>();
        if (arguments.length > 1) {
            for (int index = 1; index < arguments.length; index++) {
                for (String value : arguments[index].split(",")) {
                    Function function = getFunctionContaining(toAddr(value));
                    if (function != null) selected.add(function.getEntryPoint());
                }
            }
        }
        List<Map<String,Object>> functions = new ArrayList<>();
        for (Function function : currentProgram.getFunctionManager().getFunctions(true)) {
            functions.add(identify(function));
        }
        List<Map<String,Object>> strings = new ArrayList<>();
        for (Data data : currentProgram.getListing().getDefinedData(true)) {
            if (!(data.getValue() instanceof String)) continue;
            Map<String,Object> item = new LinkedHashMap<>();
            String value = String.valueOf(data.getValue());
            item.put("address", "0x" + data.getAddress());
            item.put("value", value);
            List<Map<String,Object>> references = new ArrayList<>();
            for (Reference reference : currentProgram.getReferenceManager().getReferencesTo(data.getAddress())) {
                Map<String,Object> ref = new LinkedHashMap<>();
                ref.put("from", "0x" + reference.getFromAddress());
                Function function = getFunctionContaining(reference.getFromAddress());
                if (function != null) {
                    ref.put("function", identify(function));
                    if (arguments.length == 1 && value.contains("::") && (value.contains("MicSelection") ||
                        value.contains("PnpStart") || value.contains("AmplifyLevel") ||
                        value.contains("ConnectorStatus") || value.contains("CheckJDStatus") ||
                        value.contains("RestoreSettingsFromRegistry") ||
                        value.contains("ChkPlugState") || value.contains("AssignDeviceType"))) {
                        selected.add(function.getEntryPoint());
                    }
                }
                references.add(ref);
            }
            item.put("references", references);
            strings.add(item);
        }
        Files.writeString(output.resolve("functions.json"), gson.toJson(functions), StandardCharsets.UTF_8);
        Files.writeString(output.resolve("strings.json"), gson.toJson(strings), StandardCharsets.UTF_8);
        DecompInterface decompiler = new DecompInterface();
        decompiler.openProgram(currentProgram);
        try {
            for (Address address : selected) {
                monitor.checkCancelled();
                Function function = getFunctionAt(address);
                Map<String,Object> result = identify(function);
                List<Map<String,Object>> callees = new ArrayList<>();
                for (Function called : function.getCalledFunctions(monitor)) callees.add(identify(called));
                result.put("callees", callees);
                List<Map<String,Object>> callers = new ArrayList<>();
                for (Function caller : function.getCallingFunctions(monitor)) callers.add(identify(caller));
                result.put("callers", callers);
                List<String> assembly = new ArrayList<>();
                for (Instruction instruction : currentProgram.getListing().getInstructions(function.getBody(), true)) {
                    assembly.add("0x" + instruction.getAddress() + " " + instruction.toString());
                }
                result.put("assembly", assembly);
                Files.writeString(output.resolve(address + ".asm"), String.join("\n", assembly) + "\n", StandardCharsets.UTF_8);
                DecompileResults decoded = decompiler.decompileFunction(function, 120, monitor);
                result.put("complete", decoded.decompileCompleted());
                result.put("error", decoded.getErrorMessage());
                if (decoded.getDecompiledFunction() != null) {
                    result.put("pseudocode", decoded.getDecompiledFunction().getC());
                    Files.writeString(output.resolve(address + ".c"), decoded.getDecompiledFunction().getC(), StandardCharsets.UTF_8);
                }
                Files.writeString(output.resolve(address + ".json"), gson.toJson(result), StandardCharsets.UTF_8);
                println("EXPORTED " + address + " " + function.getName());
            }
        } finally {
            decompiler.dispose();
        }
        println("FUNCTIONS " + functions.size() + " STRINGS " + strings.size() + " SELECTED " + selected.size());
    }
}
