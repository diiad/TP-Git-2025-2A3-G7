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
                nextRound(grid) ;
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

void nextRound (Cell** grid) {
    Cell** snapshot = copyGrid(grid) ;
    if (snapshot == NULL) {
        return ;
    }

    size_t neighboursAlive = 0 ;
    for (size_t i = 0; i < GRID_SIZE; ++i) {
        for (size_t j = 0; j < GRID_SIZE; ++j) {
            /*
            cas1 : cellule morte => vérifier si 3 voisines vivantes => vivante
            cas2 : cellule vivante => vérifier si 2 ou 3 voisines vivantes => vivivante
                    sinon morte
            compter nombre voisines vivantes => grid[i][j] = vivante/morte


            i = 0 & j = 0
            "X" O X X O O
            O X X X O O
            O O O O X O

            grid[0][0] = morte

            i = 0 & j = 1
            O O X X O O
            O X X X O O
            O O O O X O

             */
             neighboursAlive = countNeighboursAlive(snapshot, (short)i, (short)j) ;
             grid[i][j] = updateCell(snapshot[i][j].status, neighboursAlive) ;
        }
    }

    freeGrid(snapshot) ;
}

size_t countNeighboursAlive (Cell** grid, short lin, short col) {
    size_t count = 0 ;
    for (short i = lin-1; i <= lin+1; i++) {
        for (short j = col-1; j <= col+1; j++) {
            /*
            [
                [(-1,-1) (-1,0) (-1,1)]
                [(0,-1) X(0,0) (0,1)]
                [(1,-1) (1,0)  (1,1)]
            ]
            */
            if (i >= 0 && j >= 0 && i < GRID_SIZE && j < GRID_SIZE) {
                if (grid[i][j].status == 1) count += 1 ; //count++ or ++count
            }
        }
    }
    if (grid[lin][col].status == 1) count -= 1 ;
    return count ;
}

Cell updateCell (size_t previousState, size_t neighboursAlive) {
    Cell c ;

    //cas 1 : morte => vivante
    if (previousState == 0 && neighboursAlive == 3) {
        c = initCell(1) ;
    } else if (previousState == 1 && (neighboursAlive == 2 || neighboursAlive == 3)) {
        c = initCell(1) ;
    } else {
        c = initCell(0) ;
    }

    return c ;
}

Cell** copyGrid (Cell** toCopy) {
    Cell** copy = malloc(sizeof(Cell*) * GRID_SIZE);

    if (copy == NULL) {
        return NULL ;
    }

    for (size_t i = 0; i < GRID_SIZE; ++i) {
        copy[i] = malloc(sizeof(Cell) * GRID_SIZE) ;

        if (copy[i] == NULL) {
            for (short int j = i-1; j >= 0; --j) {
                free(copy[j]) ;
                copy[j] = NULL ;
            }
            free(copy) ;
            copy = NULL ;
            return NULL ;
        }
    }

    /*
    ++ <=> +=
    a++ => toute fin des opérations
        b = a + a++
            <=>
            b = a + a
            a += 1

            a = 1
            b = a + a++
            => b = 2 / a = 2
    ++a => au tout début des opérations
        b = a + ++a
            <=>
            a += 1
            b = a + a

            a = 1
            b = a + ++a
            => a = 2 / b = 4

    */

    //copie des données de toCopy
    for (size_t i = 0; i < GRID_SIZE; ++i) {
        for (size_t j = 0; j < GRID_SIZE; ++j) {
            copy[i][j] = toCopy[i][j] ;
        }
    }

    return copy ;
}
