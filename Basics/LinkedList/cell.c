#include "cell.h"
#include <stdio.h>
#include <stdlib.h>

void init_cell(cell *c, int s) {
    c->top = s;
    c->predecessor = NULL;
    c->successor = NULL;
}

void display_cell(cell *c) {
    if (c != NULL)
        printf("%d\n", c->top);
    else {
        printf("Empty cell: c = NULL\n");
    }
}
