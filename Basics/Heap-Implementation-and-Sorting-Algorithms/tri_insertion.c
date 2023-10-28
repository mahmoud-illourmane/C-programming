#include"tri_insertion.h"


void TRI_INSERTION(arete *tab, int taille){
    int i = 0, j = 0, cle = 0;
    arete cle_arete;

    for (j = 1; j < taille ; j++){
        cle = tab[j].poids;
        cle_arete = tab[j];
        i = j-1;
        while(i > -1 && tab[i].poids > cle){
            tab[i+1] = tab[i];
            i--;
        }
        tab[i+1] = cle_arete;
    }
}
