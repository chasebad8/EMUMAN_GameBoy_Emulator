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

#define IS_ZERO     (y) (y & Z_FLAG)
#define IS_NEGATIVE (y) (y & N_FLAG)
#define IS_SIGNED   (y) (y & S_FLAG)
#define IS_HCARRY   (y) (y & H_FLAG)
#define IS_CARRY    (y) (y & C_FLAG)
#define IS_OVERFLOW (y) (y & V_FLAG)

#define FLAG_SET(x, y)    (y |= x)
#define FLAG_IS_SET(x, y) (y & x)
#define FLAG_CLEAR(x, y)  (y &= ~x)

#define u8_2_u16(x, y) (x | (y << 8))

struct ram {
    u_int8_t *bootstrap;
    u_int8_t *SRAM; //stack ram
    u_int8_t *IO;
    u_int8_t *VRAM;
    u_int8_t *cartridge
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
