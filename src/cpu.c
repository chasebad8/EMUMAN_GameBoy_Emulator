#include "../inc/emuman_logs.h"
#include "../inc/definitions.h"
#include "../inc/structs.h"

extern struct ram RAM;
extern struct registers REGISTERS;

/*
 * This emulates the GameBoy CPU.  This means
 * that we must keep track of all of the internal
 * registers as well as decode OPCODES.
 */
void set_up_registers(void)
{
    REGISTERS.PC = 0;
}

void print_reg_vals(void)
{
    printf("REG F:  %02X\n",   REGISTERS.F);
    printf("REG A:  %02X\n",   REGISTERS.A);
    printf("REG AF: %02X\n\n", REGISTERS.AF);
    printf("REG C:  %02X\n",   REGISTERS.C);
    printf("REG B:  %02X\n",   REGISTERS.B);
    printf("REG BC: %02X\n\n", REGISTERS.BC);
    printf("REG E:  %02X\n",   REGISTERS.E);
    printf("REG D:  %02X\n",   REGISTERS.D);
    printf("REG DE: %02X\n\n", REGISTERS.DE);
    printf("REG L:  %02X\n",   REGISTERS.L);
    printf("REG H:  %02X\n",   REGISTERS.H);
    printf("REG HL: %02X\n\n", REGISTERS.HL);
    printf("REG SP: %02X\n",   REGISTERS.SP);
    printf("REG PC: %02X\n",   REGISTERS.PC);
}
void step_CPU(void) {
    REGISTERS.PC += decode(read_8(REGISTERS.PC));
}


