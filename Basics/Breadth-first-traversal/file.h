#ifndef FILE_H
#define FILE_H
#include"sommet.h"

/**
 * @brief Structure de file sera
 * utilisé pour le parcours en largeur
 */
typedef struct{
    int tete;
    int queue;
    int longueur;
    sommet *F;
}file_t;

/**
 * @brief initialiste une file vide
 * @param f adresse de la file
 * @param longueur longueur de la file 
 */
void init_file(file_t *f, int longueur);

/**
 * @brief fonction qui initialise un sommet 
 * pour la partie test de la file
 * @param valeur une valeur
 * @param s un sommet
 */
void init_sommet_file(sommet *s, int valeur);

/**
 * @brief enfile un sommet 
 * dans la file
 * @param f une file
 * @param sommet un sommet a enfiler
 */
void enfiler(file_t *f, sommet s);

/**
 * @brief défile un sommet
 * @param f une file 
 * @return sommet* retourne le sommet défiler
 */
sommet* defiler(file_t *f);

/**
 * @brief verifie si une file est vide
 * @param f une file
 * @return 1 si non-vide, 0 si vide
 */
int file_vide(file_t *f);

/**
 * @brief retourne la taille de la file
 * @return int la taille
 */
int file_pleine(file_t *f);

/**
 * @brief affiche une file
 * @param f une file
 */
void afficher_file(file_t *f);

/**
 * @brief supprime tout les éléments
 * d'une file
 * @param f une file
 */
void detruire_file(file_t *f);

#endif