#include <sys/types.h>

#ifndef EMUMAN_DEFINITIONS_H
#define EMUMAN_DEFINITIONS_H

#endif //EMUMAN_DEFINITIONS_H


void * load_rom(const char* filename);
int decode(u_int16_t *pc, u_int8_t opcode);
