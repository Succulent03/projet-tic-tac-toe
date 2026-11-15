#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "tic-tac-toe.h"



void interface(char ** str_grille)
{
    printf(" %c | %c | %c\n", str_grille[0][0], str_grille[0][1], str_grille[0][2]);
    printf("-----------\n");
    printf(" %c | %c | %c\n", str_grille[1][0], str_grille[1][1], str_grille[1][2]);
    printf("-----------\n");
    printf(" %c | %c | %c\n", str_grille[2][0], str_grille[2][1], str_grille[2][2]);
}

void creation_tab(char ** str_grille){
    int a = 0;
    while (a < 3) {
        int b = 0;
        while (b < 3) {
            str_grille[a][b] = ' ';
            b=b+1;
        }
        a=a+1;
    }
}

void liberer_grille(char **str_grille)
{
    int i = 0;

    while (str_grille[i] != NULL)
    {
        free(str_grille[i]);
        i = i + 1;
    }
    free(str_grille);
}

int jouer(char ** str_grille){
    int joueur;
    int ligne;
    int colonne;
    int coups = 0;
    creation_tab(str_grille);
    while(true){
        interface(str_grille);
        printf("Choisissez un chiffre entre 0 et 8 :\n");
        scanf("%d", &joueur);
        system("clear");
        if(joueur >= 0 && joueur <= 8){
            ligne = joueur /3;
            colonne = joueur %3;
            if(str_grille[ligne][colonne] == ' '){
                str_grille[ligne][colonne] = 'O';
                coups++;
                if(victoire(str_grille) == 1){
                    interface(str_grille);
                    printf("Vous avez gagné !\n");
                    return(0);
                }
                if(coups == 9){
                    interface(str_grille);
                    printf("Match nul !\n");
                    return(0);
                }
                ordinateur(str_grille);
                coups++;
                if(victoire(str_grille) == 1){
                    interface(str_grille);
                    printf("L'ordinateur a gagné !\n");
                    return(0);
                }
                
            }
            else{
                printf("Vous ne poouvez pas jouer sur un emplacement déjà utilisé !\n");
            }
        }
        else{
            printf("Il faut choisir un chiffre entre 0 et 8 !\n");
        }
    }
}
void ordinateur(char ** str_grille){
    int ligne = 0;
    int colonne = 0;
    while(str_grille[ligne][colonne] != ' '){
        colonne++;
        if(colonne >2){
            colonne = 0;
            ligne++;
        }
    }
    str_grille[ligne][colonne] = 'X';
}

int victoire(char ** str_grille){
    if (str_grille[0][0] != ' ' && str_grille[0][0] == str_grille[0][1] && str_grille[0][1] == str_grille[0][2])
        return (1);
    if (str_grille[1][0] != ' ' && str_grille[1][0] == str_grille[1][1] && str_grille[1][1] == str_grille[1][2])
        return (1);
    if (str_grille[2][0] != ' ' && str_grille[2][0] == str_grille[2][1] && str_grille[2][1] == str_grille[2][2])
        return (1);

    if (str_grille[0][0] != ' ' && str_grille[0][0] == str_grille[1][0] && str_grille[1][0] == str_grille[2][0])
        return (1);
    if (str_grille[0][1] != ' ' && str_grille[0][1] == str_grille[1][1] && str_grille[1][1] == str_grille[2][1])
        return (1);
    if (str_grille[0][2] != ' ' && str_grille[0][2] == str_grille[1][2] && str_grille[1][2] == str_grille[2][2])
        return (1);

    if (str_grille[0][0] != ' ' && str_grille[0][0] == str_grille[1][1] && str_grille[1][1] == str_grille[2][2])
        return (1);
    if (str_grille[0][2] != ' ' && str_grille[0][2] == str_grille[1][1] && str_grille[1][1] == str_grille[2][0])
        return (1);

    return (0);
}
