#include <stdlib.h>
#include <stdio.h>

#include "../inc/emuman_logs.h"
#include "../inc/definitions.h"
#include "../inc/structs.h"

struct ram RAM;
struct gpu GPU;
struct registers REGISTERS;

/**
 * This is currently where the EMUMAN is started.
 */
int main()
{
    //RAM.bootstrap = load_rom("/home/cb/Downloads/DMG_ROM.bin");
    RAM.bootstrap = load_rom("/home/cb/Downloads/DMG_ROM.bin");
    RAM.ROM       = load_rom("/home/cb/Downloads/Tetris.gb");
    RAM.WRAM      = calloc(0, sizeof(u_int8_t) * 0x3DFF);
    RAM.ERAM      = calloc(0, sizeof(u_int8_t) * 0x1FFF);
    RAM.ZRAM      = calloc(0, sizeof(u_int8_t) * 0x007F);

    GPU.OAM       = calloc(0, sizeof(u_int8_t)); //Needs work
    GPU.VRAM      = calloc(0, sizeof(u_int8_t)); //Needs work

    debug_log("MMU", "Load ROM Complete");

    set_up_registers();
    REGISTERS.PC = 0x00;

    for(;;) {
        step_CPU();

        if(REGISTERS.PC > 0xFFFF)
        {
            break;
        }
    }
    printf("\nPC: %d", REGISTERS.PC);
    free(RAM.bootstrap);
    return 0;

}