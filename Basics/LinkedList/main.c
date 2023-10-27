#include <stdio.h> // Standard Input and Output Library
#include <stdlib.h> // Standard Library
#include <fcntl.h> // File Control Library (for functions like create, open, etc.)
#include <sys/stat.h> // System-specific Data Structures - File Status
#include <sys/types.h> // System Data Types
#include <unistd.h> // POSIX Operating System API (for file close)

#include "list.h"

int main(int argc, const char *argv[]) {
    list l;
    cell *tmp;
    int val = -1;
    int choice = -1;
    int err;

    // Initialize the list
    init_list(&l);

    // Choose possible operations
    while (choice != 0) {
        printf("================\nTo add an element, enter: 1\nTo remove the last inserted element, enter: 2\nTo display the list, enter: 3\nTo remove an element, enter: 4\nTo clear the list, enter: 5\nTo exit, enter: 0\n================\n");
        
        err = scanf("%d", &choice);
        if (err != 1) {
            fprintf(stderr, "Error: Please enter a valid integer.\n");
            destroy_list(&l);
            exit(EXIT_FAILURE);
        }
        else if (err == -1) {
            perror("Error during scanf.\n");
            destroy_list(&l);
            exit(EXIT_FAILURE);
        }

        printf("\n\n");

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                err = scanf("%d", &val);
                if (err != 1) {
                    fprintf(stderr, "Error: Please enter a valid integer.\n");
                    destroy_list(&l);
                    exit(EXIT_FAILURE);
                }
                else if (err == -1) {
                    perror("Error during scanf.\n");
                    destroy_list(&l);
                    exit(EXIT_FAILURE);
                }
                insert_list(&l, val);
                printf("\n");
            break;

            case 2:
                printf("Removing the last inserted element.\n");
                remove_start_list(&l);
                display_list(&l);
                printf("\n");
            break;

            case 3:
                printf("Displaying the list:\n");
                display_list(&l);
                printf("\n");
            break;

            case 4:
                display_list(&l);
                printf("\n");
                printf("Enter the element to remove: ");
                err = scanf("%d", &val);
                if (err != 1) {
                    fprintf(stderr, "Error: Please enter a valid integer.\n");
                    destroy_list(&l);
                    exit(EXIT_FAILURE);
                }
                else if (err == -1) {
                    perror("Error during scanf.\n");
                    destroy_list(&l);
                    exit(EXIT_FAILURE);
                }
                tmp = search_list(&l, val);
                if(tmp != NULL)
                    remove_cell_list(&l, tmp);
                else
                    printf("The list are empty.\n");
                    
            break;

            case 5:
                destroy_list(&l);
                display_list(&l);
            break;

            case 0:
                printf("PROGRAM EXIT\n");
                destroy_list(&l);
                exit(EXIT_SUCCESS);
            break;

            default:
                printf("INVALID COMMAND\n");
            break;
        }
    }

    return EXIT_SUCCESS;
}
