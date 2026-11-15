#ifndef __TIC_TAC_TOE_H__
#define __TIC_TAC_TOE_H__

void liberer_grille(char **str_grille);
void interface(char ** str_grille);
int jouer(char ** str_grille);
void ordinateur(char ** str_grille);
int victoire(char ** str_grille);

#endif