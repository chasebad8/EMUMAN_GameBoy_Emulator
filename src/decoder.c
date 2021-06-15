#include <stdio.h>
#include "../inc/emuman_logs.h"
#include "../inc/structs.h"
#include "../inc/definitions.h"

/*
 *  This is where each individual opcode gets
 *  worked on.  The decoder will decide what
 *  the opcode is and then call a function that
 *  works on it
 */

extern struct ram RAM;
extern struct registers REGISTERS;

/**
 * @name decode
 * @param pc: The program counter
 * @param opcode: The received op code
 * @return a value based on if it was successful in
 *         decoding the code relative to PC increment
 */
int decode(u_int8_t opcode) {
    printf("Received opcode %02x\n", opcode);

    switch(opcode)
    {
        case 0x00:
            printf("NOP\n");
            return 1;
        case 0x01:
            printf("LD, BC, u16\n");
            LD_16(&REGISTERS.BC, u8_2_u16(read_8(REGISTERS.PC + 1),read_8(REGISTERS.PC + 2)));
            return 3;
        case 0x02:
            printf("LD, [BC], A\n");
            LD_8_RAM(REGISTERS.BC, REGISTERS.A);
            return 1;
        case 0x03:
            printf("INC, BC\n");
            INC_16(&REGISTERS.BC);
            return 1;
        case 0x04:
            printf("INC, B\n");
            INC_8(&REGISTERS.B);
            return 1;
        case 0x05:
            printf("DEC, B\n");
            DEC_8(&REGISTERS.B);
            return 1;
        case 0x06:
            printf("LD, B, u8\n");
            LD_8(&REGISTERS.B, read_8(REGISTERS.PC + 1));
            return 2;
        case 0x08:
            printf("LD, [u16], SP\n");
            LD_16_RAM(read_16(u8_2_u16(REGISTERS.PC + 1, REGISTERS.PC + 2)), REGISTERS.SP);
            return 3;
        case 0x0B:
            printf("DEC, BC\n");
            DEC_16(&REGISTERS.BC);
            return 1;
        case 0x0C:
            printf("INC, C\n");
            INC_8(&REGISTERS.C);
            return 1;
        case 0x0D:
            printf("DEC C\n");
            DEC_8(&REGISTERS.C);
            return 1;
        case 0x0E:
            printf("LD, C, u8\n");
            LD_8(&REGISTERS.C, read_8(REGISTERS.PC + 1));
            return 2;
        case 0x0F:
            printf("RRAC\n");
            RRCA();
            return 1;
        case 0x10:
            printf("STOP\n");
            error_log("CPU", "INSTRUCTION NOT IMPLEMENTED");
            return 1;
        case 0x11:
            printf("LD, DE, u16\n");
            LD_16(&REGISTERS.DE, read_16(REGISTERS.PC + 1));
            return 3;
        case 0x13:
            printf("INC, DE\n");
            INC_16(&REGISTERS.BC);
            return 1;
        case 0x15:
            printf("DEC, D\n");
            DEC_8(&REGISTERS.D);
            return 1;
        case 0x16:
            printf("LD, D, u8\n");
            LD_8(&REGISTERS.D, read_8(REGISTERS.PC + 1));
            return 2;
        case 0x17:
            printf("RLA\n");
            error_log("CPU", "INSTRUCTION NOT IMPLEMENTED");
            exit(-1);
        case 0x18:
            printf("JR, i8\n");
            error_log("CPU", "INSTRUCTION NOT IMPLEMENTED");
            exit(-1);
        case 0x19:
            printf("ADD, HL, DE\n");
            ADD_16(&REGISTERS.HL, REGISTERS.DE);
            return 1;
        case 0x1A:
            printf("LD, A, [DE]\n");
            LD_8(&REGISTERS.A, read_8(REGISTERS.DE));
            return 1;
        case 0x1D:
            printf("DEC, E\n");
            DEC_8(&REGISTERS.E);
            return 1;
        case 0x1E:
            printf("LD, E, u8\n");
            LD_8(&REGISTERS.E, read_8(REGISTERS.PC + 1));
            return 2;
        case 0x1F:
            printf("RRA\n");
            error_log("CPU", "INSTRUCTION NOT IMPLEMENTED");
            exit(-1);
        case 0x20:
            printf("LD, SP, u16\n");
            LD_16(&REGISTERS.SP, read_16(REGISTERS.PC + 1));
            return 3;
        case 0x21:
            printf("LD, HL, u16\n");
            LD_16(&REGISTERS.HL, read_16(REGISTERS.PC + 1));
            return 3;
        case 0x22:
            printf("LD, [HL+], A\n");
            REGISTERS.HL = REGISTERS.HL + 1;
            LD_16_RAM(REGISTERS.HL, REGISTERS.A);
            return 1;
        case 0x23:
            printf("INC HL\n");
            INC_16(&REGISTERS.HL);
            return 1;
        case 0x24:
            printf("INC, H\n");
            INC_8(&REGISTERS.H);
            return 1;
        case 0x26:
            printf("LD, H, u8\n");
            LD_8(&REGISTERS.H, read_8(REGISTERS.PC + 1));
            return 2;
        case 0x28:
            printf("JR Z, i8\n");
            error_log("CPU", "INSTRUCTION NOT IMPLEMENTED");
            exit(-1);
        case 0x2E:
            printf("LD, L, u8\n");
            LD_8(&REGISTERS.L, read_8(REGISTERS.PC + 1));
            return 2;
        case 0x2F:
            printf("CPL\n");
            error_log("CPU", "INSTRUCTION NOT IMPLEMENTED");
            exit(-1);
        case 0x31:
            printf("LD, SP, u16\n");
            LD_16(&REGISTERS.SP, read_8(REGISTERS.PC + 1));
            return 3;
        case 0x32:
            printf("LD, HL-, A\n");
            LD_16(&REGISTERS.HL, REGISTERS.A);
            REGISTERS.HL = REGISTERS.HL - 1;
            return 1;
        case 0x33:
            printf("INC, SP\n");
            INC_16(&REGISTERS.SP);
            return 1;
        case 0x34:
            printf("INC, [HL]\n");
            write_u16(REGISTERS.HL, read_8(REGISTERS.HL) + 1);
            return 1;
        case 0x3C:
            printf("INC, A\n");
            INC_8(&REGISTERS.A);
            return 1;
        case 0x3D:
            printf("DEC, A\n");
            DEC_8(&REGISTERS.A);
            return 1;
        case 0x3E:
            printf("LD, A, u8\n");
            LD_8(&REGISTERS.A, read_8(REGISTERS.PC + 1));
            return 2;
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
            LD_8(&REGISTERS.H, read_8(REGISTERS.HL));
            return 1;
        case 0x67:
            printf("LD, H, A\n");
            LD_8(&REGISTERS.H, REGISTERS.A);
            return 1;
        case 0x6E:
            printf("LD, L, [HL]\n");
            LD_8(&REGISTERS.L, read_8(REGISTERS.HL));
            return 1;
        case 0x73:
            printf("LD, [HL], E\n");
            LD_8(&RAM.bootstrap[REGISTERS.HL], REGISTERS.E);
            return 1;
        case 0x77:
            printf("LD [HL], A\n");
            LD_8_RAM(read_16(REGISTERS.HL), REGISTERS.A);
            return 1;
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
            ADD_8(&REGISTERS.A, REGISTERS.B);
            return 1;
        case 0x83:
            printf("ADD, A, E\n");
            ADD_8(&REGISTERS.A, REGISTERS.E);
            return 1;
        case 0x86:
            printf("ADD, A, [HL]\n");
            ADD_8(&REGISTERS.A, read_8(REGISTERS.HL));
            return 1;
        case 0x87:
            printf("ADD, A, A\n");
            ADD_8(&REGISTERS.A, REGISTERS.A);
            return 1;
        case 0x88:
            printf("ADC, A, B\n");
            ADC_8(&REGISTERS.A, REGISTERS.B);
            return 1;
        case 0x89:
            printf("ADC, A, C\n");
            ADC_8(&REGISTERS.A, REGISTERS.C);
            return 1;
        case 0x90:
            printf("SUB, A, B\n");
            SUB_8(&REGISTERS.A, REGISTERS.B);
            return 1;
        case 0x91:
            printf("SUB, A, C\n");
            SUB_8(&REGISTERS.A, REGISTERS.C);
            return 1;
        case 0x95:
            printf("SUB, A, L\n");
            SUB_8(&REGISTERS.A, REGISTERS.L);
            return 1;
        case 0x96:
            printf("SUB, A, [HL]\n");
            SUB_8(&REGISTERS.A, read_8(REGISTERS.HL));
            return 1;
        case 0x99:
            printf("SBC, A, C\n");
            SBC_8(&REGISTERS.A, REGISTERS.C);
            return 1;
        case 0x9F:
            printf("SBC, A, A\n");
            SBC_8(&REGISTERS.A, REGISTERS.A);
            return 1;
        case 0xA5:
            printf("AND, A, L\n");
            AND_8(&REGISTERS.A, REGISTERS.L);
            return 1;
        case 0xA8:
            printf("XOR, A, B\n");
            XOR_8(&REGISTERS.A, REGISTERS.B);
            return 1;
        case 0xAF:
            printf("XOR, A, A\n");
            XOR_8(&REGISTERS.A, REGISTERS.A);
            return 1;
        case 0xB9:
            printf("CP, A, C\n");
            CP_8(&REGISTERS.C);
            return 1;
        case 0xBB:
            printf("CP, A, E\n");
            CP_8(&REGISTERS.E);
            return 1;
        case 0xBE:
            printf("CP, A, [HL]\n");
            CP_8(&RAM.bootstrap[REGISTERS.HL]);
            return 1;
        case 0xC1:
            printf("POP, BC\n");
            POP_16(&REGISTERS.BC);
            return 1;
        case 0xC5:
            printf("PUSH, BC\n");
            PUSH_16(REGISTERS.BC);
            return 1;
        case 0xC9:
            printf("RET\n");
            error_log("CPU", "INSTRUCTION NOT IMPLEMENTED");
            exit(-1);
        case 0xCB:
            printf("NEXT OP IS FROM OTHER TABLE!\n");
            return (CB_decode(read_8(REGISTERS.PC + 1)));
        case 0xCC:
            printf("CALL, Z, u16\n");
            error_log("CPU", "INSTRUCTION NOT IMPLEMENTED");
            exit(-1);
        case 0xCD:
            printf("CALL u16\n");
            PUSH_16(read_16(REGISTERS.PC + 1));
            return 3;
        case 0xCE:
            printf("ADC, A, u8\n");
            ADC_8(&REGISTERS.A, read_8(REGISTERS.PC));
            return 2;
        case 0xD2:
            printf("JP, NC, u16\n");
            error_log("CPU", "INSTRUCTION NOT IMPLEMENTED");
            exit(-1);
        case 0xD8:
            printf("RET C\n");
            RET_C();
            return 1;
        case 0xD9:
            printf("RETI C\n");
            error_log("CPU", "INSTRUCTION NOT IMPLEMENTED");
            exit(-1);
        case 0xDC:
            printf("CALL, C, u16\n");
            error_log("CPU", "INSTRUCTION NOT IMPLEMENTED");
            exit(-1);
        case 0xDD:
            error_log("CPU", "UNDEFINED code was accessed (0xDD)");
            exit(-1);
        case 0xE0:
            printf("LD, [FF00 + u8], A\n");
            LD_8(&RAM.bootstrap[(0xFF00 + read_8(REGISTERS.PC + 1))], REGISTERS.A);
            return 2;
        case 0xE2:
            printf("LD, [FF00 + C], A\n");
            LD_8(&RAM.bootstrap[(0xFF00 + REGISTERS.C)], REGISTERS.A);
            return 1;
        case 0xE6:
            printf("AND, A, u8\n");
            AND_8(&REGISTERS.A, read_8(REGISTERS.PC + 1));
            return 2;
        case 0xEA:
            printf("LD, [u16], A\n");
            LD_16_RAM(read_16(u8_2_u16(REGISTERS.PC + 1, REGISTERS.PC + 2)), REGISTERS.A);
            return 3;
        case 0xEC:
            error_log("CPU", "UNDEFINED code was accessed (0xEC)");
            exit(-1);
        case 0xED:
            error_log("CPU", "UNDEFINED code was accessed (0xED)");
            exit(-1);
        case 0xF0:
            printf("LD, A, (FF00+u8)\n");
            LD_8(&REGISTERS.A, (0xFF00 + read_8(REGISTERS.PC + 1)));
            return 2;
        case 0xF2:
            printf("LD, A,(FF00+C)\n");
            LD_8(&REGISTERS.A, (0xFF00 + REGISTERS.C));
            return 2;
        case 0xF3:
            printf("DI\n");
            error_log("CPU", "INSTRUCTION NOT IMPLEMENTED");
            exit(-1);
        case 0xF5:
            printf("PUSH, AF\n");
            PUSH_16(REGISTERS.AF);
            return 1;
        case 0xF7:
            printf("RST, 30h\n");
            error_log("CPU", "INSTRUCTION NOT IMPLEMENTED");
            exit(-1);
        case 0xF9:
            printf("LD, SP, HL\n");
            LD_16(&REGISTERS.SP, REGISTERS.HL);
            return 1;
        case 0xFA:
            printf("LD, A, [u16]\n");
            LD_8(&REGISTERS.A, read_16(REGISTERS.PC + 1));
            return 3;
        case 0xFB:
            printf("EI\n");
            error_log("CPU", "INSTRUCTION NOT IMPLEMENTED");
            exit(-1);
        case 0xFC:
            printf("UNDEFINED\n");
            error_log("CPU", "UNDEFINED code was accessed (0xFC)");
            exit(-1);
        case 0xFE:
            printf("CP, A, u8\n");
            CP_8(&RAM.bootstrap[REGISTERS.PC + 1]);
            return 2;
        case 0xFF:
            printf("RST 0x38\n");
            error_log("CPU", "INSTRUCTION NOT IMPLEMENTED");
            exit(-1);
        default:
            error_log("CPU", "OP CODE not implemented!");
            printf("Op Code Not Implemented!\n");
            exit(-1);

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

void LD_8_RAM(u_int16_t dest, u_int8_t operand)
{
    write_8(dest, operand);
}

void LD_16_RAM(u_int16_t dest, u_int16_t operand)
{
    write_u16(dest, operand);
}
/*                         *
 * 8-bit Arithmetic Logic  *
 * ----------------------- */
void ADD_8(u_int8_t *dest, u_int8_t operand)
{
    u_int16_t res = *dest + operand;
    *dest = (u_int8_t)(res & 0xFF);

    //Check if a carry has occurred
    if((res & 0xFF00) > 1) {
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

void XOR_8(u_int8_t *dest, u_int8_t operand)
{
    *dest = *dest ^ operand;

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
 * 8-bit Compare           *
 * ------------------------*/
void CP_8(u_int8_t *operand)
{
    if (*operand > REGISTERS.A){
        FLAG_SET(S_FLAG, REGISTERS.F);
    } else {
        FLAG_CLEAR(S_FLAG, REGISTERS.F);
    }

    if (*operand == REGISTERS.A){
        FLAG_SET(Z_FLAG, REGISTERS.F);
    } else {
        FLAG_CLEAR(Z_FLAG, REGISTERS.F);
    }

    if ((((REGISTERS.A&0x0F) - (*operand&0x0F)) & 0x10) == 0x10){
        FLAG_SET(H_FLAG, REGISTERS.F);
    } else {
        FLAG_CLEAR(H_FLAG, REGISTERS.F);
    }

    if (REGISTERS.A < *operand){
        FLAG_SET(C_FLAG, REGISTERS.F);
    } else {
        FLAG_CLEAR(C_FLAG, REGISTERS.F);
    }

    FLAG_CLEAR(V_FLAG, REGISTERS.F);
    FLAG_SET(N_FLAG, REGISTERS.F);
}

void CPL_8()
{
    FLAG_SET(H_FLAG, REGISTERS.F);
    FLAG_SET(N_FLAG, REGISTERS.F);
    REGISTERS.A = ~(REGISTERS.A);
}
/*                         *
 * 16-bit Arithmetic Logic *
 * ------------------------*/
void ADD_16(u_int16_t *dest, u_int16_t operand)
{
    u_int32_t result = *dest + operand;
    *dest = (u_int16_t)(result & 0xFF);
}

void RET_C(void)
{
    if(FLAG_IS_SET(C_FLAG, REGISTERS.F))
    {
        POP_16(&REGISTERS.PC);
    }
}
/*                         *
 * 8-bit Increment         *
 * ------------------------*/
void INC_8(u_int8_t *dest)
{
    if (*dest == 0x7F){
        FLAG_SET(V_FLAG, REGISTERS.F);
    } else {
        FLAG_CLEAR(V_FLAG, REGISTERS.F);
    }
    if ((((*dest&0x0F) + (1&0x0F)) & 0x10) == 0x10){
        FLAG_SET(H_FLAG, REGISTERS.F);
    } else {
        FLAG_CLEAR(H_FLAG, REGISTERS.F);
    }

    *dest = *dest + 1;

    FLAG_CLEAR(Z_FLAG, REGISTERS.F);
    FLAG_CLEAR(S_FLAG, REGISTERS.F);
    FLAG_CLEAR(N_FLAG, REGISTERS.F);
}

/*                         *
 * 16-bit Increment        *
 * Used to implement INC ss*
 * No conditions affected  *
 * ------------------------*/
void INC_16(u_int16_t *dest)
{
    *dest = *dest + 1;
}

/*                         *
 * 8-bit Decrement         *
 * ------------------------*/
void DEC_8(u_int8_t *dest)
{
    if (*dest == 0x00){
        FLAG_SET(S_FLAG, REGISTERS.F);
    } else {
        FLAG_CLEAR(S_FLAG, REGISTERS.F);
    }

    if (*dest == 0x80){
        FLAG_SET(V_FLAG, REGISTERS.F);
    } else {
        FLAG_CLEAR(V_FLAG, REGISTERS.F);
    }

    if ((((*dest&0x0F) - (1&0x0F)) & 0x10) == 0x10){
        FLAG_SET(H_FLAG, REGISTERS.F);
    } else {
        FLAG_CLEAR(H_FLAG, REGISTERS.F);
    }

    FLAG_SET(N_FLAG, REGISTERS.F);

    *dest = *dest - 1;

    if (*dest == 0x00){
        FLAG_SET(Z_FLAG, REGISTERS.F);
    } else {
        FLAG_CLEAR(Z_FLAG, REGISTERS.F);
    }

}

/*                         *
 * 16-bit Decrement        *
 * Used to implement DEC ss*
 * No conditions affected  *
 * ------------------------*/
void DEC_16(u_int16_t *dest)
{
    *dest = *dest - 1;
}


/*        *
 * Branch *
 * -------*/
void STOP()
{
    //exit
}

/*        *
 * Stack  *
 * -------*/

void PUSH_16(u_int16_t operand)
{
    REGISTERS.SP -= 2;
    write_u16(REGISTERS.SP, operand);
}

void POP_16(u_int16_t *dest)
{
    *dest = read_16(REGISTERS.SP);
    REGISTERS.SP += 2;
}

/*        *
 * Other  *
 * -------*/

/**
 * @name RRCA
 *
 * The contents of the Accumulator (Register A)
 * are rotated right 1 bit position. Bit 0 is copied
 * to the Carry flag and also to bit 7.
 * Bit 0 is the least-significant bit.
 *
 */
void RRCA(void)
{
    if((REGISTERS.A & 0x01) == 1) {
        FLAG_SET(C_FLAG, REGISTERS.F);
    }  else {
        FLAG_CLEAR(C_FLAG, REGISTERS.F);
    }

    REGISTERS.A >> 1;
    if((REGISTERS.A & 0x01 ) == 1) {
        REGISTERS.A = REGISTERS.A | 0x80; //1000 0000
    }

    FLAG_CLEAR(N_FLAG, REGISTERS.F);
    FLAG_CLEAR(Z_FLAG, REGISTERS.F);
    FLAG_CLEAR(H_FLAG, REGISTERS.F);
}

int CB_decode(u_int8_t opcode)
{
    switch(opcode)
    {
        case(0x7C):
            printf("BIT, H, 1 << 7\n");
            BIT_8(&REGISTERS.H, 1 << 7);
            return 1;
    }
}

/*
 * CB commands :(
 */
void BIT_8(u_int8_t *dest, u_int8_t bit)
{
    if(*dest & bit == 0){
        FLAG_SET(Z_FLAG, REGISTERS.F);
    } else {
        FLAG_CLEAR(Z_FLAG, REGISTERS.F);
    }

    FLAG_CLEAR(N_FLAG, REGISTERS.F);
    FLAG_SET(H_FLAG, REGISTERS.F);
}