#ifndef PILE_H
#define PILE_H

typedef struct pile_t{
    int *P;
    int taille;
    int sommet;
}pile;

/**
 * @brief Initialise la pile
 * initialise la taille de la pile
 * alloue le tableau de manière dynamique
 * @param p pointeur sur une pile 
 * @param taille la taille du tableau
 */
void init_pile(pile *p, int taille);

/**
 * @brief Empile la valeur 
 * passer en paramètre
 * @param p pointeur sur une pile 
 * @param val valeur à empiler
 */
void empiler(pile *p, int val);

/**
 * @brief Depiler la première  
 * valeur
 * @param p pointeur sur une pile 
 */
int depiler(pile *p);

/**
 * @brief Retourne la valeur du
 * sommet de la pile sans la dépiler
 * @param p pointeur sur une pile
 * @return int la valeur retourner
 */
int sommet(pile *p);

/**
 * @brief Retourne 0 si la pile 
 * est vide.
 * Retourne -1 sinon
 * @param p pointeur sur la pile
 * @return int valeur retourner 0/-1
 */
int pile_vide(pile *p);

/**
 * @brief Retourne 0 si la pile 
 * est pleine.
 * Retourne -1 sinon
 * @param p pointeur sur la pile
 * @return int valeur retourner 0/-1
 */
int pile_pleine(pile *p);

/**
 * @brief Détruit la pile 
 * @param p pointeur sur la pile
 */
void detruire_pile(pile *p);

#endif