#include <stdlib.h>
#include <stdio.h>
#include "tic-tac-toe.h"



int main(){
    char **str_grille = malloc(4 * sizeof(*str_grille));
    str_grille[3] = NULL;
    str_grille[0] = malloc(4 * sizeof(char));
    str_grille[1] = malloc(4 * sizeof(char));
    str_grille[2] = malloc(4 * sizeof(char));
    jouer(str_grille);  
}
