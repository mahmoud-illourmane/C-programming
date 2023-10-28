#include<stdio.h>
#include<stdlib.h>

#include"tas.h"

int racine(tas *tas){ return tas->A[0].poids; }

int parent(int i){ 
    int r;
    int tmp = i+1;
    r = tmp/2;
    return r-1; 
}

int gauche(int i){ 
    int ii, r;
    ii = i+1;
    r = ii*2;
    return r-1; 
}

int droite(int i){ 
    int ii, r;
    ii = i+1;
    r = ii*2+1;
    return r-1; 
}

void echanger(arete *a, arete *b){
    arete tmp;
    tmp = *b;
    *b = *a;
    *a = tmp;
}

void entasser_max(tas *tas, int i){
    int g, d, max;
    
    g = gauche(i);
    d = droite(i);
    
    if(g < tas->taille && tas->A[g].poids > tas->A[i].poids){
        max = g;
    }else{
        max = i;
    }

    if(d < tas->taille && tas->A[d].poids > tas->A[max].poids){
        max = d;
    }
    
    if(max != i){
        echanger(&tas->A[i], &tas->A[max]);
        entasser_max(tas, max);
    }
}

void afficherTas(tas *tas){
    int i;

    printf("[");
    for ( i = 0; i < tas->taille; i++){
        printf("%d, ", tas->A[i].poids);
    }
    printf("]\n");
}

void construire_tas_max(tas *tas, arete *tab, int longueur){
    int i;

    tas->longueur = longueur;
    tas->taille = longueur;
    //Allocation dynamique du tableau d'arêtes du tas
    tas->A = (arete *) malloc( sizeof(arete) * longueur );
    if(tas->A == NULL){
        perror("Erreur lors de l'allocation du tableau du tas\n");
        exit(EXIT_FAILURE);
    }
    
    //Copie du tableau d'arêtes dans le tableau tas->A
    for (i = 0; i < longueur; i++){
        tas->A[i].poids = tab[i].poids;
        tas->A[i].sommet_origine = tab[i].sommet_origine;
        tas->A[i].sommet_extrimite = tab[i].sommet_extrimite;
    }
    
    //Boucle qui entasse tous les éléments du tas
    for ( i = tas->longueur/2; i >= 0; i-- ){
        entasser_max(tas, i);
    }
}

void tri_par_tas(tas *tas, arete *tab, int longueur, int bool_print){
    int i;
    construire_tas_max(tas, tab, longueur); //Construction d'un tas max pour la suite du tri
    
    if(bool_print == 0){
        printf("\n###TRI PAR TAS###\n");
        printf("Informations obtenus :\n  Taille de A : %d\n  Longueur de A : %d\n", tas->taille, tas->longueur);

        printf("\n\nTableau :\n");
        for (i = 0; i < tas->longueur; i++){
            printf("%d ", tab[i].poids);
        }

        printf("\n\nTransformation en tas max :\n");
        for (i = 0; i < tas->longueur; i++){
            printf("%d ", tas->A[i].poids);
        }
    }
    
    /*Coeur de la fonction*/
    for ( i = tas->longueur-1; i >= 0; i--){
        echanger(&tas->A[0], &tas->A[i]);
        tas->taille = tas->taille-1;
        entasser_max(tas, 0); //On entasse toujours en indice 0 après avoir fais l'échange
    }
    /*Coeur de la fonction*/

    if(bool_print == 0){
        printf("\n\nTableau après le tri par tas :\n");
        for (i = 0; i < longueur; i++){
            printf("[(%d)-(%d)] poids %d\n", tas->A[i].sommet_origine, tas->A[i].sommet_extrimite, tas->A[i].poids);
        }
    }
    printf("\n");
}

void detruire_tas(tas *tas){
    free(tas->A);
    tas->A = NULL;
}