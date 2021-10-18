/*
Game of Life practice
Sarah Schlegel
18.10.2021

main file
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "cells.h"
#include "output.h"

#define GRID_SIZE 15

void gameOfLife (void) ;

int main (void) {
    gameOfLife() ;
    return 0;
}

Cell initCell (size_t s) {
    Cell cell ;
    if (s != 0 && s != 1) {
        s = 0 ;
    }

    cell.status = s;
    if (s == 0) {
        cell.symbol = 'O' ;
    } else {
        cell.symbol = 'X' ;
    }
    return cell ;
}

void freeCell (Cell* cell) {
    if (cell != NULL) {
        free(cell) ;
        cell = NULL ;
    }
}

void gameOfLife (void) {
    Cell** grid = initGrid();
    int option = 1 ;
    while (option) {
        printMenu() ;
        fflush(stdin) ;
        scanf("%d", &option) ;
        switch (option) {
            case 0:
                printf("Free and quit\n") ;
                freeGrid(grid) ;
                return ;
            case 1:
                printGrid(grid) ;
                printf("\n\n") ;
                printf("Next round\n") ;
                break ;
            case 2:
                printf("Write to file\n") ;
                break ;
        }
    }
    freeGrid(grid) ;
}

Cell** initGrid () {
    Cell** grid = malloc(sizeof(Cell*) * GRID_SIZE);

    if (grid == NULL) {
        return NULL ;
    }

    for (size_t i = 0; i < GRID_SIZE; ++i) {
        grid[i] = malloc(sizeof(Cell) * GRID_SIZE) ; //grid[i] / Cell*

        if (grid[i] == NULL) {
            for (short int j = i-1; j >= 0; --j) {
                free(grid[j]) ;
                grid[j] = NULL ;
            }
            free(grid) ;
            grid = NULL ;
            return NULL ;
        }
    }
    srand(time(NULL));
    //cells alloc
    for (size_t i = 0 ; i < GRID_SIZE ; ++i) {
        for (size_t j = 0 ; j < GRID_SIZE ; ++j) {
            grid[i][j] = initCell(rand() % 2) ;
        }
    }
    return grid ;
}

void freeGrid (Cell** grid) {
    for (size_t i = 0; i < GRID_SIZE; ++i) {
        if (grid[i] != NULL) {
            free(grid[i]) ;
            grid[i] = NULL ;
        }
    }
    free(grid) ;
    grid = NULL ;
}
