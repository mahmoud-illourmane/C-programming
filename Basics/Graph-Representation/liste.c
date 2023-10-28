#include"liste.h"
#include<stdio.h>
#include<stdlib.h>

/**
 * @brief fonction qui initialise 
 * une liste vide
 * @param l pointeur sur une liste
 */
void init_liste(liste *l){
    l->tete = NULL;
}

void inserer(liste *l, cellule *c){
    c->succ = l->tete;
	   
	if(l->tete != NULL) 
		l->tete->pred = c;

	l->tete = c;	
	c->pred = NULL;
}

void inserer_liste(liste *l, int val){
	cellule *c = (cellule *) malloc(sizeof(cellule));
	if(c == NULL){
		printf("Erreur allocation dynamique");
		exit(EXIT_FAILURE);
	} 
	init_cellule(c, val);
	inserer(l, c);
}

void afficher_liste(liste *l){
    if(l->tete != NULL){
        cellule *pelem = l->tete;

        printf("[ ");
        while(pelem != NULL){
            printf("%d ",pelem->sommet);
            pelem = pelem->succ;
        }
        printf("]\n");
    }else{
        printf("Liste vide : NULL\n");
    }
    
}

cellule* recherche_liste(liste *l, int id){
	cellule *x = l->tete;
	while(x != NULL && x->sommet != id){
		x = x->succ;
	}
	return x;
}

void supprimer_debut_liste_statique(liste *l){
    cellule *tmp; 

	if(l->tete == NULL){
		printf("[ empty ]\nLa liste est vide, on peut rien supprimer.\n");
		exit(EXIT_FAILURE);
	}

	tmp = l->tete;
	if(tmp == NULL) exit(EXIT_FAILURE);

	l->tete = tmp->succ;
	if(l->tete != NULL)
		l->tete->pred = NULL;
}

void supprimer_debut_liste(liste *l){
	cellule *tmp = l->tete;
	
	if(l->tete == NULL){
		printf("[ empty ]\nLa liste est vide, on ne peut rien supprimer.\n");
	}else{
		l->tete = tmp->succ;
		if(l->tete)
			l->tete->pred = NULL;

		free(tmp);
		tmp = NULL;
	}
}

void supprimer_cellule_liste_statique(liste *l, cellule *c){
	if(c->pred != NULL){
		c->pred->succ = c->succ;
	}else{
		l->tete = c->succ;
	}

	if(c->succ != NULL){
		c->succ->pred = c->pred;
	}

	c->succ = NULL;
	c->pred = NULL;
}

void supprimer_cellule_liste(liste *l, cellule *c){
	if(l->tete == NULL){
		printf("La liste est vide.\n");
	}

	if(c->pred != NULL){
		c->pred->succ = c->succ;
	}else{
		l->tete = c->succ;
	}

	if(c->succ != NULL){
		c->succ->pred = c->pred;
	}

	free(c);
	c->succ = NULL;
	c->pred = NULL;
}

void detruire_liste(liste *l){
	cellule *tmp;
	cellule *pelem = l->tete;

	while(pelem){
		tmp = pelem;
		pelem = pelem->succ;
		free(tmp);
		tmp = NULL;
	}

	l->tete = NULL;
}


