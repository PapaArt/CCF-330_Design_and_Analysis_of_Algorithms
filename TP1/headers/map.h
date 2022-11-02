#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#ifndef MAP_H
#define MAP_H

#define UP 3
#define DOWN 4
#define LEFT 2
#define RIGHT 5

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
int movement(map *map, data *data, int **track, int* actualPosition);
void initialize_data(data *data);
void print_field();

#endif