#include <sys/types.h>

#ifndef EMUMAN_DEFINITIONS_H
#define EMUMAN_DEFINITIONS_H

#endif //EMUMAN_DEFINITIONS_H

void * load_rom(const char* filename);
int decode(u_int8_t opcode);
void step_CPU(void);
void set_up_registers(void);

/* OP CODE Functions */
void LD_8(u_int8_t *dest, u_int8_t operand);
void LD_16(u_int16_t *dest, u_int16_t operand);
void ADD_8(u_int8_t *dest, u_int8_t operand);
void SUB_8(u_int8_t *dest, u_int8_t operand);
void AND_8(u_int8_t *dest, u_int8_t operand);
void OR_8(u_int8_t *dest, u_int8_t operand);
void ADC_8(u_int8_t *dest, u_int8_t operand);
void SBC_8(u_int8_t *dest, u_int8_t operand);
void ADD_16(u_int8_t *dest, u_int8_t operand);
void INC_8(u_int8_t *dest);
void INC_16(u_int16_t *dest);
void DEC_8(u_int8_t *dest);
void DEC_16(u_int16_t *dest);
void NOP();