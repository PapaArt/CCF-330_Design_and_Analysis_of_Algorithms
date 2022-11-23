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

int gridMap(map *map)
{
    int memo[10][10];
    memo[0][0] = map->map[0][0];

    // Init the first row of memo
    for (int j = 1; j < map->width; j++){
        memo[0][j] = memo[0][j-1] + map->map[0][j];
    }
    
    for (int i = 1; i < map->height; i++){
        memo[i][0] = memo[i-1][0] + map->map[i][0];
    }

    for (int i = 1; i < map->height; i++)
    {
        for (int j = 1; j < map->width; j++)
        {
            memo[i][j] = min(memo[i-1][j], memo[i][j-1]) + map->map[i][j];
        }
    }    
    
    printf("map height -> %d\nmap width -> %d\n", (map->height-1), (map->width-1));

    return memo[map->height-1][map->width-1];  
}

int min(int a, int b)
{
    return (a > b) ? b : a;
}