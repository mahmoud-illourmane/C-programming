#include"liste.h"
#include"graphe.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void init_graphe(graphe *g, char *file_name){
    FILE *fd = NULL;
    int val, val2, err, i, j;
    char tmp_char[20];

    fd = fopen(file_name, "r");
    if(fd == NULL){
        perror("Erreur lors de l'ouverture du fichier.\n");
        exit(EXIT_FAILURE);
    }

    //Lectures des informations du graphe
    err = fscanf(fd, "%s", tmp_char);
    if(err == -1){
        perror("Erreur lors de la lecture des données du graphe init_graphe.");
        exit(EXIT_FAILURE);
    }
    err = fscanf(fd, "%d", &val);
    if(err == -1){
        perror("Erreur lors de la lecture des données du graphe init_graphe.");
        exit(EXIT_FAILURE);
    }

    //Saisi du nombre de sommet récupérer dans le fichier dans la structure du graphe
    g->nb_sommet = val;
    //Allocation du tableau de liste chaîné qui sera utilisé pour les listes d'adjacences
    g->l_adj = (liste *) malloc(sizeof(liste) * g->nb_sommet);
    if(g->l_adj == NULL){
        perror("Erreur lors de l'allocation du tableau de liste.\n");
        exit(EXIT_FAILURE);
    }
    g->m_stockage = (int *) malloc(sizeof(int) * (g->nb_sommet*g->nb_sommet));
    if(g->m_stockage == NULL){
        perror("Erreur lors de l'allocation du tableau de matrice.\n");
        exit(EXIT_FAILURE);
    }
    g->m_adj = (int **) malloc(sizeof(int *) * g->nb_sommet);
    if(g->m_adj == NULL){
        perror("Erreur lors de l'allocation de g->m_adj.\n");
        exit(EXIT_FAILURE);
    }
    //Allocation du tableau de sommets qui sera utilisé pour les parcours 
    g->sommet = (sommet *) malloc(sizeof(sommet) * g->nb_sommet);
    if(g->sommet == NULL){
        perror("Erreur lors de l'allocation du tableau de sommets.\n");
        exit(EXIT_FAILURE);
    }

    //Initialisation du tableau de listes chaîné
    //Affectation des valeurs de chaque sommets 
    for(i = 0; i< g->nb_sommet; i++){
        init_liste(&g->l_adj[i]);
        g->sommet[i].valeur = i;
    }

    //Simplification du tableau m_stockage pour y accéder via m_adj[u][v]
    for(i = 0; i < g->nb_sommet; i++){
        g->m_adj[i] = &g->m_stockage[i*g->nb_sommet];
    }  

    //Initialisation de la matrice 
    for(i = 0; i< g->nb_sommet; i++){
        for(j = 0; j < g->nb_sommet; j++){
            g->m_adj[i][j] = 0;
        }
    }

    //Initialisation des données orienté et valué
    err = fscanf(fd, "%s", tmp_char);
    err = fscanf(fd, "%d", &val);
    g->oriente = val;

    err = fscanf(fd, "%s", tmp_char);
    err = fscanf(fd, "%d", &val);
    g->value = val;
    
    err = fscanf(fd, "%s", tmp_char);
    //Création des liste d'adjacences ainsi que des matrices d'adjacences
    while(strcmp(tmp_char, "FIN_DEF_ARETES") != 0){
        if(g->oriente ==  0){
            err = fscanf(fd, "%s", tmp_char);
            if(strcmp(tmp_char, "FIN_DEF_ARETES") != 0){
                val = atoi(tmp_char);  

                err = fscanf(fd, "%d", &val2);

                //Liste d'adjacenses
                inserer_liste(&g->l_adj[val], val2);
                inserer_liste(&g->l_adj[val2], val);

                //Matrice d'adjacences
                g->m_adj[val][val2] = 1;
                g->m_adj[val2][val] = 1;  
            }
            
        }else{
            err = fscanf(fd, "%s", tmp_char);
            if(strcmp(tmp_char, "FIN_DEF_ARETES") != 0){
                val = atoi(tmp_char); 
                err = fscanf(fd, "%d", &val);

                //Liste d'adjacenses
                inserer_liste(&g->l_adj[val], val2);

                //Matrice d'adjacences
                g->m_adj[val][val2] = 1;
                g->m_adj[val2][val] = 0;   
            }
        }
   
    }
    fclose(fd);
}

void afficher_graphe(graphe *g){
    int i,j;

    printf("Graphe :\nNombre de sommets : %d\nOrienté : %d\nValué : %d\n\n", g->nb_sommet, g->oriente, g->value);

    printf("Liste d'adjacences :\n");
    for ( i = 0; i < g->nb_sommet; i++ ){
        printf("[%d] -> ", i);
        afficher_liste(&g->l_adj[i]);
    }

    printf("\nMatrice d'adjacences :\n");
    for ( i = 0; i < g->nb_sommet; i++){
        for (j = 0; j < g->nb_sommet; j++){
            printf(" %d ", g->m_adj[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");
}

void detruire_graphe(graphe *g){
    
    //Libération mémoire de toutes les listes d'adj
    for (int i = 0; i < g->nb_sommet; i++){
        detruire_liste(&g->l_adj[i]);
    }
    
    free(g->l_adj);
    g->l_adj = NULL;

    free(g->m_stockage);
    g->m_stockage = NULL;

    free(g->m_adj);
    g->m_adj = NULL;

    free(g->sommet);
    g->sommet = NULL;
}