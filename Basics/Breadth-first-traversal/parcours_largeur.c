#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

#include"graphe.h"
#include"file.h"
#include"parcours_largeur.h"

void parcours_largeur(graphe *g, sommet som){
    int u;
    file_t f;
    sommet *su;
    cellule *tmp = NULL;
    
    //Boucle d'initialisation des sommets
    for (u = 0; u < g->nb_sommet; u++){
        g->sommet[u].couleur = 'B';
        g->sommet[u].distance = __INT_MAX__;
        g->sommet[u].pere = -1;
    }
    
    //Traitement du sommet de départ
    g->sommet[som.valeur].couleur = 'G';
    g->sommet[som.valeur].distance = 0;
    g->sommet[som.valeur].pere = -1;

    init_file(&f, g->nb_sommet);//Initialisation de la file
    enfiler(&f, som);//On enfile le premier sommet

    //Boucle de traitement des sommets en utilisant les listes d'adjacences
    while(file_vide(&f) != 0){
        su = defiler(&f);
        tmp = g->l_adj[su->valeur].tete;
        
        while(tmp != NULL){
            if(g->sommet[tmp->sommet].couleur == 'B'){
                g->sommet[tmp->sommet].couleur = 'G';
                g->sommet[tmp->sommet].distance = g->sommet[su->valeur].distance + 1;
                g->sommet[tmp->sommet].pere = g->sommet[su->valeur].valeur;
                enfiler(&f, g->sommet[tmp->sommet]);
            }
            tmp = tmp->succ;
        }
        g->sommet[su->valeur].couleur = 'N';
    }
    
    detruire_file(&f);
    printf("\n");
}



void afficher_chemin(graphe *g, int R, int V){
    if(g->sommet[V].valeur == g->sommet[R].valeur){
        printf("%d ", g->sommet[R].valeur);
    }else{
        if(g->sommet[V].pere == -1){
            printf("Aucun chemin de la racine %d au sommet %d\n", g->sommet[R].valeur, g->sommet[V].valeur);
        }else{
            afficher_chemin(g, g->sommet[R].valeur, g->sommet[V].pere);
            printf("%d ", g->sommet[V].valeur);
        }
    }
}