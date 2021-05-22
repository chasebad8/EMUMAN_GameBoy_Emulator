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

/* Based the memory layout off of this link ... hope its right   */
/* http://imrannazar.com/GameBoy-Emulation-in-JavaScript:-Memory */

/**
 * read_8
 *
 * Read the byte contained in the memory location
 * given in "location" and return it.
 *
 * @param location
 * @return
 */
u_int8_t read_8(u_int16_t address)
{
    if(address < 0x0100 && address >= 0x0000)
    {
        return RAM.bootstrap[address];
    }
    //of course will need to add more
}

/**
 * read_16
 *
 * Read 2 bytes from memory.  Depending on the location
 * to be read it will use a different memory array in RAM.
 * @param location
 * @return
 */
u_int16_t read_16(u_int16_t address)
{
    return u8_2_u16(read_8(address), read_8(address + 1));
}