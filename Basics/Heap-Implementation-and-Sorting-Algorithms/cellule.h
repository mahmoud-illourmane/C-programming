#ifndef CELLULE_H
#define CELLULE_H
    #define FALSE 1
    #define TRUE 0
    
    /**
     * @brief Structure qui représente
     * une cellule
     */
    typedef struct cellule_t{
        int sommet;
        int poids;
        struct cellule_t *succ;
        struct cellule_t *pred;
    }cellule;

    //Prototype de fonctions
    /**
     * @brief fonction qui initialise une cellule
     * @param c une cellule
     * @param s la valeur a insérer 
     */
    void init_cellule(cellule *c, int s);

    /**
     * @brief fonction qui affiche une cellule
     * @param c une cellule
     */
    void affiche_cellule(cellule *c);
#endif