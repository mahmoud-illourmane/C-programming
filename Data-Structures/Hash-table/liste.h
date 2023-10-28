#ifndef LISTE_H
#define LISTE_H
#include"cellule.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

    /**
     * @brief Structure qui représente 
     * une liste doubelement chaîné de châine de caractères
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
     * @param ch châine à insérer
     */
    void inserer_liste(liste *l, char *ch);

    /**
     * @brief insère une cellule en tête de liste.
     * TEMPS D'EXECUTION O(1)
     * @param l pointeur sur une liste
     * @param c cellule a inséré
     */
    void inserer(liste *l, cellule *c);    

    /**
     * @brief recherche un élément dans une liste.
     * TEMPS D'EXECUTION O(N)
     * @param l pointeur sur une liste
     * @param ch chaine à rechercher
     * @return cellule* OU NULL 
     */
    cellule* recherche_liste(liste *l, char *ch);

    /**
     * @brief affiche une liste.
     * TEMPS D'EXECUTION O(N)
     * @param l pointeur sur une liste
     */
    void afficher_liste(liste *l);

    /**
     * @brief compte le nombre d'élément d'une liste.
     * TEMPS D'EXECUTION O(N) 
     * @param l pointeur sur une liste
     * @return le nombre de mot
     */
    int compte_element_liste(liste *l);

    /**
     * @brief compte le nombre d'élément d'une table de hachage.
     * Elle varie simplement par rapport à la fonction 'compte_element_liste', sur
     * le point qu'elle n'affiche pas la phrase lorsque une liste est vide.
     * TEMPS D'EXECUTION O(N) 
     * @param l pointeur sur une liste
     * @return le nombre de mot
     */
    int compte_element_table_hachage(liste *l);

    /**
     * @brief supprime le premier élément d'une liste.
     * TEMPS D'EXECUTION O(1) 
     * @param l pointeur sur une liste
     */
    void supprimer_debut_liste(liste *l);

    /**
     * @brief supprime la cellule indiqué en paramètre si elle existe.
     * @param l pointeur sur une liste
     * @param c pointeur sur une cellule
     */
    void supprimer_cellule_liste(liste *l, cellule *c);

    /**
     * @brief supprime toute la liste
     * TEMPS D'EXECUTION O(1) 
     * @param l pointeur sur une liste
     */
    void detruire_liste(liste *l);

#endif