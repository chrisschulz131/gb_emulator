//
// Created by cschulz on 3/2/21.
//

#include <stdio.h>
#include "cpu.h"


int handleOP(unsigned char *opbuffer, int pc) {

    // get the operation from the file, at the location of the program counter.
    unsigned char *op = &opbuffer[pc];

    int opbytes = 1;
    // print the location of the program counter.
    printf("\n%04x ", pc);

    // switch on the operation the program counter is pointing too...
    // for now let's print what the operation is and increment the PC accordingly
    // then we will worry about implementing the actual instruction.

    switch(*op) {
        case 0x00: printf("NOP"); break;
        case 0x01: printf("LD BC"); opbytes = 3; break;
        case 0x02: printf("LD (BC), A"); break;
        case 0x03: printf("INC BC"); break;
        case 0x04: printf("INC B"); break;
        case 0x05: printf("DEC B"); break;
        case 0x06: printf("LD B"); opbytes = 2; break;
        case 0x07: printf("RLCA"); break;
        case 0x08: printf("LD (a16), SP"); opbytes = 3; break;
        case 0x09: printf("ADD HL, BC"); break;
        case 0x0a: printf("LD A, (BC)");
        case 0x0b: printf("DEC BC"); break;
        case 0x0c: printf("INC C"); break;
        case 0x0d: printf("DEC C"); break;
        case 0x0e: printf("LD C"); opbytes = 2; break;
        case 0x0f: printf("RRCA"); break;
        case 0x10: printf("STOP 0"); opbytes = 2; break;
        case 0x11: printf("LD DE 0x%04X", op[2] << 8 | op[1]); opbytes = 3; break;
        case 0x12: printf("LD (DE), A"); break;

        // we left shift and OR to concatenate the two bytes needed for the JP instruction.
        case 0xc3: printf("JP 0x%04X", op[2] << 8 | op[1]); opbytes = 3; break;
        default: printf("OP CODE NOT IMPLEMENTED!");
    }

    return opbytes;
}

