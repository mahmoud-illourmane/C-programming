#ifndef CELLULE_H
#define CELLULE_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

    /**
      * @brief Structure that represents
      * a string cell
      */
    typedef struct cellule_t{
        char chaine[27];
        struct cellule_t *succ;
        struct cellule_t *pred;
    }cellule;

    //Prototype of functions

    /**
      * @brief function that initializes a cell
      * @param c a cell
      * @param s the string to insert
      */
    void init_cellule(cellule *c, char *ch);

    /**
      * @brief function that displays a cell
      * @param c a cell
      */
    void affiche_cellule(cellule *c);
    
#endif