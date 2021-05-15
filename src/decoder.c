#include <stdio.h>
#include <stdint.h>

int decode(uint16_t *pc, uint8_t opcode) {
    printf("Received opcode %04x\n", opcode);

    switch(opcode)
    {
        case 0x00:
            printf("NOP");
            break;
        case 0x01:
            printf("LXI");
    }
}