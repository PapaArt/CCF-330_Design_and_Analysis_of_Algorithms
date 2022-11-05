#include "../headers/map.h"

void initialize_map(map *map, int width, int height)
{
    map->height = height;
    map->width = width;

    map->map = (char **)malloc(sizeof(char *) * width);
    for (int i = 0; i < width; i++)
    {
        map->map[i] = (char *)malloc(sizeof(char *) * height);
    }
}

void insert_line(map *map, int position, char *line)
{
    for (int i = 0; i < map->width; i++)
    {
        for (int j = 0; j < map->height; j++)
        {
            map->map[position][j] = line[j];
        }
    }
}

void initialize_data(data *data)
{
    data->number_of_recursions = -1;
}


// Função para fazer a movimentação do fazendeiro, necessidade de definir os parâmetros

int movement(map *map, data *data, int **track, int* actualPosition, int n, int* git ) {

    return movement(map, data, track, [1, 2], n+1);
}
/*
ARTUR
int movement(map *map, int direction, data *data, int line, int column)
{
    if (direction == LEFT)
    {
        printf("LEFT\n");
        direction = UP;
        return movement(map, LEFT, data, line, column - 1);
    }   
    else if (direction == RIGHT)
    {    
        printf("RIGHT\n");
        direction = DOWN;
        return movement(map, RIGHT, data, line, column + 1);
    }
    else if (direction == UP)
    {
        printf("UP\n");
        direction = RIGHT;
        return movement(map, UP, data, line - 1, column);
    }
    else if (direction == DOWN)
    {
        printf("DOWN\n");
        direction = LEFT;
        return movement(map, DOWN, data, line + 1, column);
    }
}
*/

// int already_visited(map *map, int *direction)
// {
//     switch (*direction)
//     {
//     case UP:
//         return TRUE;
//         break;
//     case DOWN:
//         return TRUE;
//         break;
//     case RIGHT:
//         return TRUE;
//         break;
//     case LEFT:
//         return TRUE;
//         break;
//     default:
//         return FALSE;
//         break;
//     }
// }

// void results(map *map, int line, int column)
// {
     
// }

void print_field(map *map)
{
	for (int i = 0; i < map->width; i++)
    {
        for (int j = 0; j < map->height; j++)
        {
            printf("%c", map->map[i][j]);
        }
    }
    
}