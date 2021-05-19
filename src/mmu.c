#include <stdio.h>
#include <stdlib.h>
#include "../inc/structs.h"
#include "../inc/emuman_logs.h"

extern struct ram RAM;
extern struct registers REGISTERS;

/**
 * The MMU of the emulator.  ROM's will be loaded and
 * values will be read from here.
 */

void * load_rom(const char* filename)
{
    u_int8_t* rom_pointer;
    FILE *f;
    long size;

    f = fopen(filename, "r"); //read the first line of the Bootstrap
    fseek(f, 0, SEEK_END); //Go to end of file to get the size
    size = ftell(f);
    fseek(f, 0, SEEK_SET); //Set pointer to front of ROM

    rom_pointer = malloc(sizeof(u_int8_t) * size);
    if(rom_pointer == NULL) {
        error_log("MMU", "Could not Allocate memory");
    }

    u_int8_t *tmp = rom_pointer;
    for(int i = 0; i < size; i++) {
        fread(rom_pointer, sizeof(u_int8_t), 1, f);
        rom_pointer ++;
    }


    fclose(f);

    return tmp;
}


