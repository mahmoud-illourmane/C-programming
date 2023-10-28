#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h> 
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h> 

#include"table_hachage.h"

int main(int argc, const char *argv[]){
    table_hachage t;
    cellule *tmp;   
    char chaine[50];
    int choix = -1;
    int err;

    //Initialisation de la table de hachage.
    initialiser_table_hachage(&t, HASHSIZE);

    //Choix d'opérations possible
    while(choix != 0){
        printf("================\n1)-To add an element type: 1\n2)-To delete an element type: 2\n3)-To display the hash table type: 3\n4)-To search for an element type: 4\n5)-To delete the table hash table type: 5\n6)-To count the number of elements present in the hash table type: 6\n0)-To exit type: 0\n==============\n");
        
        err = scanf("%d", &choix);
        if(err == -1){ fprintf(stderr, "Error during entry.\n"); }
        printf("\n");

        switch (choix){
            case 1:
                printf("Enter the character string to insert:");
                err = scanf("%s", chaine);
                if(err == -1){ perror("Error during entry.\n"); }
                inserer_hachage(&t, chaine);
                printf("\n");
            break;

            case 2:
                printf("Choose the element to delete in the hash table:\n");
                afficher_table_hachage(&t);
                printf("\nEnter the element to delete:");
                err = scanf("%s", chaine);
                if(err == -1){ perror("Error during entry.\n"); }
                supprimer_hachage(&t, chaine);
                afficher_table_hachage(&t);
                printf("\n");
            break;

            case 3:
                printf("Show hash table:\n");
                afficher_table_hachage(&t);
                printf("\n");
            break;

            case 4:
                afficher_table_hachage(&t);
                printf("\n");
                printf("Enter the element to search for:");
                err = scanf("%s", chaine);
                if(err == -1){ fprintf(stderr, "Error during entry.\n"); }
                tmp = rechercher_hachage(&t, chaine);
                if(tmp == NULL){ printf("The item was not found.\n\n"); }
                else{ printf("The element is present in the hash table.\n\n"); }
            break;

            case 5:
                detruire_table_hachage(&t);
                printf("\n");
                afficher_table_hachage(&t);
            break;

            case 6:
                printf("The number of elements present in the hash table is [%d] element(s).\n\n", compter_table_hachage(&t) );
            break;

            case 0:
                printf("PROGRAM EXIT\n");
                detruire_table_hachage(&t);
                exit(EXIT_SUCCESS);
            break;
            
            default:
                printf("PROGRAM EXIT\n");
                detruire_table_hachage(&t);
                exit(EXIT_SUCCESS);
            break;
        }
    }

    detruire_table_hachage(&t);
    return EXIT_SUCCESS;
}