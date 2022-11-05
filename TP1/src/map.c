#include "../headers/map.h"

void initialize_map(map *map, int width, int height) {
    map->height = height;
    map->width = width;

    map->map = (char **)malloc(sizeof(char *) * width);
    for (int i = 0; i < width; i++) {
        map->map[i] = (char *)malloc(sizeof(char *) * height);
    }
}

void insert_line(map *map, int position, char *line) {
    for (int i = 0; i < map->width; i++) {
        for (int j = 0; j < map->height; j++) {
            map->map[position][j] = line[j];
        }
    }
}

void initialize_data(data *data) {
    data->number_of_recursions = -1;
}

int **beginMovement(map *map, data *data) {
    int result, flag = 0;
    int n = map->height * map->width;
    int **track = (int **)malloc(n * sizeof(int *));
    int *sequence;
    fibonnaci(sequence, n);
    for (int i = 0; i < map->width; i++) {
        int actualPosition = {0, i};
        result = movement(map, data, track, actualPosition, 0, sequence);
        if (result) break;
    }
    return track;
}

// Função para fazer a movimentação do fazendeiro, necessidade de definir os parâmetros

int movement(map *map, data *data, int **track, int *actualPosition, int index, int *sequence) {
    int result;
    int trackOk[2];
    int nextPosition[2];

    if (map->map[actualPosition[0]][actualPosition[1]] == sequence[index] + '0') {
        trackOk[0] = actualPosition[0];
        trackOk[1] = actualPosition[1];
        track[index] = trackOk;
        if (actualPosition[0] == map->height) return 1;

        if (actualPosition[0] > 0) //movement para esquerda
        {
            nextPosition[0] = actualPosition[0]-1;
            nextPosition[1] = actualPosition[1];
            result = movement(map, data, track, nextPosition, index+1, sequence);
            if (result) return 1;
        }

        if (actualPosition[0] < map->width-1) //movement para direita
        {
            nextPosition[0] = actualPosition[0]+1;
            nextPosition[1] = actualPosition[1];
            result = movement(map, data, track, nextPosition, index+1, sequence);
            if (result) return 1;
        }

        if (actualPosition[1] > 0) //movement para cima
        {  
            nextPosition[0] = actualPosition[0];
            nextPosition[1] = actualPosition[1]-1;
            result = movement(map, data, track, nextPosition, index+1, sequence);
            if (result) return 1;
        }

        if (actualPosition[0] < map->height-1) //movement para baixo
        {
            nextPosition[0] = actualPosition[0];
            nextPosition[1] = actualPosition[1]+1;
            result = movement(map, data, track, nextPosition, index+1, sequence);
            if (result) return 1;
        }
    
    return 0;
}

// ARTHUR
// int movement(map *map, int direction, data *data, int line, int column)
// {
//     if (direction == LEFT && !(already_visited(map, &direction)))
//     {

//         return movement(map, LEFT, data, line, column - 1) - movement(map, LEFT, data, line, column - 2);
//     }
//     else if (direction == RIGHT && !(already_visited(map, &direction)))
//     {

//         return movement(map, RIGHT, data, line, column + 1) - movement(map, RIGHT, data, line, column + 2);
//     }
//     else if (direction == UP && !(already_visited(map, &direction)))
//     {
//         return movement(map, UP, data, line - 1, column) - movement(map, UP, data, line - 2, column);
//     }
//     else if (direction == DOWN && !(already_visited(map, &direction)))
//     {
//         return movement(map, DOWN, data, line + 1, column) - movement(map, DOWN, data, line + 2, column);
//     }
// }

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

void print_field(map *map) {
    for (int i = 0; i < map->width; i++) {
        for (int j = 0; j < map->height; j++) {
            printf("%c", map->map[i][j]);
        }
    }
}