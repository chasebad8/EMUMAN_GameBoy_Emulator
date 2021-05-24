#ifndef EMUMAN_STRUCTS_H
#define EMUMAN_STRUCTS_H

#endif //EMUMAN_STRUCTS_H

#include <stdlib.h>
#include <stdio.h>

#define S_FLAG (1 << 7) //Sign
#define Z_FLAG (1 << 6) //Zero
#define H_FLAG (1 << 4) //Half Carry
#define V_FLAG (1 << 2) //Overflow
#define N_FLAG (1 << 1) //Negative
#define C_FLAG (1 << 0) //Carry

#define FLAG_SET(x, y)    (y |= x)
#define FLAG_IS_SET(x, y) (y & x)
#define FLAG_CLEAR(x, y)  (y &= ~x)

#define u8_2_u16(x, y) (x | (y << 8))

struct ram
{
    //0000 - 3FFF Cartridge ROM
    u_int8_t *bootstrap; //0000 - 00FF BIOS (Gets overridden)
    u_int8_t *ROM;

    //A000 - BFFF External Cartridge RAM
    u_int8_t *ERAM;

    //C000 - DFFF Working RAM
    u_int8_t *WRAM;

    //FF80 - FFFF Zero Page RAM
    u_int8_t *ZRAM;
};

struct gpu
{
    u_int8_t *VRAM; //Virtual RAM
    u_int8_t *OAM;  //Object Attribute Memory
};

/**
 * registers contain information about all
 * of the current values in the registers
 */
struct registers {
    struct {
        union {
            struct {
                u_int8_t F;
                u_int8_t A;
            };
            u_int16_t AF;
        };
    };

    struct {
        union {
            struct {
                u_int8_t C;
                u_int8_t B;
            };
            u_int16_t BC;
        };
    };

    struct {
        union {
            struct {
                u_int8_t E;
                u_int8_t D;
            };
            u_int16_t DE;
        };
    };

    struct {
        union {
            struct {
                u_int8_t L;
                u_int8_t H;
            };
            u_int16_t HL;
        };
    };

    u_int16_t SP;
    u_int16_t PC;
};
