#include "way.h"
#ifndef MAP_H
#define MAP_H

typedef struct map
{
    int width, height;
    char **map;
} map;

typedef struct data
{
    int number_of_recursions;
} data;

void initialize_map(map *map, int width, int height);
void insert_line(map *map, int position, char *line);
// Função para fazer a movimentação do fazendeiro, necessidade de definir os parâmetros
int movement();
void initialize_data(data *data);
void print_field();

#endif