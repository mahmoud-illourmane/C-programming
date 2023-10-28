#include"table_hachage.h"

void initialiser_table_hachage(table_hachage *t, int m){
    int i;

    t->t = (liste *) malloc( sizeof(liste) * m );
    if( t->t == NULL ){
        perror("Error dynamically allocating the hash table.\n");
        exit(EXIT_FAILURE);
    }

    t->m = m;

    //Initializing linked lists
    for( i = 0; i < m; i++ ){
        init_liste(&t->t[i]);
    }

}

void afficher_table_hachage(table_hachage *t){
    int i;

    printf("Hash Table :\n");

    if( t->t == NULL ){
        printf("The hash table is empty.\n");
    }else{
        for ( i = 0; i < t->m; i++ ){
            printf("|%d| --> ", i);
            afficher_liste(&t->t[i]);
        }
    }
}

unsigned long long convertir_ch_entier(char *chaine){
    unsigned long long entier = 0;
    int i = 0;
    int ii = 0;
    
    ii = strlen(chaine)-1;

    while( chaine[i] != 0 ){
        entier = entier + chaine[i] * pow( 128, ii );
        ii--;
        i++;
    }

    return entier;
}

int hachage(unsigned long long k, int m){
    return k % m;
}

void inserer_hachage(table_hachage *t, char *chaine){
    int hk = -1;
    if(t->t != NULL){
        hk = hachage( convertir_ch_entier(chaine), t->m );
        inserer_liste( &t->t[hk], chaine ); 
    }
}

cellule* rechercher_hachage(table_hachage *t, char *chaine){
    int hk = -1;
    cellule *recherche = NULL;

    hk = hachage( convertir_ch_entier(chaine), t->m );
    if( t->t != NULL ){
        recherche = recherche_liste( &t->t[hk], chaine );
    }else{
        printf("The hash table is empty.\n");
    }

    return recherche;
}

void supprimer_hachage(table_hachage *t, char *chaine){
    cellule *cellule_a_supprimer = NULL;
    int hk = -1;

    cellule_a_supprimer = rechercher_hachage(t, chaine);

    if( cellule_a_supprimer != NULL ){
        hk = hachage( convertir_ch_entier(chaine), t->m );
        supprimer_cellule_liste(&t->t[hk], cellule_a_supprimer);
    }else{
        printf("The cell does not exist.\n");
    }
}

int compter_table_hachage(table_hachage *t){
    int nombre_de_mot = 0;
    int i;

    for ( i = 0; i < t->m; i++ ){
        nombre_de_mot += compte_element_table_hachage( &t->t[i] );
    }
    return nombre_de_mot;
}

void detruire_table_hachage(table_hachage *t){
    int i;

    if(t->t != NULL){
        //Freeing memory of all lists in the hash table
        for ( i = 0; i < t->m; i++ ){
            detruire_liste(&t->t[i]);
        }

        free(t->t);
        t->t = NULL;
        printf("\nThe hash table has been emptied and initialized to NULL.\n");
        exit(EXIT_SUCCESS);
    }else{
        printf("The hash table is already empty.\n");
    }
    
}