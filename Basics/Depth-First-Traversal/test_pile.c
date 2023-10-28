#include"stdio.h"
#include"stdlib.h"

#include"pile.h"

int main(int argc, const char *argv[]){
    int t, choix, val;
    pile p;

    printf("Entrez la taille de la pile : ");
    scanf("%d", &t);

    init_pile(&p, t);

    while (choix != -1){
        printf("MENU DES OPERATIONS :\n");
        printf("  Pour empiler tapez 1.\n");
        printf("  Pour dépiler tapez 2.\n");
        printf("  Pour afficher le sommet de la pile tapez 3.\n");
        scanf("%d", &choix);

        switch (choix){
            case 1:
                printf("Entrez la valeur à empiler : ");
                scanf("%d", &val);
                empiler(&p, val);
            break;
            
            case 2:
                printf("La valeur dépiler : %d\n", depiler(&p));
            break;

            case 3:
                printf("Le sommet de la pile : %d\n", sommet(&p));
            break;

            default:
                choix = -1;
            break;
        }
    }
    
    detruire_pile(&p);
    printf("\n");
    return EXIT_SUCCESS;
}
