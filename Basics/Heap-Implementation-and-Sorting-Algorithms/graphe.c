#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"liste.h"
#include"graphe.h"

void init_graphe(graphe *g, char *file_name){
    FILE *fd = NULL;
    int val, val2, poids_, err, i, j;
    char tmp_char[20];

    fd = fopen(file_name, "r");
    if(fd == NULL){
        perror("Erreur lors de l'ouverture du fichier.\n");
        exit(EXIT_FAILURE);
    }

    /*----------------Lectures des informations du graphe----------------*/

    //Readings of the number of vertices in the graph
    err = fscanf(fd, "%s", tmp_char);
    if(err == -1){
        perror("Error reading data from the init_graph graph.");
        exit(EXIT_FAILURE);
    }
    err = fscanf(fd, "%d", &val);
    if(err == -1){
        perror("Error reading data from the init_graph graph.");
        exit(EXIT_FAILURE);
    }

    g->nb_sommet = val;//Enter the number of vertices retrieved from the file in the graph structure

    //Allocation of the linked list array that will be used for adjacency lists
    g->l_adj = (liste *) malloc(sizeof(liste) * g->nb_sommet);
    if(g->l_adj == NULL){
        perror("Erreur lors de l'allocation du tableau de liste.\n");
        exit(EXIT_FAILURE);
    }

    //Allocation of storage arrays for adj matrix
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

    //Allocation of the vertex table that will be used for the routes
    g->sommet = (sommet *) malloc(sizeof(sommet) * g->nb_sommet);
    if(g->sommet == NULL){
        perror("Erreur lors de l'allocation du tableau de sommets.\n");
        exit(EXIT_FAILURE);
    }

    //Initializing the linked list array
    //Aassignment of the values of each vertex
    for(i = 0; i< g->nb_sommet; i++){
        init_liste(&g->l_adj[i]);
        g->sommet[i].valeur = i;
    }

    //Simplification of the m_storage table to access it via m_adj[u][v]
    for(i = 0; i < g->nb_sommet; i++){
        g->m_adj[i] = &g->m_stockage[i*g->nb_sommet];
    }  

    //Matrix initialization
    for(i = 0; i< g->nb_sommet; i++){
        for(j = 0; j < g->nb_sommet; j++){
            g->m_adj[i][j] = 0;
        }
    }

    //Data oriented initialization
    err = fscanf(fd, "%s", tmp_char);
    err = fscanf(fd, "%d", &val);
    g->oriente = val;

    //Initializing valued data
    err = fscanf(fd, "%s", tmp_char);
    err = fscanf(fd, "%d", &val);
    g->value = val;
    

    /*------READING ADJ LISTS------*/
    err = fscanf(fd, "%s", tmp_char);//Reading the string DEBUT_DEF_ARETES
   
    g->nb_arete = 0;//Initialization of the number of edges of the graph

    //Creation of adjacency lists as well as adjacency matrices
    while(strcmp(tmp_char, "FIN_DEF_ARETES") != 0){
        if(g->oriente ==  0){
            err = fscanf(fd, "%s", tmp_char); //Lecture de la première valeur/chaîne
            if(strcmp(tmp_char, "FIN_DEF_ARETES") != 0){
                val = atoi(tmp_char);//Si c'est une valeur numérique on la converti en int
                err = fscanf(fd, "%d", &val2);
                err = fscanf(fd, "%d", &poids_);//Lecture de la valeur du poids

                //Liste d'adjacenses
                inserer_liste(&g->l_adj[val], val2);
                g->nb_arete++;
                inserer_liste(&g->l_adj[val2], val);
                g->l_adj[val].tete->poids = poids_;
                g->l_adj[val2].tete->poids = poids_;

                //Matrice d'adjacences
                g->m_adj[val][val2] = poids_;
                g->m_adj[val2][val] = poids_;  
            }
        }else{
            err = fscanf(fd, "%s", tmp_char);
            if(strcmp(tmp_char, "FIN_DEF_ARETES") != 0){
                val = atoi(tmp_char); 
                err = fscanf(fd, "%d", &val);
                err = fscanf(fd, "%d", &poids_);//Lecture de la valeur du poids

                //Liste d'adjacenses
                inserer_liste(&g->l_adj[val], val2);
                g->nb_arete++;
                g->l_adj[val].tete->poids = poids_;

                //Matrice d'adjacences
                g->m_adj[val][val2] = poids_;
                g->m_adj[val2][val] = 0;
            }
        }
    }
    fclose(fd);

    //Allocation du tableau d'arêtes
    g->aretes = (arete *) malloc( sizeof(arete) * g->nb_arete);
    if(g->aretes == NULL){
        perror("Erreur lors de l'allocation du tableau d'arêtes\n");
        exit(EXIT_FAILURE);
    }

    remplir_aretes(g);
}

void remplir_aretes(graphe *g){
    int i, k;
    cellule *tmp = NULL;
    k = 0;
    
    for(i = 0; i < g->nb_sommet; i++){
        tmp = g->l_adj[i].tete;
        while( tmp != NULL && i < tmp->sommet ){
            g->aretes[k].sommet_origine = i;
            g->aretes[k].sommet_extrimite = tmp->sommet;
            g->aretes[k].poids = tmp->poids;    
            tmp = tmp->succ;
            k++;
        }
    }
}

void afficher_graphe(graphe *g){
    int i,j;

    printf("Graphe :\nNombre de sommets : %d\nOrienté (O/NON, 1/OUI): %d\nValué (O/NON, 1/OUI): %d\n\n", g->nb_sommet, g->oriente, g->value);

    printf("Liste d'adjacences : [sommet] -> [poids|sommet] -> ... -> NULL\n\n");
    for ( i = 0; i < g->nb_sommet; i++ ){
        printf("[%d] -> ", i);
        afficher_liste(&g->l_adj[i]);
    }

    printf("\nMatrice d'adjacences :\n");
    for ( i = 0; i < g->nb_sommet; i++){
        printf("[%d]", i);
        for (j = 0; j < g->nb_sommet; j++){
            printf(" %d ", g->m_adj[i][j]);
        }
        printf("\n");
    }
    
    printf("\nArêtes :\n");
    for (i = 0; i < g->nb_arete; i++){
        printf("(%d)-(%d): poids %d\n", g->aretes[i].sommet_origine, g->aretes[i].sommet_extrimite, g->aretes[i].poids);
    }  

    printf("\n");
}

void detruire_graphe(graphe *g){
    int i;

    //Libération mémoire de toutes les listes d'adj
    for (i = 0; i < g->nb_sommet; i++){
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
    
    free(g->aretes);
    g->aretes = NULL;
}