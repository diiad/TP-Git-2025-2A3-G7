/*
Game of Life practice
Sarah Schlegel
18.10.2021

output file
*/

#include <stdio.h>
#include <stdlib.h>
#include "cells.h"
#include "output.h"

#define GRID_SIZE 15

void printMenu (void) {
    printf("Select option:\n") ;
    printf("0 - Quit\n") ;
    printf("1 - Next round\n") ;
    printf("2 - Save most recent to file.\n") ;
    printf("Enter option: ") ;
}

void printGrid (Cell** grid) {
    for (size_t i = 0; i < GRID_SIZE; i++) {
        for (size_t j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid[i][j].symbol) ;
        }
        printf("\n") ;
    }
}
