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


void gameOfLife (void) {
    Cell** grid = initGrid();

    //vérif grid == NULL

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

/*

X X X O O O X O X X O X X X O
O X X X O X X O X X X X X X O
X O X O X O X O X O O O O O X
X O X O X X X O O O X O O O X
O X O O O O O O O O X O X X O
O O O X X X X O O X X O X O O
X O O X O O O O X X X X X O O
O X O O X O O O O X O X O X X
O X X O X O O X O O X O O X O
X X X X O O X O O O O O X X X
X O O O O O X X O O O O X O X
O O X O O O O O X X X X O O X
X O X O O O X O X X X X X O O
O X O X O X O X O O X X O X O
X O X O O O O X O X O X O X X

    Cell**
    [
        15x Cell*
        [
            15x Cell
        ]
    ]
*/


Cell** initGrid () {
    /*
    char => 1 octet
    short (int) => 2 octets
    int => 4 octets
    long (int) => 4/8 octets
    long long (int) => 16 octets
    float => 4 octets
    long float <=> double => 8 octets
    long double => 16 octets

    n = 8
    int* pointeur = malloc(sizeof(int) * n) ; sizeof(int) = 4 et n = 8 => 32
    int* pointeur = malloc(12) ;
    */


    Cell** grid = malloc(sizeof(Cell*) * GRID_SIZE);
    /*
    [
        []
        []
        []
        []
        … x15
    ]
    */


    if (grid == NULL) {
        return NULL ;
    }

    for (size_t i = 0; i < GRID_SIZE; ++i) {
        grid[i] = malloc(sizeof(Cell) * GRID_SIZE) ; //grid[i] / Cell*

        /*
        [
            [
                Cell x15
            ]
            [
                Cell x15
            ]
            [
                Cell x15
            ]
            …
        ]
        */

        /*
        4 premières lignes de Cell** grid
        grid[0]=> 0x109D01D
        grid[1]=>
        …
        grid[3] =>
        grid[4] => NULL
        */


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

    /*
    grid[i][j] = [Cell]
    */
    for (size_t i = 0 ; i < GRID_SIZE ; ++i) {
        for (size_t j = 0 ; j < GRID_SIZE ; ++j) {
            grid[i][j] = initCell(rand() % 2) ;
            /*
            [
                [
                    Cell {
                        status (random 0 ou 1)
                        symbol => X si status = 1, sinon O
                    } x15
                ]
                …
            ]
            */
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
    if (grid != NULL) {
        free(grid) ;
        grid = NULL ;
    }
}
