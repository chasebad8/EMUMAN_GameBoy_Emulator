#ifndef EMUMAN_STRUCTS_H
#define EMUMAN_STRUCTS_H

#endif //EMUMAN_STRUCTS_H


struct RAM {
    u_int8_t *bootstrap;
};

/**
 * registers contain information about all
 * of the current values in the registers
 */
struct REGISTERS {
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
