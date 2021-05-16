#include <stdio.h>
#include "../inc/emuman_logs.h"
#include "../inc/definitions.h"
#include "../inc/structs.h"

struct RAM ram;
struct REGISTERS cpu;
/**
 * This is currently where the EMUMAN is started.
 */
int main()
{
    debug_log("MMU", "Starting System");

    ram.bootstrap = load_rom("/home/cb/Downloads/DMG_ROM.bin");

    cpu.PC = 0;

    for(;;) {
        decode(&cpu.PC, ram.bootstrap[cpu.PC]);

        if(cpu.PC > 256)
        {
            break;
        }
    }

    return 0;

}