#ifndef TRI_INSERTION_H
#define TRI_INSERTION_H
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>// for clock_t, clock(), CLOCKS_PER_SEC

#include"arete.h"

/**
 * @brief Fonction du tri par insertion
 * en O(n²)
 * @param tab tableau d'arêtes à trier
 * @param taille la taille du tableau
 */
void TRI_INSERTION(arete *tab, int taille);

#endif