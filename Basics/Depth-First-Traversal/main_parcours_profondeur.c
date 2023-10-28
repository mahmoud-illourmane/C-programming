#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

#include"graphe.h"
#include"parcours_profondeur.h"

int main(int argc, const char *argv[]){
    graphe g;

    init_graphe(&g, "graphe2.txt");
    parcours_profondeur_recursif(&g);
    afficher_parcours_profondeur(&g);
    
    detruire_graphe(&g);
    return EXIT_SUCCESS;
}
