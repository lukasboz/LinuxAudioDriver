// A persistent local MCP client for an investigation already authorized by the user.
// Save complete tool responses before printing a compact receipt.
import { pathToFileURL } from 'node:url';
import { createRequire } from 'node:module';
import { mkdir, writeFile } from 'node:fs/promises';
import { join, resolve } from 'node:path';
import readline from 'node:readline';

const packageRoot = process.env.REA_PACKAGE_ROOT;
if (!packageRoot) throw new Error('Set REA_PACKAGE_ROOT to the installed rea-agents package');
const requirePackage = createRequire(pathToFileURL(join(packageRoot, 'package.json')));
const { Client } = requirePackage('@modelcontextprotocol/client');
const { StdioClientTransport } = requirePackage('@modelcontextprotocol/client/stdio');
const output = resolve(process.argv[2] ?? 'observations/driver_reverse_engineering/rea');
await mkdir(output, { recursive: true });
const client = new Client({ name: 'audio-driver-investigation', version: '1' });
const transport = new StdioClientTransport({
  command: process.execPath,
  args: [join(packageRoot, 'scripts', 'rea.mjs'), 'mcp'],
  env: process.env,
  stderr: 'pipe',
});
transport.stderr?.on('data', data => process.stderr.write(data));
await client.connect(transport);
const catalog = await client.listTools();
await writeFile(join(output, 'tool-schemas.json'), JSON.stringify(catalog, null, 2));
process.stdout.write(JSON.stringify({ ready: true, tools: catalog.tools.length, output }) + '\n');
let sequence = 0;
const input = readline.createInterface({ input: process.stdin, crlfDelay: Infinity });
for await (const line of input) {
  if (!line.trim()) continue;
  try {
    const request = JSON.parse(line);
    if (request.action === 'exit') break;
    if (request.action === 'schema') {
      process.stdout.write(JSON.stringify(catalog.tools.filter(tool => request.names.includes(tool.name))) + '\n');
      continue;
    }
    if (!catalog.tools.some(tool => tool.name === request.name)) throw new Error('Tool not advertised');
    const result = await client.callTool({ name: request.name, arguments: request.arguments ?? {} }, { timeout: 600000 });
    const name = `${String(++sequence).padStart(3, '0')}-${request.name}.json`;
    const path = join(output, name);
    await writeFile(path, JSON.stringify({ request, result }, null, 2));
    process.stdout.write(JSON.stringify({ saved: path, isError: result.isError ?? false }) + '\n');
  } catch (error) {
    process.stdout.write(JSON.stringify({ error: String(error) }) + '\n');
  }
}
input.close();
await client.close();
process.stdin.pause();
