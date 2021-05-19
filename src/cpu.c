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
void set_up_registers(void) {
    REGISTERS.PC = 0;
}
void step_CPU(void) {
    REGISTERS.PC += decode(RAM.bootstrap[REGISTERS.PC]);
}


