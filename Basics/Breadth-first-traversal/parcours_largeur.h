#ifndef PARCOURS_LARGEUR_H
#define PARCOURS_LARGEUR_H
#include"sommet.h"
#include"graphe.h"

/**
 * @brief parcours en largeur prenant un graphe
 * et un sommet de départ.
 * TEMPS D'EXECUTION O(S+A)
 * @param g un graphe 
 * @param sommet un sommet de départ
 */
void parcours_largeur(graphe *g, sommet sommet);

void parcours_largeur_matrice(graphe *g, sommet sommet);

/**
 * @brief affiche le chemin le plus court entre S et V
 * @param g Un graphe
 * @param R Sommet d'origine
 * @param V Sommet d'arriver
 */
void afficher_chemin(graphe *g, int S, int V);

#endif