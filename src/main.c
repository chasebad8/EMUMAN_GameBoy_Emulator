#include <stdlib.h>
#include <stdio.h>

#include "../inc/emuman_logs.h"
#include "../inc/definitions.h"
#include "../inc/structs.h"

struct ram RAM;
struct registers REGISTERS;

/**
 * This is currently where the EMUMAN is started.
 */
int main()
{
    RAM.bootstrap = load_rom("/home/cb/Downloads/DMG_ROM.bin");
    debug_log("MMU", "Load ROM Complete");

    for(;;) {
        step_CPU();

        if(REGISTERS.PC > 256)
        {
            break;
        }
    }
    printf("\nPC: %d", REGISTERS.PC);
    free(RAM.bootstrap);
    return 0;

}