#include "../headers/map.h"

void initializeMap(map *map, int width, int height)
{
    map->width = width;
    map->height = height;

    map->map = (int **)malloc(sizeof(int *) * map->height);
    for (int i = 0; i < map->height; i++)
    {
        // alocar a quantidade de colunas de cada linha
        map->map[i] = (int *)malloc(sizeof(int *) * map->width);
    }  
}

void insertValue(map *map,  int width, int height, int value){
    map->map[width][height] = value;
}

void printMap(map *map){
    printf("J = %d ; I = %d \n",map->width, map->height);

    for (int i = 0; i < map->height; i++)
    {
        for (int ii = 0; ii < map->width; ii++)
        {
            printf("%d ",map->map[i][ii]);
        }
        printf("\n");
    }
}

int gridmap(int width, int height, int *memo)
{
    //int *key = width;
    // if (in(memo, sizeof(memo), key)) return memo[key];
    // if (width == 1 && height == 1) return 1;
    // if (width == 0 || height == 0) return 0;

    // memo[key] = gridmap(width + 1, height, memo) + gridmap(width, height + 1, memo);
    // return memo[key];
    printf("qlqr coisa");
}

int in(int *array, int length, int value)
{
    for (int i = 0; i < length; i++)
    {
        if (array[i] == value) return TRUE;
    }
    return FALSE;
}
