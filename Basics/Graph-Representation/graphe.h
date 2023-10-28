#ifndef GRAPHE_H
#define GRAPHE_H
#include"liste.h"

    /**
     * @brief Structure d'un graphe
     */
    typedef struct graphe_t{
        int nb_sommet;
        int oriente;
        int value;
        liste *l_adj;
        int *m_stockage;
        int **m_adj;    
    }graphe;

    //métohdes

    /**
     * @brief fonction qui initialise un graphe
     * @param g pointeur sur une structure d'un graphe
     * @param file_name nom d'un fichier 
     */
    void init_graphe(graphe *g, char *file_name);

    /**
     * @brief fonction qui affiche les propriétés d'un graphe
     * @param g un graphe
     */
    void afficher_graphe(graphe *g);

    /**
     * @brief fonction qui supprime un graphe
     * ainsi que son contenus
     * @param g un graphe
     */
    void detruire_graphe(graphe *g);

    
#endif