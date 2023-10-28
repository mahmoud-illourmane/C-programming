#include"file.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void init_file(file_t *f, int longueur){
    f->tete = 0;
    f->queue = 0;
    f->longueur = longueur;
    f->F = (sommet *) malloc(sizeof(sommet) * longueur);
}

void init_sommet_file(sommet *s, int valeur){
    s->valeur = valeur;
}

void enfiler(file_t *f, sommet s){
    
    if(f->tete == f->queue+1){
        printf("La file est pleine.\n");
        exit(EXIT_FAILURE);
    }
    f->F[f->queue] = s; //on enfile le sommet
    if(f->queue == f->longueur){ // Après enfilage on vérifie si l'index de queue n'a pas atteint la limite de la file 
        f->queue = 0; //Si c'est le cas on renvient à l'index 0 (file circulaire)
    }else{
        f->queue = f->queue+1;
    }
}

sommet* defiler(file_t *f){
    sommet *tmp = NULL;
    tmp = &f->F[f->tete];
    if(f->tete == f->longueur){
        f->tete = 0; 
    }else{
        f->tete = f->tete+1;
    }
    return tmp;
}

void afficher_file(file_t *f){
    sommet *tmp = NULL;

    printf("\nFile F:\n");
    while(f->tete != f->queue){
        tmp = defiler(f);
        printf("%d ", tmp->valeur);
    }
    printf("\n");
}

int file_vide(file_t *f){
    int b = -1;
    if( f->tete == f->queue ){
        b = 0;
    }
    return b;
}

int file_pleine(file_t *f){
    int b = -1;
    if(f->tete == f->queue+1){
        b = 0;
    }
    return b;
}

void detruire_file(file_t *f){
    free(f->F);
    f->F = NULL;
}