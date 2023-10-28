#ifndef LISTE_H
#define LISTE_H
#include"cellule.h"

    /**
     * @brief Structure qui représente 
     * une liste doubelement chaîné
     */
    typedef struct liste_t{
        cellule *tete;
    }liste;

    /**
     * @brief initialisation d'une liste vide
     * @param l pointeur sur une liste
     */
    void init_liste(liste *l);

    /**
     * @brief création d'une cellule et insertion dans la liste
     * @param l pointeur sur une liste
     * @param val valeur a insérer
     */
    void inserer_liste(liste *l, int val);

    /**
     * @brief insère une cellule en tête de liste
     * @param l pointeur sur une liste
     * @param c cellule a inséré
     */
    void inserer(liste *l, cellule *c);    

    /**
     * @brief recherche un élément dans une liste
     * via un identifiant
     * @param l pointeur sur une liste
     * @param id valeur à rechercher
     * @return cellule* OU NULL 
     */
    cellule* recherche_liste(liste *l, int id);

    /**
     * @brief affiche une liste
     * @param l pointeur sur une liste
     */
    void afficher_liste(liste *l);

    /**
     * @brief supprime le premier élément d'une liste
     * @param l pointeur sur une liste
     */
    void supprimer_debut_liste_statique(liste *l);

    /**
     * @brief supprime le premier élément d'une liste 
     * avec une cellule alloué dynamiquement
     * @param l pointeur sur une liste
     */
    void supprimer_debut_liste(liste *l);

    /**
     * @brief supprime la cellule indiqué en paramètre
     * @param l pointeur sur une liste
     * @param c pointeur sur une cellule
     */
    void supprimer_cellule_liste_statique(liste *l, cellule *c);

    /**
     * @brief supprime la cellule alloué dynamiquement, indiqué en paramètre
     * @param l pointeur sur une liste
     * @param c pointeur sur une cellule
     */
    void supprimer_cellule_liste(liste *l, cellule *c);

    /**
     * @brief supprime toute la liste
     * @param l pointeur sur une liste
     */
    void detruire_liste(liste *l);

    /**
     * @brief calcul la taille d'une liste
     * @param l pointeur sur une liste
     * @return la taille
     */
    int tailleListe(liste *l);
    
#endif