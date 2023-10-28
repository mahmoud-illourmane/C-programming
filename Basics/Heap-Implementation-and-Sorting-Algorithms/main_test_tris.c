#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<time.h>

#include"graphe.h"
#include"tri_insertion.h"
#include"tas.h"

int main(int argc, const char *argv[]){
    tas tas1;
    arete A[100000];
    // pour stocker le temps d'exécution du code
    double time_spent = 0.0;
    double time_spent_2 = 0.0;

    tas1.A = (arete *) malloc(sizeof(arete) * 100000);
    
    srand(time(NULL));
    for (int i = 0; i < 100000; i++){
        A[i].poids = rand() % (256 + 1);
        A[i].sommet_origine = 0;
        A[i].sommet_extrimite = 0;
    }
    
    // for (int i = 0; i < 100000; i++){
    //     tas1.A[i].poids = A[i].poids;
    //     tas1.A[i].sommet_origine = 0;
    //     tas1.A[i].sommet_extrimite = 0;
    // }

    clock_t begin = clock();
    tri_par_tas(&tas1, A, 100000, FALSE);
    clock_t end = clock();

    // calcule le temps écoulé en trouvant la différence (end - begin) et
    // divisant la différence par CLOCKS_PER_SEC pour convertir en secondes
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The elapsed time with heap sort is %f seconds\n", time_spent);
    // printf("%d, %d", tas1.A[0].poids, tas1.A[100000].poids);
    
    clock_t begin_2 = clock();
    TRI_INSERTION(A, 100000);
    clock_t end_2 = clock();
    time_spent_2 += (double)(end_2 - begin_2) / CLOCKS_PER_SEC;
    printf("The elapsed time with insertion sort is %f seconds\n", time_spent_2);

    printf("\n");
    detruire_tas(&tas1);
    return EXIT_SUCCESS;
}
