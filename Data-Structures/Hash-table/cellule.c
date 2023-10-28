#include"cellule.h"

void init_cellule(cellule *c, char *ch){
    strcpy(c->chaine, ch);
    c->pred = NULL;
    c->succ = NULL;
}

void affiche_cellule(cellule *c){
    if(c != NULL)
        printf("%s\n", c->chaine);
    else{
        printf("Cellule vide : c = NULL\n");
    }
}
