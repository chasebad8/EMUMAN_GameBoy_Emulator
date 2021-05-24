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
void XOR_8(u_int8_t *dest, u_int8_t operand);
void ADC_8(u_int8_t *dest, u_int8_t operand);
void SBC_8(u_int8_t *dest, u_int8_t operand);
void ADD_16(u_int16_t *dest, u_int16_t operand);
void INC_8(u_int8_t *dest);
void INC_16(u_int16_t *dest);
void DEC_8(u_int8_t *dest);
void DEC_16(u_int16_t *dest);
void CP_8(u_int8_t *operand);
void NOP();
void RRCA(void);
void PUSH_16(u_int16_t operand);
void POP_16(u_int16_t *dest);

/* Memory Functions */
u_int8_t read_8(u_int16_t address);
u_int16_t read_16(u_int16_t address);
void write_8(u_int16_t address, u_int8_t value);
void write_u16(u_int16_t address, u_int16_t value);
