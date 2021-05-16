#include <stdio.h>
#include <stdint.h>
/**
 *  This is where each individual opcode gets
 *  worked on.  The decoder will decide what
 *  the opcode is and then call a function that
 *  works on it
 */

int decode(uint16_t *pc, uint8_t opcode) {
    printf("Received opcode %02x\n", opcode);

    switch(opcode)
    {
        case 0x00:
            printf("NOP\n");
            *pc += 1;
            break;
        case 0x01:
            printf("LXI\n");
            *pc += 1;
            break;
        case 0x31:
            printf("JP!\n");
            *pc += 3;
            break;
        default:
            printf("Op Code Not Implemented!\n");
            *pc += 1;
    }
}