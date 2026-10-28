# Direct ALSA capture results

Boot condition: cold

| Test | PCM | Route | Status | Digital silence | Voice heard |
|---|---|---|---|---|---|
| 01-pcm0-original | hw:Audio_1,0 | original-state | ok | False | unreviewed |
| 02-pcm1-original | hw:Audio_1,1 | original-state | ok | False | unreviewed |
| 03-pcm2-original | hw:Audio_1,2 | original-state | ok | True | unreviewed |
| 04-pcm0-switch13-max | hw:Audio_1,0 | Line Capture Switch index=0 | ok | True | unreviewed |
| 05-pcm1-switch13-max | hw:Audio_1,1 | Line Capture Switch index=0 | ok | False | unreviewed |
| 06-pcm2-switch13-max | hw:Audio_1,2 | Line Capture Switch index=0 | ok | True | unreviewed |
| 07-pcm0-switch17-max | hw:Audio_1,0 | Mic Capture Switch index=0 | ok | True | unreviewed |
| 08-pcm1-switch17-max | hw:Audio_1,1 | Mic Capture Switch index=0 | ok | True | unreviewed |
| 09-pcm2-switch17-max | hw:Audio_1,2 | Mic Capture Switch index=0 | ok | False | unreviewed |
| 10-pcm0-switch9-max | hw:Audio_1,0 | Analog In Capture Switch index=0 | ok | False | unreviewed |
| 11-pcm1-switch9-max | hw:Audio_1,1 | Analog In Capture Switch index=0 | ok | True | unreviewed |
| 12-pcm2-switch9-max | hw:Audio_1,2 | Analog In Capture Switch index=0 | ok | True | unreviewed |

Next step: **finish_direct_capture_tests_and_review**

Enumeration or signal level alone does not identify microphone speech. Resolve failed/skipped captures and listen to the recordings before choosing a patch.

Restoration errors: []
