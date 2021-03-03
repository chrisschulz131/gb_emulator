//
// Created by cschulz on 3/2/21.
//

#ifndef GB_EMULATOR_CPU_H
#define GB_EMULATOR_CPU_H

FILE *debug_file;

int handleOP(unsigned char *opbuffer, int pc);

#endif //GB_EMULATOR_CPU_H
