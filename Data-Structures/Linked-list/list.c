#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void init_list(list *l) {
    l->head = NULL;
}

void insert(list *l, cell *c) {
    c->successor = l->head;

    if (l->head != NULL)
        l->head->predecessor = c;

    l->head = c;
    c->predecessor = NULL;
}

void insert_list(list *l, int val) {
    cell *c = (cell *)malloc(sizeof(cell));
    if (c == NULL) {
        printf("Dynamic allocation error");
        exit(EXIT_FAILURE);
    }
    init_cell(c, val);
    insert(l, c);
}

void display_list(list *l) {
    if (l->head != NULL) {
        cell *current = l->head;

        printf("[ ");
        while (current != NULL) {
            printf("%d ", current->top);
            current = current->successor;
        }
        printf("]\n");
    } else {
        printf("Empty list: NULL\n");
    }
}

cell* search_list(list *l, int id) {
    cell *x = l->head;
    while (x != NULL && x->top != id) {
        x = x->successor;
    }
    return x;
}

void remove_start_list_static(list *l) {
    cell *tmp;

    if (l->head == NULL) {
        printf("[ empty ]\nThe list is empty, nothing to remove.\n");
        exit(EXIT_FAILURE);
    }

    tmp = l->head;
    if (tmp == NULL)
        exit(EXIT_FAILURE);

    l->head = tmp->successor;
    if (l->head != NULL)
        l->head->predecessor = NULL;
}

void remove_start_list(list *l) {
    cell *tmp = l->head;

    if (l->head == NULL) {
        printf("[ empty ]\nThe list is empty, nothing to remove.\n");
    } else {
        l->head = tmp->successor;
        if (l->head)
            l->head->predecessor = NULL;

        free(tmp);
        tmp = NULL;
    }
}

void remove_cell_list_static(list *l, cell *c) {
    if (c->predecessor != NULL) {
        c->predecessor->successor = c->successor;
    } else {
        l->head = c->successor;
    }

    if (c->successor != NULL) {
        c->successor->predecessor = c->predecessor;
    }

    c->successor = NULL;
    c->predecessor = NULL;
}

void remove_cell_list(list *l, cell *c) {
    if (l->head == NULL) {
        printf("The list is empty.\n");
    }

    if (c->predecessor != NULL) {
        c->predecessor->successor = c->successor;
    } else {
        l->head = c->successor;
    }

    if (c->successor != NULL) {
        c->successor->predecessor = c->predecessor;
    }

    free(c);
    c->successor = NULL;
    c->predecessor = NULL;
}

void destroy_list(list *l) {
    cell *tmp;
    cell *current = l->head;

    while (current) {
        tmp = current;
        current = current->successor;
        free(tmp);
        tmp = NULL;
    }

    l->head = NULL;
    printf("List cleared\n");
}
