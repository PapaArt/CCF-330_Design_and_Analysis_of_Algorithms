#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#ifndef MAP_H
#define MAP_H

#define TRUE 1;
#define FALSE 0;

typedef struct map
{
    int **map;
    int width, height;
}map;

void initializeMap(map *map, int width, int height);
void insertValue(map *map,  int width, int height, int value);
void printMap(map *map);
void cleanMap(map *map);

#endif