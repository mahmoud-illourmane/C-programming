#ifndef GRAPHE_H
#define GRAPHE_H
#include"liste.h"
#include"sommet.h"
#include"arete.h"
#include"tas.h"

    /**
     * @brief Structure d'un graphe
     */
    typedef struct graphe_t{
        int nb_sommet;
        int oriente;
        int value;
        int nb_arete;
        int *m_stockage;
        int **m_adj;    
        liste *l_adj;
        sommet *sommet;
        arete *aretes; //Tableau d'arêtes utilisé pour les algorithmes de plus courts chemin et de poids minimum
        tas tas;
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

    /**
     * @brief fonction qui remplis les 
     * arêtes du graphes
     * @param g un graphe
     */
    void remplir_aretes(graphe *g);
    
#endif