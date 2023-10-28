#ifndef sommet_H
#define sommet_H
#include"liste.h"

/**
 * @brief Structure distance utilisé
 * uniquement lors d'un parcours en profondeur
 */
typedef struct date_t{
    int debut;
    int fin;
}date;

/**
 * @brief structure qui représente un sommet
 */
typedef struct sommet_t{
    int valeur;
    int distance;
    //struct sommet_t *suivant; //Utilisé pour le parcours en largeur implimenter avec une file
    int pere;
    char couleur;
    date date_decouvert; //Utilisé pour le parcours en profondeur
}sommet;

#endif