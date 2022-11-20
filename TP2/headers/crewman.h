#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#ifndef CREWMAN_H
#define CREWMAN_H

#define TRUE 1;
#define FALSE 0;

typedef struct travel
{
    int *memo;
    int **map;
    int width, height;
}travel;

void initializeTrip(travel *travel, int width, int height);
void insertLine(travel *travel, int position, int *line);
void printGrid(travel *travel);
int gridTravel(int width, int height, int *memo);
int in(int *array, int length, int value);

#endif