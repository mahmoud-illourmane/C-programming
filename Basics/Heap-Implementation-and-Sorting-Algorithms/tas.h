#ifndef TAS_H
#define TAS_H
#include"arete.h"

    /**
     * @brief Structure représentant un tas max d'arêtes
     * int longueur : nombre d'éléments du tableau
     * int taille : nombre d'éléments ranger dans le tableau A 
     */
    typedef struct tas_t{
        int longueur;
        int taille;
        arete *A;
    }tas;

    /*==Procédures et fonctions==*/ 

    /**
     * @brief Fonction qui affiche une tas.
     * @param tas tas min
     */
    void afficherTas(tas *tas);

    /**
     * @brief retourne la racine du tas
     * TEMPS D'EXECUTION O(1)
     * @return int le sommet parent
     */
    int racine(tas *tas);

    /**
     * @brief retourne le sommet parent du noeud i
     * TEMPS D'EXECUTION O(1)
     * @param i indice du tableau
     * @return int le sommet parent
     */
    int parent(int i);

    /**
     * @brief retourne le fils gauche du noeud i
     * TEMPS D'EXECUTION O(1)
     * @param i l'indice de recherche
     * @return int le sommet fils gauche de i
     */
    int gauche(int i);

    /**
     * @brief retourne le fils droit du noeud i
     * TEMPS D'EXECUTION O(1)
     * @param i l'indice de recherche
     * @return int le sommet fils droit de i
     */
    int droite(int i);

    /**
     * @brief Retourne le maximum
     * entre a et b
     * @param a une arete
     * @param b une arete 
     */
    void echanger(arete *a, arete *b);
    
    /**
     * @brief Produit un tas max à partir d’un tableau d’entrée d'arêtes non-ordonné
     * @param tas le tas à constuire
     * @param tab le tableau non-ordonné de base
     * @param taille le nombre d’éléments du tas rangés dans le tableau tas->A
     * @param longueur le nombre d’éléments du tableau tas->A
     */
    void construire_tas_max(tas *tas, arete *tab, int longueur);

    /**
     * @brief entasse l’élément d’indice i afin de 
     * rétablir la propriété de tas max
     * TEMPS D'EXECUTION O(lg n)
     * @param A un tableau de Tas
     * @param i l'indice de l'élément i a entasser
     */
    void entasser_max(tas *tas, int i);

    /**
     * @brief fonction qui exécute le tri par tas
     * TEMPS D'EXECUTION O(n lg n)
     * @param A un tas
     */
    void tri_par_tas(tas *A, arete *tab, int longueur, int bool_print);

    /**
     * @brief Détruit les ressources d'un tas
     * @param A un tas
     */
    void detruire_tas(tas *tas);


#endif