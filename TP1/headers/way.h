#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#ifndef WAY_H
#define WAY_H

#define UP 3
#define DOWN 4
#define LEFT 2
#define RIGHT 5


// Criar a estrutura neste arquivo
// Convencao: usar snake case
typedef struct field{
    char *direction;
    char *visited;
}field;

typedef struct type_cell *pointer_type;
typedef struct type_cell{
    field field;
    pointer_type next;
} type_cell;

typedef struct {
    pointer_type first, last;
} list_type;

void make_list_empty(list_type *list);
void insert(field field, list_type *tlist);
void print_way(list_type *list, int n);

#endif