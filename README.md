# Overview
EMUMAN is a dumpster fire of an attempt at making an Original GameBoy Emulator.
It is being created purely for "educational purposes" to gain further insight
into how different computer chips work.

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

GB Spec Sheet <br>
http://www.zilog.com/docs/z80/um0080.pdf

Gambit Existing One <br>
https://github.com/mattrubin/Gambit

GB Emu <br>
https://github.com/jgilchrist/gbemu

### Debuggers

Wasm Debugger <br>
https://wasmboy.app/

Potential Test <br>
https://gbdev.gg8.se/files/roms/blargg-gb-tests/

No$GMB
https://problemkaputt.de/gmb.htm
