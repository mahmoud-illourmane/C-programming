#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

#include"graphe.h"
#include"tri_insertion.h"
#include"tas.h"

int main(int argc, const char *argv[]){
    graphe g;
    //int i;

    init_graphe(&g, "graphe5.txt");
    afficher_graphe(&g);

    // Use insertion sort
    // printf("Before insertion sort:\n");
    // for (i = 0; i < g.nb_arete; i++){
    //     printf("%d ", g.aretes[i].poids);
    // }
    // TRI_INSERTION(g.aretes, g.nb_arete);
    // printf("\nAfter insertion sort:\n");
    // for (i = 0; i < g.nb_arete; i++){
    //     printf("%d ", g.aretes[i].poids);
    // }
    // printf("\n");
    
    tri_par_tas(&g.tas, g.aretes, g.nb_arete, TRUE);
    
    detruire_tas(&g.tas);
    detruire_graphe(&g);

    printf("\n");
    return EXIT_SUCCESS;
}
