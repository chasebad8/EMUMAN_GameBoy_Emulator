# Overview
***
EMUMAN is a dumpster fire of an attempt at making an Original GameBoy Emulator.
It is being created purely for "educational purposes" to gain further insight
into how different computer chips work.

Chase Badalato <br>
Carleton University Department of Electrical and Computer Engineering
## Files
I wanted to try and break all of the code up into files that are various parts
of the gameboy.  Therefore we have
- CPU.c
- MMU.c
- Decoder.c *(Maybe should go into CPU.c)*
- main.c *(will probably get removed)*

# Important Notes
- The Z80 chip that the GameBoy used uses little endian

# Links
***
### OP Tables
OP Table <br>
http://imrannazar.com/Gameboy-Z80-Opcode-Map

Gbops <br>
https://izik1.github.io/gbops/index.html

### Tutorials
Cinoop <br>
https://cturt.github.io/cinoop.html

Emulator 101 <br>
http://emulator101.com/
### Debuggers

Wasm Debugger <br>
https://wasmboy.app/