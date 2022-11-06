#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fibonnaci.h"
#ifndef MAP_H
#define MAP_H

#define TRUE 1
#define FALSE 0

typedef struct Map
{
    int width, height;
    int **map;
} Map;

typedef struct data
{
    int number_of_recursions;
} data;

Map* initialize_map(int width, int height);
void insert_line(Map *map, int position, int *line);
void initialize_data(data *data);
void print_field(Map *map);
int beginMovement(Map *map, data *data, int **track, int* index);
int movement(Map *map, data *data, int **track, int *actualPosition, int* index, int *sequence);

#endif