#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fibonnaci.h"
#ifndef MAP_H
#define MAP_H

#define UP 3
#define DOWN 4
#define LEFT 2
#define RIGHT 5

#define TRUE 1
#define FALSE 0

typedef struct Map
{
    int width, height;
    char **map;
} Map;

typedef struct data
{
    int number_of_recursions;
} data;

void initialize_map(Map *map, int width, int height);
void insert_line(Map *map, int position, char *line);
//int movement(map *map, data *data, int **track, int* actualPosition);
// Função para fazer a movimentação do fazendeiro, necessidade de definir os parâmetros
int beginMovement(Map *map, data *data, int **track);
int movement(Map *map, data *data, int **track, int *actualPosition, int index, int *sequence);
int already_visited(Map *map, int *direction);
void results(Map *map, int line, int column); 
void initialize_data(data *data);
void print_field(Map *map);

#endif