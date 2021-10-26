typedef struct Cell {
    size_t status ; //0 ou 1
    char symbol ; //O ou X
    //char evolution[10] ;
} Cell;

Cell initCell (size_t s) ;

Cell** initGrid ();
void freeGrid (Cell** grid) ;

// if (status == 1) printf("X") ;
// else printf("O") ;
//
// printf("%c", symbol) => X ou O
