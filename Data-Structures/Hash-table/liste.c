#include"liste.h"

/**
  * @author MAHMOUD ILLOURMANE, 2021/2022.
  * Implementation of a linked list.
  * @version 1.0
  */

void init_liste(liste *l){
    l->tete = NULL;
}

void inserer(liste *l, cellule *c){
    c->succ = l->tete; 			// We insert at the start of the list, so we put the success of the new cell at the head.
	   
	if( l->tete != NULL ) 
		l->tete->pred = c; 		// The pred of the future old first element of the list is now cell c.
						
	l->tete = c;				// We now place cell c in its place, that is to say at the top of the list.
	c->pred = NULL; 			// The pred at the head of the list is always NULL.
}

void inserer_liste(liste *l, char *ch){
	cellule *c = (cellule *) malloc(sizeof(cellule));
	if( c == NULL ){
		perror("Dynamic allocation error in the insert_list function\n");
		exit(EXIT_FAILURE);
	} 
	init_cellule(c, ch);
	inserer(l, c);
}

void afficher_liste(liste *l){
    if( l->tete != NULL ){
        cellule *pelem = l->tete;

        printf("[ ");
        while(pelem != NULL){
            printf("%s, ",pelem->chaine);
            pelem = pelem->succ;
        }
        printf("]\n");
    }else{
        printf("[ - ]\n");
    }
}

int compte_element_liste(liste *l){
	int nombre_de_mot = 0;

    if( l->tete != NULL ){
        cellule *pelem = l->tete;
        while( pelem != NULL ){
            nombre_de_mot ++;
            pelem = pelem->succ;
        }
    }else{
        printf("Your list is currently empty.\n");
    }

	return nombre_de_mot;
}

int compte_element_table_hachage(liste *l){
	int nombre_de_mot = 0;

    if( l->tete != NULL ){
        cellule *pelem = l->tete;
        while( pelem != NULL ){
            nombre_de_mot ++;
            pelem = pelem->succ;
        }
    }
	
	return nombre_de_mot;
}

cellule* recherche_liste(liste *l, char *ch){
	cellule *x = l->tete;

	while( x != NULL && strcmp( x->chaine, ch ) != 0 ){
		x = x->succ;
	}

	if( strcmp( x->chaine, ch ) != 0 ){
		x = NULL;
	}
	
	return x;
}

void supprimer_debut_liste(liste *l){
	cellule *tmp = NULL;

	if( l->tete == NULL ){
		printf("[ empty ]\nThe list is empty, nothing can be deleted.\n");
	}else{
		tmp = l->tete;
		l->tete = tmp->succ;

		if( l->tete != NULL ){
			l->tete->pred = NULL;
		}
			
		free(tmp);
		tmp = NULL;
	}
}

void supprimer_cellule_liste(liste *l, cellule *c){
	if( l->tete == NULL )
		printf("La liste est vide.\n");
	
	if( c->pred != NULL ){ 			// If the cell c that we want to delete has a pred.
		c->pred->succ = c->succ; 	// We modify the succ of the pred from c to c->succ.
	}else{ 							// If cell c does not have a pred this means that it is the first element in the list.
		l->tete = c->succ; 			// We therefore assign the success of c to the head of the list.
	}

	if( c->succ != NULL ){ 			// Si la cellule c qu'on veut supprimer possède un succ.
		c->succ->pred = c->pred; 	// On modifie le pointeur où pointe le c->succ->pred à c->pred.
	}

	free(c);
	c->succ = NULL;
	c->pred = NULL;
	printf("Item deleted.\n");
}

void detruire_liste(liste *l){
	if(l != NULL){
		cellule *tmp = NULL;
		cellule *pelem = l->tete;

		while( pelem != NULL ){
			tmp = pelem;
			pelem = pelem->succ;
			free(tmp);
			tmp = NULL;
		}

		l->tete = NULL;
	}else{
		printf("The list is already empty.\n");
	}
	
}


