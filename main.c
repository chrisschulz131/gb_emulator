//
// Created by cschulz on 3/1/21.
//

#include <stdio.h>
#include <SDL2/SDL.h>
#include "cpu.h"


int main(int argc, char *argv[]) {

    // in the future make a gui.c class to handle set up of the game window.
//    SDL_Window* win = SDL_CreateWindow("GameBoyEmmy",
//                                       SDL_WINDOWPOS_CENTERED,
//                                       SDL_WINDOWPOS_CENTERED,
//                                       1000, 1000, 0);
//
//
//    while(1)
//        ;

    // read in the rom
    if(argc != 2) {
        printf("\nERROR: Incorrect Number of Arguments. Please Provide a ROM file.\n");
        exit(EXIT_FAILURE);
    }

    FILE *fp;

    fp = fopen(argv[1], "r");
    if(!fp) {
        perror("Failed to open ROM: ");
        exit(EXIT_FAILURE);
    } else {
        printf("ROM was successfully opened...\n");
    }


    // credits to emulator101 - read the file into memory and close it.
    fseek(fp, 0L, SEEK_END);
    // get size of file
    int fsize = ftell(fp);
    // set location of file pointer back at beginning of the file.
    fseek(fp, 0L, SEEK_SET);

    // GameBoy games begin at memory location 0100
    unsigned char *buffer = malloc(fsize);
    fread(buffer, fsize, 1, fp);
    fclose(fp);

    int pc = 0x0100;
    while(pc < fsize) {
        pc += handleOP(buffer, pc);
    }

    free(buffer);
    return 0;

}

