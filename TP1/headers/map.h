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

typedef struct Data
{
    int number_of_recursions;
} Data;

void initializeMap(Map** map, int width, int height);
void initializeData(Data *data);
void printField(Map *map);
int beginMovement(Map *map, Data *data);
int movement(Map *map, Data *data, int **track, int *actualPosition, int* index, int *sequence);
int inTracking(int **track, int* position, int *index);
void printTrack(int** track, int *index);

#endif