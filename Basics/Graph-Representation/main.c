#include"liste.h"
#include"graphe.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

/**
 * @brief programme de test qui affiche les données d'un graphe 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, const char *argv[]){
    graphe g;
    
    init_graphe(&g, "graphe2.txt");
    
    afficher_graphe(&g);
    detruire_graphe(&g);
    
    return EXIT_SUCCESS;
}
