# cybersec-bn0

Class warm-up for *Introduction to Computer Security* at the University of Athens (Department of Informatics & Telecommunications).

A small buffer-overflow exercise on a tiny C target (`camelot.c` / `camelot_wrap.c`). Following the guided example from the assignment brief, I overflow a stack buffer to redirect execution and grab the flag.

## What's in this repo

- **`camelot.c`** / **`camelot_wrap.c`** — the vulnerable target.
- **`exploit.py`** — the working exploit.
- **`exploit_notes.md`** — detailed notes (in English): the offset, the return address, why some early ideas were dropped, and what the final solution does.
- **`asciinema.cast`** — terminal recording of the exploit running. Replay with:
  ```bash
  asciinema play asciinema.cast
  ```

## Sequence

Part of a five-piece cybersecurity coursework cluster:

1. **cybersec-bn0** *(you are here)* — class warm-up
2. [cybersec-hw0](https://github.com/AlexTuring010/cybersec-hw0) — first homework
3. [cybersec-hw1](https://github.com/AlexTuring010/cybersec-hw1) — HackCenter binary exploitation (1230 points)
4. [cybersec-hw2](https://github.com/AlexTuring010/cybersec-hw2) — HackCenter web & crypto (3rd place)
5. [cybersec-hw3-chimera-agents](https://github.com/AlexTuring010/cybersec-hw3-chimera-agents) — team CTF capstone
