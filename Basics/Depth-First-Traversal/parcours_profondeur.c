#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

#include"graphe.h"
#include"parcours_profondeur.h"

void parcours_profondeur_recursif(graphe *g){
    int u;
    int date_ = -1;

    //Boucle d'initialisation des sommets
    for (u = 0; u < g->nb_sommet; u++){
        g->sommet[u].couleur = 'B';
        g->sommet[u].pere = -1;
    }
    date_ = 0;

    //Boucle qui traite les sommets avec visiter_pp
    for (u = 0; u < g->nb_sommet; u++){
        if(g->sommet[u].couleur == 'B'){
            visiter_pp(g, u, &date_);
        }
    }

    printf("\n");
}

void visiter_pp(graphe *g, int u, int *date_){
    cellule *tmp = NULL; //Utilisé pour le parcours des listes d'adjacences

    //Traitement du sommet courant u
    g->sommet[u].couleur = 'G';//On met le sommet à gris
    *date_ = *date_ + 1;
    g->sommet[u].date_decouvert.debut = *date_;

    //Boucle qui parcours la liste d'adjacences de chaque sommet
    tmp = g->l_adj[u].tete;
    while(tmp != NULL){
        if( g->sommet[tmp->sommet].couleur == 'B'){
            g->sommet[tmp->sommet].pere = u; //tmp->sommet correspond au sommet blanc présent dans la liste d'adj du sommet u passé en paramètre
            visiter_pp(g, g->sommet[tmp->sommet].valeur, date_);   
        }
        tmp = tmp->succ; //Si le if retourn 1, on passe au sommet suivant de la liste d'adj de u
    }

    //On a fini le traitement d'un sommet on le met à noir et on affecte la date de fin
    g->sommet[u].couleur = 'N';
    *date_ = *date_ + 1;
    g->sommet[u].date_decouvert.fin = *date_;
}

void afficher_parcours_profondeur(graphe *g){
    int i;
    printf("\n");
    for (i = 0; i < g->nb_sommet; i++){
        printf("Sommet : %d, date debut : %d, date fin : %d, pere : %d\n", g->sommet[i].valeur, g->sommet[i].date_decouvert.debut, g->sommet[i].date_decouvert.fin, g->sommet[i].pere);
    }   
    printf("\n");
}