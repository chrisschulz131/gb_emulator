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
        case 0x13: printf("INC DE"); break;
        case 0x14: printf("INC D"); break;
        case 0x15: printf("DEC D"); break;
        case 0x16: printf("LD D, 0x%02X", op[2]); opbytes = 2; break;
        case 0x17: printf("RLA"); break;
        case 0x18: printf("JR 0x%02X", op[2]); opbytes = 2; break;
        case 0x19: printf("ADD HL, DE"); break;
        case 0x1a: printf("LD A, (DE)"); break;
        case 0x1b: printf("DEC DE"); break;
        case 0x1c: printf("INC E"); break;
        case 0x1d: printf("DEC E"); break;
        case 0x1e: printf("LD E, 0x%02X", op[2]); opbytes = 2; break;
        case 0x1f: printf("RRA"); break;
        case 0x20: printf("JR NZ, 0x%02X", op[2]); break;
        case 0x21: printf("LD HL, 0x%04X", op[2] << 8 | op[1]); opbytes = 3; break;
        case 0x22: printf("LDI (HL), A"); break;
        case 0x23: printf("INC HL"); break;
        case 0x24: printf("INC H"); break;
        case 0x25: printf("DEC H"); break;
        case 0x26: printf("LD H, 0x%02X", op[2]); opbytes = 2; break;
        case 0x27: printf("DAA"); break;
        case 0x28: printf("JR Z, 0x%02X", op[2]); opbytes = 2; break;
        case 0x29: printf("ADD HL, HL"); break;
        case 0x2a: printf("LDI A, (HL)"); break;
        case 0x2b: printf("DEC HL"); break;
        case 0x2c: printf("INC L"); break;
        case 0x2d: printf("DEC L"); break;
        case 0x2e: printf("LD L, 0x%02X", op[2]); opbytes = 2; break;
        case 0x2f: printf("CPL"); break;
        case 0x30: printf("JR NC, 0x%02X", op[2]); opbytes = 2; break;
        case 0x31: printf("LD SP, 0x%04X", op[2] << 8 | op[1]); opbytes = 3; break;
        case 0x32: printf("LDD (HL), A"); break;
        case 0x33: printf("INC SP"); break;
        case 0x34: printf("INC (HL)"); break;
        case 0x35: printf("DEC (HL)"); break;
        case 0x36: printf("LD (HL), 0x%02X", op[2]); opbytes = 2; break;
        case 0x37: printf("SCF"); break;
        case 0x38: printf("JR C, 0x%02X", op[2]); opbytes = 2; break;
        case 0x39: printf("ADD HL, SP"); break;
        case 0x3a: printf("LDD A, (HL)"); break;
        case 0x3b: printf("DEC SP"); break;
        case 0x3c: printf("INC A"); break;
        case 0x3d: printf("DEC A"); break;
        case 0x3e: printf("LD A, 0x%02X", op[2]); opbyte = 2; break;
        case 0x3f: printf("CCF"); break;
        case 0x40: printf("LD B, B"); break;
        case 0x41: printf("LD B, C"); break;
        case 0x42: printf("LD B, D"); break;
        case 0x43: printf("LD B, E"); break;
        case 0x44: printf("LD B, H"); break;
        case 0x45: printf("LD B, L"); break;
        case 0x46: printf("LD B, (HL)"); break;
        case 0x47: printf("LD B, A"); break;
        case 0x48: printf("LD C, B"); break;
        case 0x49: printf("LD C, C"); break;
        case 0x4a: printf("LD C, D"); break;
        case 0x4b: printf("LD C, E"); break;
        case 0x4c: printf("LD C, H"); break;
        case 0x4d: printf("LD C, L"); break;
        case 0x4e: printf("LD C, (HL)"); break;
        case 0x4f: printf("LD C, A"); break;
        case 0x50: printf("LD D, B"); break;
        case 0x51: printf("LD D, C"); break;
        case 0x52: printf("LD D, D"); break;
        case 0x53: printf("LD D, E"); break;
        case 0x54: printf("LD D, H"); break;
        case 0x55: printf("LD D, L"); break;
        case 0x56: printf("LD D, (HL)"); break;
        case 0x57: printf("LD D, A"); break;
        case 0x58: printf("LD E, B"); break;
        case 0x59: printf("LD E, C"); break;
        case 0x5a: printf("LD E, D"); break;
        case 0x5b: printf("LD E, E"); break;
        case 0x5c: printf("LD E, H"); break;
        case 0x5d: printf("LD E, L"); break;
        case 0x5e: printf("LD E, (HL)"); break;
        case 0x5f: printf("LD E, A"); break;
        case 0x60: printf("LD H, B"); break;
        case 0x61: printf("LD H, C"); break;
        case 0x62: printf("LD H, D"); break;
        case 0x63: printf("LD H, E"); break;
        case 0x64: printf("LD H, H"); break;
        case 0x65: printf("LD H, L"); break;
        case 0x66: printf("LD H, (HL)"); break;
        case 0x67: printf("LD H, A"); break;
        case 0x68: printf("LD L, B"); break;
        case 0x69: printf("LD L, C"); break;
        case 0x6a: printf("LD L, D"); break;
        case 0x6b: printf("LD L, E"); break;
        case 0x6c: printf("LD L, H"); break;
        case 0x6d: printf("LD L, L"); break;
        case 0x6e: printf("LD L, (HL)"); break;
        case 0x6f: printf("LD L, A"); break;
        case 0x70: printf("LD (HL), B"); break;
        case 0x71: printf("LD (HL), C"); break;
        case 0x72: printf("LD (HL), D"); break;
        case 0x73: printf("LD (HL), E"); break;
        case 0x74: printf("LD (HL), H"); break;
        case 0x75: printf("LD (HL), L"); break;
        case 0x76: printf("HALT"); break;
        case 0x77: printf("LD (HL), A"); break;
        case 0x78: printf("LD A, B"); break;
        case 0x79: printf("LD A, C"); break;
        case 0x7a: printf("LD A, D"); break;
        case 0x7b: printf("LD A, E"); break;
        case 0x7c: printf("LD A, H"); break;
        case 0x7d: printf("LD A, L"); break;
        case 0x7e: printf("LD A, (HL)"); break;
        case 0x7f: printf("LD A, A"); break;
        case 0x80: printf("ADD A, B"); break;
        case 0x81: printf("ADD A, C"); break;
        case 0x82: printf("ADD A, D"); break;
        case 0x83: printf("ADD A, E"); break;
        case 0x84: printf("ADD A, H"); break;
        case 0x85: printf("ADD A, L"); break;
        case 0x86: printf("ADD A, (HL)"); break;
        case 0x87: printf("ADD A"); break;
        case 0x88: printf("ADC B"); break;
        case 0x89: printf("ADC C"); break;
        case 0x8a: printf("ADC D"); break;
        case 0x8b: printf("ADC E"); break;
        case 0x8c: printf("ADC H"); break;
        case 0x8d: printf("ADC L"); break;
        case 0x8e: printf("ADC (HL)"); break;
        case 0x8f: printf("ADC A"); break;
        case 0x90: printf("SUB B"); break;
        case 0x91: printf("SUB C"); break;
        case 0x92: printf("SUB D"); break;
        case 0x93: printf("SUB E"); break;
        case 0x94: printf("SUB H"); break;
        case 0x95: printf("SUB L"); break;
        case 0x96: printf("SUB (HL)"); break;
        case 0x97: printf("SUB A"); break;





            // we left shift and OR to concatenate the two bytes needed for the JP instruction.
        case 0xc3: printf("JP 0x%04X", op[2] << 8 | op[1]); opbytes = 3; break;
        default: printf("OP CODE NOT IMPLEMENTED!");
    }

    return opbytes;
}

