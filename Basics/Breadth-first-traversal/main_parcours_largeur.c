#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

#include"graphe.h"
#include"file.h"
#include"parcours_largeur.h"

int main(int argc, const char *argv[]){
    graphe g;
    int i;

    init_graphe(&g, "graphe2.txt");
    //afficher_graphe(&g);
    parcours_largeur(&g, g.sommet[0]);
    
    for(i = 0; i < g.nb_sommet; i++){
        afficher_chemin(&g, 0, i);
        printf("\n");
    }

    // afficher_chemin(&g, 2, 6);
    printf("\n");
    detruire_graphe(&g);
    return EXIT_SUCCESS;
}
