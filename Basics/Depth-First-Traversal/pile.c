#include"stdio.h"
#include"stdlib.h"

#include"pile.h"

void init_pile(pile *p, int taille){
    p->P = (int *) malloc( sizeof(int) * taille );
    if( p->P == NULL ){
        perror("Erreur lors de l'allocation du tableau de la pile.\n");
        exit(EXIT_FAILURE);
    }
    p->taille = taille;
    p->sommet = 0;
}

int pile_vide(pile *p){
    int verif = -1;
    if(p->sommet == 0){
        verif = 0;
    }
    return verif;
}

int pile_pleine(pile *p){
    int verif = -1;
    if(p->sommet >= p->taille-1){
        verif = 0;
    }
    return verif;
}

void empiler(pile *p, int val){
    if( pile_pleine(p) == 0){
        perror("La pile est pleine on ne peut pas empiler.\n");
        exit(EXIT_FAILURE);
    }
    p->sommet++;
    p->P[p->sommet] = val;
}

int depiler(pile *p){
    if( pile_vide(p) == 0 ){
        perror("La pile est vide.\n");
        exit(EXIT_FAILURE);
    }
    p->sommet--;
    return p->P[p->sommet+1];
}

int sommet(pile *p){
    if( pile_vide(p) == 0 ){
        perror("La pile est vide.\n");
        exit(EXIT_FAILURE);
    }
    return p->P[p->sommet];
}

void detruire_pile(pile *p){
    free(p->P);
    p->P = NULL;
}