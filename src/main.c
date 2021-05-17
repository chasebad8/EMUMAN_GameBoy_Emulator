#include <stdlib.h>
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
        if(decode(&cpu.PC, ram.bootstrap[cpu.PC]) == -1)
        {
            printf("\nPC: %d", cpu.PC);
            return(-1);
        }

        if(cpu.PC > 256)
        {
            break;
        }
    }
    free(ram.bootstrap);
    return 0;

}