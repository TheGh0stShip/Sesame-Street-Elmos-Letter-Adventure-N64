# Sesame Street: Elmo's Letter Adventure (Nintendo 64) — complete matching code reconstruction

All **964 catalogued functions** and **438,160 executable bytes** in the USA release reproduce word-for-word from the published sources. Independent verification run v17 compiled every function at its retail address and compared every instruction; float constants and switch tables were checked separately.

| Completion metric | Verified | Catalogued | Progress |
|---|---:|---:|---:|
| **Functions reproduced from verified source** | **964** | **964** | **100.00%** |
| **Code bytes reproduced from verified source** | **438,160** | **438,160** | **100.00%** |
| Ordinary matching C functions | 911 | 964 | 94.50% |
| Ordinary matching C bytes | 428,252 | 438,160 | 97.74% |

[![Source-complete code](https://bytematch.dev/TheGh0stShip/Sesame-Street-Elmos-Letter-Adventure-N64.svg?version=usa&category=catalogued-code&measure=complete_code_percent&label=Source-complete%20code)](https://bytematch.dev/TheGh0stShip/Sesame-Street-Elmos-Letter-Adventure-N64/usa)
[![Matching C bytes](https://bytematch.dev/TheGh0stShip/Sesame-Street-Elmos-Letter-Adventure-N64.svg?version=usa&category=catalogued-code&measure=matched_code_percent&label=Matching%20C%20bytes)](https://bytematch.dev/TheGh0stShip/Sesame-Street-Elmos-Letter-Adventure-N64/usa)

ByteMatch's **complete code / units** measurement is the project-completion figure. The ordinary-C score deliberately excludes 53 files containing required MIPS assembly; those units are complete source, not missing work.

## Verification and provenance

- USA ROM SHA-1: `97777ca06f4e8aff8f1e95033cc8d3833be40f76` (the ROM is not included).
- `VERIFY.tsv` records the address, owned size, compiler lane, source origin and `word_exact` verdict for every function.
- `progress-inventory.tsv` and `source-accounted.tsv` bind every interval to its published source SHA-256.
- `NAMES.tsv` records resolved named references used during strict replay.
- GitHub Actions validates counts, ranges, source digests, proof rows and generated tracker reports on every push.

The source is a byte-matching reconstruction, not a claim that every function is human-restored or portable. `UGLY_FORMS.tsv` identifies compiler-sensitive forms retained for matching.

## Assets and ROM reconstruction

Every byte of the 8 MiB ROM and all eight unpacked level images is classified with zero unknown ranges. The last measured whole-ROM build matched the original SHA-1 while regenerating **82.8%** of ROM bytes and placing the remaining identified bytes verbatim. Later component encoders passed their own byte-exact checks, but the end-to-end regeneration percentage has not yet been remeasured. The pending DOS gzip 1.2.4 experiment is not counted unless it reproduces all compressed level streams exactly.

Research maps and format notes are under `docs/asset-research/`; extracted copyrighted assets are not included.
