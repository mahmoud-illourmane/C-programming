#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

#include"graphe.h"
#include"file.h"

int main(int argc, const char *argv[]){
    file_t f;
    sommet s1, s2, s3;
    sommet *s4;
    int a;

    init_sommet_file(&s1, 36);
    init_sommet_file(&s2, 78);
    init_sommet_file(&s3, 45);

    init_file(&f, 5);

    enfiler(&f, s1);
    enfiler(&f, s2);
    enfiler(&f, s3);
    
    //afficher_file(&f);
    s4 = defiler(&f);
    printf("sommet : %d\n", s4->valeur);

    detruire_file(&f);
    printf("\n");
    return EXIT_SUCCESS;
}
