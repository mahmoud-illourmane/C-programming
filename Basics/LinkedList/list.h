#ifndef LIST_H
#define LIST_H

#include "cell.h"

/**
 * @brief Structure representing a doubly linked list
 */
typedef struct list_t {
    cell *head;
} list;

/**
 * @brief Initializes an empty list
 * @param l Pointer to a list
 */
void init_list(list *l);

/**
 * @brief Creates a cell and inserts it into the list
 * @param l Pointer to a list
 * @param val Value to insert
 */
void insert_list(list *l, int val);

/**
 * @brief Inserts a cell at the head of the list
 * @param l Pointer to a list
 * @param c Cell to insert
 */
void insert(list *l, cell *c);

/**
 * @brief Searches for an element in a list using an identifier
 * @param l Pointer to a list
 * @param id Value to search for
 * @return cell* OR NULL
 */
cell* search_list(list *l, int id);

/**
 * @brief Displays a list
 * @param l Pointer to a list
 */
void display_list(list *l);

/**
 * @brief Removes the first element of a list (statically allocated cell)
 * @param l Pointer to a list
 */
void remove_start_list_static(list *l);

/**
 * @brief Removes the first element of a list (dynamically allocated cell)
 * @param l Pointer to a list
 */
void remove_start_list(list *l);

/**
 * @brief Removes the cell specified in the parameter (statically allocated cell)
 * @param l Pointer to a list
 * @param c Pointer to a cell
 */
void remove_cell_list_static(list *l, cell *c);

/**
 * @brief Removes the dynamically allocated cell specified in the parameter
 * @param l Pointer to a list
 * @param c Pointer to a cell
 */
void remove_cell_list(list *l, cell *c);

/**
 * @brief Removes the entire list
 * @param l Pointer to a list
 */
void destroy_list(list *l);

#endif
