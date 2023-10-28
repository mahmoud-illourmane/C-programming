#include<time.h>
#include"table_hachage.h"
#define MAX_MOT 50

/**
  * @author MAHMOUD ILLOURMANE
  * 2021-2022
  * @brief Hand that reads the contents of a file pass
  * in argument and counts the number of different words and stores the words
  * different contents of the file in a hash table.
  * @param argc number of arguments received
  * @param argv received argument array
  * @return int 0 if everything went well
  */
int main(int argc, const char *argv[]){
    char buffer[MAX_MOT];
    table_hachage t;
    cellule *tmp;
    FILE *f;
    int nombre_de_mot = 0;
    int nombre_de_mot_fichier = 0;
    int time_spent;

    //Checking the text file as argument
    if( argv[1] == NULL ){
        fprintf(stderr, "You must enter the file name as an argument.\n");
        exit(EXIT_FAILURE);
    }

    //Opening the file
    f = fopen(argv[1], "r");
    if( f == NULL ){ 
        fprintf(stderr, "Error opening file.\n");
        exit(EXIT_FAILURE);
    }

    //Initialization of the hash table
    initialiser_table_hachage(&t, 11);

    //Start of the timer
    clock_t begin = clock();
    while( fscanf(f, "%s", buffer) != EOF ){
        nombre_de_mot_fichier ++;
        if( strlen(buffer) < 27 ){
            tmp = rechercher_hachage(&t, buffer);
            if( tmp == NULL ){
                inserer_hachage(&t, buffer);
            }
        }
    }
    clock_t end = clock();
    //End of timer
    time_spent = (int)(end - begin) / CLOCKS_PER_SEC;

    nombre_de_mot = compter_table_hachage(&t);
    
    printf("-->File: %s\n -The number of words in the file is %d\n -The number of different words in the file is %d.\n -The elapsed time is: %ds\n", argv[1],  nombre_de_mot_fichier, nombre_de_mot, time_spent);

    detruire_table_hachage(&t);
    printf("\n");
    return EXIT_SUCCESS;
}