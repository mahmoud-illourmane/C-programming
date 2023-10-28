#ifndef CELL_H
#define CELL_H

/**
 * @brief Structure representing a cell
 */
typedef struct cell_t {
    int top;
    struct cell_t *successor;
    struct cell_t *predecessor;
} cell;

// Function prototypes
/**
 * @brief Function that initializes a cell
 * @param c Pointer to a cell
 * @param s The value to insert
 */
void init_cell(cell *c, int s);

/**
 * @brief Function that displays a cell
 * @param c Pointer to a cell
 */
void display_cell(cell *c);

#endif
