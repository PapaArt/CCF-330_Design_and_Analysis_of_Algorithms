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

int **initializeMemo(map *map)
{
    int **memo = (int **)malloc(sizeof(int *) * map->height);
    for (int i = 0; i < map->height; i++)
    {
        // alocar a quantidade de colunas de cada linha
        memo[i] = (int *)malloc(sizeof(int *) * map->width);
    }

    for (int i = 0; i < map->height; i++)
    {
        for (int j = 0; j < map->width; j++)
        {
            memo[i][j] = 0;
        }
    }

    return memo;
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

int gridMap(map *map, int **memo)
{   
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

    return memo[map->height-1][map->width-1];  
}

int numberWays(map *map, int **memo, int x, int y, int count, int before)
{
    if (x == (map->height - 1) && y == (map->width - 1))
    {
        return ++count;
    }
    else if (x == (map->height - 1) && y != (map->width - 1) && memo[x][y] >= before && memo[x][y] < memo[map->height-1][map->width-1])
    {
        count = numberWays(map, memo, x, y+1, count, memo[x][y]) + count;
    }
    else if (x != (map->height - 1) && y == (map->width - 1) && memo[x][y] >= before && memo[x][y] < memo[map->height-1][map->width-1])
    {
        count = numberWays(map, memo, x+1, y, count, memo[x][y]) + count;   
    }
    else if (memo[x][y] >= before && memo[x][y] < memo[map->height-1][map->width-1])
    {
        count = numberWays(map, memo, x+1, y, count, memo[x][y]) + numberWays(map, memo, x, y+1, count, memo[x][y]) + count;
    }
    else
    {return 0;}
}

int min(int a, int b)
{
    return (a > b) ? b : a;
}
