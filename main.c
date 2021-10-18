/*
Game of Life practice
Sarah Schlegel
18.10.2021

main file
*/

#include <stdio.h>
#include <stdlib.h>
#include "output.h"

void gameOfLife (void) ;

int main (void) {
    gameOfLife() ;
    return 0;
}

void gameOfLife (void) {
    int option = 1 ;
    while (option) {
        printMenu() ;
        fflush(stdin) ;
        scanf("%d", &option) ;
        switch (option) {
            case 0:
                printf("Free and quit\n") ;
                return ;
            case 1:
                printf("Next round\n") ;
                break ;
            case 2:
                printf("Write to file\n") ;
                break ;
        }
    }
}
