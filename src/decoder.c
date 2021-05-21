#include <stdio.h>
#include <stdint.h>
#include "../inc/emuman_logs.h"
#include "../inc/structs.h"
#include "../inc/definitions.h"

/*
 *  This is where each individual opcode gets
 *  worked on.  The decoder will decide what
 *  the opcode is and then call a function that
 *  works on it
 */

/**
 * @name decode
 * @param pc: The program counter
 * @param opcode: The received op code
 * @return a value based on if it was successful in
 *         decoding the code
 */

extern struct ram RAM;
extern struct registers REGISTERS;

int decode(u_int8_t opcode) {
    printf("Received opcode %02x\n", opcode);

    switch(opcode)
    {
        case 0x00:
            printf("NOP\n");
            break;
        case 0x01:
            printf("LD, BC, u16\n");
            break;
        case 0x02:
            printf("LD, [BC], A\n");
            break;
        case 0x03:
            printf("INC, BC\n");
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
        case 0x0B:
            printf("DEC, BC\n");
            break;
        case 0x0C:
            printf("INC, C\n");
            break;
        case 0x0D:
            printf("DEC C\n");
            break;
        case 0x0E:
            printf("LD, C, u8\n");
            break;
        case 0x0F:
            printf("RRAC\n");
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
        case 0x15:
            printf("DEC, D\n");
            break;
        case 0x16:
            printf("LD, D, u8\n");
            break;
        case 0x17:
            printf("RLA\n");
            break;
        case 0x18:
            printf("JR, i8\n");
            break;
        case 0x19:
            printf("CP, A, u8\n");
            break;
        case 0x1A:
            printf("LD, A, [DE]\n");
            break;
        case 0x1D:
            printf("DEC, E\n");
            break;
        case 0x1E:
            printf("LD, E, u8\n");
            break;
        case 0x1F:
            printf("RRA\n");
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
        case 0x24:
            printf("INC, H\n");
            break;
        case 0x26:
            printf("LD, H, u8\n");
            break;
        case 0x28:
            printf("JR Z, i8\n");
            break;
        case 0x2E:
            printf("LD, L, u8\n");
            break;
        case 0x2F:
            printf("CPL\n");
            break;
        case 0x31:
            printf("LD, SP, u16\n");
            LD_16(&REGISTERS.SP, RAM.bootstrap[REGISTERS.PC + 1]);
            break;
        case 0x32:
            printf("LD, HL-, A\n");
            break;
        case 0x33:
            printf("INC, SP\n");
            break;
        case 0x34:
            printf("INC, [HL]\n");
            break;
        case 0x3C:
            printf("INC, A\n");
            break;
        case 0x3D:
            printf("DEC, A\n");
            break;
        case 0x3E:
            printf("LD, A, u8\n");
            break;
        case 0x40:
            printf("LD, B, B\n");
            LD_8(&REGISTERS.B, REGISTERS.B);
            return 1;
        case 0x42:
            printf("LD, B, D\n");
            LD_8(&REGISTERS.B, REGISTERS.D);
            return 1;
        case 0x44:
            printf("LD, B, H\n");
            LD_8(&REGISTERS.B, REGISTERS.H);
            return 1;
        case 0x47:
            printf("LD, B, A\n");
            LD_8(&REGISTERS.B, REGISTERS.A);
            return 1;
        case 0x4F:
            printf("LD, C, A\n");
            LD_8(&REGISTERS.C, REGISTERS.A);
            return 1;
        case 0x50:
            printf("LD, D, B\n");
            LD_8(&REGISTERS.D, REGISTERS.B);
            return 1;
        case 0x57:
            printf("LD, D, A\n");
            LD_8(&REGISTERS.D, REGISTERS.A);
            return 1;
        case 0x62:
            printf("LD, H, D\n");
            LD_8(&REGISTERS.H, REGISTERS.D);
            return 1;
        case 0x63:
            printf("LD, H, E\n");
            LD_8(&REGISTERS.H, REGISTERS.E);
            return 1;
        case 0x64:
            printf("LD, H, H\n");
            LD_8(&REGISTERS.H, REGISTERS.H);
            return 1;
        case 0x66:
            printf("LD, H, [HL]\n");
            // u_int8_t offset = (REGISTERS.H<<8) | (REGISTERS.L);
            LD_8(&REGISTERS.H, RAM.bootstrap[REGISTERS.HL]);
            return 1;
        case 0x67:
            printf("LD, H, A\n");
            LD_8(&REGISTERS.H, REGISTERS.A);
            return 1;
        case 0x6E:
            printf("LD, L, [HL]\n");
            LD_8(&REGISTERS.L, RAM.bootstrap[REGISTERS.HL]);
            return 1;
        case 0x73:
            printf("LD, [HL], E\n");
            LD_8(&RAM.bootstrap[REGISTERS.HL], REGISTERS.E);
            return 1;
        case 0x77:
            printf("CP, A, u8\n");
            break;
        case 0x78:
            printf("LD, A, B\n");
            LD_8(&REGISTERS.A, REGISTERS.B);
            return 1;
        case 0x7B:
            printf("LD, A, E\n");
            LD_8(&REGISTERS.A, REGISTERS.E);
            return 1;
        case 0x7C:
            printf("LD, A, H\n");
            LD_8(&REGISTERS.A, REGISTERS.H);
            return 1;
        case 0x7D:
            printf("LD, A, L\n");
            LD_8(&REGISTERS.A, REGISTERS.L);
            return 1;
        case 0x80:
            printf("ADD, A, B\n");
            break;
        case 0x83:
            printf("ADD, A, E\n");
            break;
        case 0x86:
            printf("ADD, A, [HL]\n");
            break;
        case 0x87:
            printf("ADD, A, A\n");
            break;
        case 0x88:
            printf("ADC, A, B\n");
            break;
        case 0x89:
            printf("ADC, A, C\n");
            break;
        case 0x90:
            printf("SUB, A, B\n");
            break;
        case 0x91:
            printf("SUB, A, C\n");
            break;
        case 0x95:
            printf("SUB, A, L\n");
            break;
        case 0x96:
            printf("SUB, A, [HL]\n");
            break;
        case 0x99:
            printf("SBC, A, C\n");
            break;
        case 0x9F:
            printf("SBC, A, A\n");
            break;
        case 0xA5:
            printf("AND, A, L\n");
            break;
        case 0xA8:
            printf("XOR, A, B\n");
            break;
        case 0xAF:
            printf("XOR, A, A\n");
            break;
        case 0xB9:
            printf("CP, A, C\n");
            break;
        case 0xBB:
            printf("CP, A, E\n");
            break;
        case 0xBE:
            printf("CP, A, [HL]\n");
            break;
        case 0xC1:
            printf("POP, BC\n");
            break;
        case 0xC5:
            printf("PUSH, BC\n");
            break;
        case 0xC9:
            printf("RET\n");
            break;
        case 0xCB:
            printf("NEXT OP IS FROM OTHER TABLE!\n");
            break;
        case 0xCC:
            printf("CALL, Z, u16\n");
            break;
        case 0xCD:
            printf("CALL u16\n");
            break;
        case 0xCE:
            printf("ADC, A, u8\n");
            break;
        case 0xD2:
            printf("JP, NC, u16\n");
            break;
        case 0xD8:
            printf("RET C\n");
            break;
        case 0xD9:
            printf("RETI C\n");
            break;
        case 0xDC:
            printf("CALL, C, u16\n");
            break;
        case 0xDD:
            error_log("CPU", "UNDEFINED code was accessed (0xDD)");
            break;
        case 0xE0:
            printf("LD, [FF00 + u8], A\n");
            break;
        case 0xE2:
            printf("LD, [FF00 +C], A\n");
            break;
        case 0xE6:
            printf("AND, A, u8\n");
            break;
        case 0xEA:
            printf("LD, u16, A\n");
            break;
        case 0xEC:
            error_log("CPU", "UNDEFINED code was accessed (0xEC)");
            break;
        case 0xED:
            error_log("CPU", "UNDEFINED code was accessed (0xED)");
            break;
        case 0xF0:
            printf("LD, A, (FF00+u8)\n");
            break;
        case 0xF2:
            printf("LD, A,(FF00+C)\n");
            break;
        case 0xF3:
            printf("CP, A, u8\n");
            break;
        case 0xF5:
            printf("PUSH, AF\n");
            break;
        case 0xF7:
            printf("RST, 30h\n");
            break;
        case 0xF9:
            printf("LD, SP, HL\n");
            LD_16(&REGISTERS.SP, REGISTERS.HL);
            return 1;
        case 0xFA:
            printf("LD, A, u16\n");
            break;
        case 0xFB:
            printf("EI\n");
            break;
        case 0xFC:
            printf("UNDEFINED\n");
            error_log("CPU", "UNDEFINED code was accessed (0xFC)");
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

/*                           *
 * 8-bit Load / Store / Move *
 * ------------------------- */
void LD_8(u_int8_t *dest, u_int8_t operand) {
    *dest = operand;
}
/*                            *
 * 16-bit Load / Store / Move *
 * -------------------------- */
void LD_16(u_int16_t *dest, u_int16_t operand) {
    *dest = operand;
}
/*                         *
 * 8-bit Arithmetic Logic  *
 * ----------------------- */
void ADD_8(u_int8_t *dest, u_int8_t operand)
{
    u_int16_t res = *dest + operand;
    *dest = (u_int8_t)(res & 0xFF);

    //Check if a carry has occurred
    if(res & 0xFF00 > 1) {
        FLAG_SET(C_FLAG, REGISTERS.F);
    } else {
        FLAG_CLEAR(C_FLAG, REGISTERS.F);
    }

    //Check if the value of the addition is 0 (shouldn't be)
    if(*dest == 0){
        FLAG_SET(Z_FLAG, REGISTERS.F);
    } else {
        FLAG_CLEAR(Z_FLAG, REGISTERS.F);
    }

    //Check if a half carry occurred
    if(((*dest & 0x0F) + (operand & 0x0F)) > 0x0F) {
        FLAG_SET(H_FLAG, REGISTERS.F);
    } else {
        FLAG_CLEAR(H_FLAG, REGISTERS.F);
    }

    //We know that there can't be a negative value (unsigned)
    FLAG_CLEAR(N_FLAG, REGISTERS.F);
}

void SUB_8(u_int8_t *dest, u_int8_t operand)
{
    //N Flag will always be set
    FLAG_SET(N_FLAG, REGISTERS.F);

    //If value subtracted from A is larger, we get a carry
    if(operand > *dest) {
        FLAG_SET(C_FLAG, REGISTERS.F);
    } else {
        FLAG_CLEAR(C_FLAG, REGISTERS.F);
    }

    //Check if we need to set Z flag
    if(*dest - operand == 0) {
        FLAG_SET(Z_FLAG, REGISTERS.F);
    } else {
        FLAG_CLEAR(Z_FLAG, REGISTERS.F);
    }
    *dest = *dest - operand;
}

void AND_8(u_int8_t *dest, u_int8_t operand)
{
    *dest = *dest & operand;

    if(*dest == 0) {
        FLAG_SET(Z_FLAG, REGISTERS.F);
    } else {
        FLAG_CLEAR(Z_FLAG, REGISTERS.F);
    }
    FLAG_CLEAR(N_FLAG, REGISTERS.F);
    FLAG_CLEAR(C_FLAG, REGISTERS.F);
    FLAG_SET(H_FLAG, REGISTERS.F);
}

void OR_8(u_int8_t *dest, u_int8_t operand)
{
    *dest = *dest | operand;

    if(*dest == 0) {
        FLAG_SET(Z_FLAG, REGISTERS.F);
    } else {
        FLAG_CLEAR(Z_FLAG, REGISTERS.F);
    }
    FLAG_CLEAR(N_FLAG, REGISTERS.F);
    FLAG_CLEAR(H_FLAG, REGISTERS.F);
    FLAG_CLEAR(C_FLAG, REGISTERS.F);
}

void ADC_8(u_int8_t *dest, u_int8_t operand)
{
    if(FLAG_IS_SET(C_FLAG, REGISTERS.F) == 1) {
        *dest = *dest + 1;
    }
    u_int16_t res = *dest + operand;

    //Check if the value of the addition is 0 (shouldn't be)
    if(*dest == 0){
        FLAG_SET(Z_FLAG, REGISTERS.F);
    } else {
        FLAG_CLEAR(Z_FLAG, REGISTERS.F);
    }

    //Check if a half carry occurred
    if(((*dest & 0x0F) + (operand & 0x0F)) > 0x0F) {
        FLAG_SET(H_FLAG, REGISTERS.F);
    } else {
        FLAG_CLEAR(H_FLAG, REGISTERS.F);
    }

    //We know that there can't be a negative value (unsigned)
    FLAG_SET(N_FLAG, REGISTERS.F);

    *dest = (u_int8_t)(res & 0xFF);
}

void SBC_8(u_int8_t *dest, u_int8_t operand)
{
    if(FLAG_IS_SET(C_FLAG, REGISTERS.F) == 1) {
        *dest = *dest + 1;
    }

    //If value subtracted from A is larger, we get a carry
    if(operand > *dest) {
        FLAG_SET(C_FLAG, REGISTERS.F);
    } else {
        FLAG_CLEAR(C_FLAG, REGISTERS.F);
    }

    if(*dest - operand == 0) {
        FLAG_SET(Z_FLAG, REGISTERS.F);
    } else {
        FLAG_CLEAR(Z_FLAG, REGISTERS.F);
    }

    //Check if a half carry occurred
    if(((*dest & 0x0F) > (operand & 0x0F))) {
        FLAG_SET(H_FLAG, REGISTERS.F);
    } else {
        FLAG_CLEAR(H_FLAG, REGISTERS.F);
    }

    *dest = *dest - operand;
}

/*                         *
 * 16-bit Arithmetic Logic *
 * ------------------------*/
void ADD_16(u_int8_t *dest, u_int8_t operand)
{
    u_int32_t result = *dest + operand;
    *dest = (u_int16_t)(result & 0xFF);
}
/*        *
 * Branch *
 * -------*/

/*        *
 * Other *
 * -------*/