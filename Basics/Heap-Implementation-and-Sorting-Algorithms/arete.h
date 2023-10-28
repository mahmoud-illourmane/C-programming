#ifndef ARETE_H
#define ARETE_H

    /**
     * @brief structure qui represnte une arête
     */
    typedef struct arete_t{
        int sommet_origine;
        int sommet_extrimite;
        int poids;
    }arete;
    
    /**
     * @brief fonction qui initialise une arête
     * @param o sommet d'origine
     * @param e sommet d'extrémité
     * @param p son poids
     */
    void init_arete(int o, int e, int p);
    
#endif