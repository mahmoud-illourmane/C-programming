#include"cellule.h"
#include<stdio.h>
#include<stdlib.h>

void init_cellule(cellule *c, int s){
    c->sommet = s;
    c->pred = NULL;
    c->succ = NULL;
}

void affiche_cellule(cellule *c){
    if(c != NULL)
        printf("%d\n", c->sommet);
    else{
        printf("Cellule vide : c = NULL\n");
    }
}
