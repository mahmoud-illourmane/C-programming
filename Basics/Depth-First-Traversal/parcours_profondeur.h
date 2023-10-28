#ifndef PARCOURS_PROFONDEUR_H
#define PARCOURS_PROFONDEUR_H
#include"sommet.h"
#include"graphe.h"

/**
 * @brief fonction qui éffectue le parcours
 * en profondeur
 * @param g un graphe 
 */
void parcours_profondeur_recursif(graphe *g);

/**
 * @brief fonction qui éffectue visiter_pp
 * @param g un graphe
 * @param u un sommet
 * @param *date_ la date courante
 */
void visiter_pp(graphe *g, int u, int *date_);

/**
 * @brief affiche le résultat du parcours en profondeur
 * @param g Un graphe
 */
void afficher_parcours_profondeur(graphe *g);

#endif