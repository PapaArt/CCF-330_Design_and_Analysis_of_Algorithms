#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef MAP_H
#define MAP_H
#define MAX 2147483647

typedef struct map
{
    int **map;
    int width, height;
}map;

void initializeMap(map *map, int width, int height);
int **initializeMemo(map *map);
void insertValue(map *map,  int width, int height, int value);
void printMap(map *map);
void cleanMap(map *map);
int gridMap(map *map, int **memo);
int numberWays(map *map, int **memo, int x, int y, int count, int before);
int min(int a, int b);

#endif