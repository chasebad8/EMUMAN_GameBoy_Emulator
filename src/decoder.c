#include <stdio.h>
#include <stdint.h>
#include "../inc/emuman_logs.h"

/**
 *  This is where each individual opcode gets
 *  worked on.  The decoder will decide what
 *  the opcode is and then call a function that
 *  works on it
 */

int decode(uint16_t *pc, uint8_t opcode) {
    printf("Received opcode %02x\n", opcode);
    *pc += 1;

    switch(opcode)
    {
        case 0x00:
            printf("NOP\n");
            break;
        case 0x01:
            printf("LD, BC, u16\n");
            break;
        case 0x04:
            printf("INC, B\n");
            break;
        case 0x05:
            printf("DEC, B\n");
            break;
        case 0x06:
            printf("LD, B, u8\n");
            break;
        case 0x08:
            printf("LD, [u16], SP\n");
            break;
        case 0x0C:
            printf("INC, C\n");
            break;
        case 0x0E:
            printf("LD, C, u8\n");
            break;
        case 0x10:
            printf("STOP\n");
            break;
        case 0x11:
            printf("LD, DE, u16\n");
            break;
        case 0x13:
            printf("INC, DE\n");
            break;
        case 0x19:
            printf("CP, A, u8\n");
            break;
        case 0x1A:
            printf("LD, A, [DE]\n");
            break;
        case 0x20:
            printf("LD, SP, u16\n");
            break;
        case 0x21:
            printf("LD, HL, u16\n");
            break;
        case 0x22:
            printf("LD, [HL+], A\n");
            break;
        case 0x23:
            printf("INC HL\n");
            break;
        case 0x26:
            printf("LD, H, u8\n");
            break;
        case 0x31:
            printf("LD, SP, u16\n");
            break;
        case 0x32:
            printf("LD, HL-, A\n");
            break;
        case 0x34:
            printf("INC, [HL]\n");
            break;
        case 0x3E:
            printf("LD, A, u8\n");
            break;
        case 0x47:
            printf("LD, B, A\n");
            break;
        case 0x77:
            printf("CP, A, u8\n");
            break;
        case 0x7B:
            printf("LD, A, E\n");
            break;
        case 0x7C:
            printf("LD, A, H\n");
            break;
        case 0x80:
            printf("ADD, A, B\n");
            break;
        case 0x95:
            printf("SUB, A, L\n");
            break;
        case 0x96:
            printf("SUB, A, [HL]\n");
            break;
        case 0x9F:
            printf("SBC, A, A\n");
            break;
        case 0xAF:
            printf("CP, A, u8\n");
            break;
        case 0xCB:
            printf("PREFIX CB\n");
            break;
        case 0xCD:
            printf("CALL u16\n");
            break;
        case 0xD8:
            printf("RET C\n");
            break;
        case 0xE0:
            printf("LD, [FF00 + u8], A\n");
            break;
        case 0xE2:
            printf("LD, [FF00 +C], A\n");
            break;
        case 0xF3:
            printf("CP, A, u8\n");
            break;
        case 0xF9:
            printf("LD, SP, HL\n");
            break;
        case 0xFB:
            printf("EI\n");
            break;
        case 0xFC:
            printf("UNDEFINED\n");
            error_log("CPU", "UNDEFINED code was accessed");
            break;
        case 0xFE:
            printf("CP, A, u8\n");
            break;
        case 0xFF:
            printf("RST 0x38\n");
            break;
        default:
            error_log("CPU", "OP CODE not implemented!");
            printf("Op Code Not Implemented!\n");
            return -1;

    }
}