#ifndef TABLE_HACHAGE_H
#define TABLE_HACHAGE_H
#define HASHSIZE 11
#include<fcntl.h> // pour les fonctions create, open...
#include<unistd.h> // pour le close de fichier
#include<sys/stat.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include"liste.h"

    /**
      * @author MAHMOUD ILLOURMANE
      * 2021-2022
      * Implementation of a hash table by resolving collisions by chaining.
      * @version 1.0
      */

    /**
      * @brief Structure that represents a hash table
      * t the table where we will hash the character strings
      * m the size of the array, it must be a prime number not close to a power of 2
      */
    typedef struct table_h{
        liste *t;
        int m;
    }table_hachage;

    /**
      * @brief Initializes the hash table
      * allocates array t
      * EXECUTION TIME O(1)
      * @param t a hash table
      * @param m the size of the array t
      */
    void initialiser_table_hachage(table_hachage *t, int m);

    /**
      * @brief function which converts a string into
      * integer, and returns its unsigned long integer representation.
      * EXECUTION TIME O(String size)
      * @param string
      * @return unsigned long long
      */
    unsigned long long convertir_ch_entier(char *chaine); 
    
    /**
      * @brief function which determines the index k, to do the insertion in the
      * hash table, using the division method.
      * EXECUTION TIME O(1)
      * @param k the string converted to integer
      * @param m the size of the hash table array
      * @return int
      */
    int hachage(unsigned long long k, int m);

    /**
      * @brief function that inserts a cell into
      * a hash table.
      * EXECUTION TIME O(1)
      */
    void inserer_hachage(table_hachage *t, char *chaine);

    /**
      * @brief searches for a string in a hash table and
      * returns either a pointer to the cell that contains the string, or NULL.
      * EXECUTION TIME O(N)
      * @param t a hash table
      * @param string a string of characters
      * @return cell*
      */
    cellule* rechercher_hachage(table_hachage *t, char *chaine);

    /**
      * @brief takes as parameter a pointer to a cell of a table
      * hash and remove this cell from the table.
      * EXECUTION TIME O(N)
      * @param t a hash table.
      * @param string a string of characters.
      */
    void supprimer_hachage(table_hachage *t, char *chaine);

    /**
      * @brief Function that counts the number of elements
      * present in a hash table.
      * EXECUTION TIME O(N)
      * @param t a hash table.
      * @return int the number of elements present in the hash table.
      */
    int compter_table_hachage(table_hachage *t);

    /**
      * @brief Displays the contents of a hash table
      * EXECUTION TIME O(N)
      * @param t a hash table.
      */
    void afficher_table_hachage(table_hachage *t);

    /**
      * @brief Frees the memory resources of a table
      *hash.
      * EXECUTION TIME O(1)
      * @param t a hash table
      */
    void detruire_table_hachage(table_hachage *t);
#endif