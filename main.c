#include <stdlib.h>
#include <stdio.h>
#include <tic-tac-toe.h>
#include <unistd.h>

char *str_cpy(char *str)
{
    int len = str_len(str);
    char *copy = malloc((len + 1) * sizeof(char));
    int i = 0;

    copy[len] = '\0';

    while (str[i] != '\0')
    {
        copy[i] = str[i];
        i = i + 1;
    }

    return(copy);
}

int main(){

    char **str_grille = malloc(4 * sizeof(*str_grille));
    
    str_grille[3] = NULL;
    str_grille[0] = str_cpy("   ");
    str_grille[1] = str_cpy("   ");
    str_grille[2] = str_cpy("   ");
    printf("%c | %c | %c", );
}
