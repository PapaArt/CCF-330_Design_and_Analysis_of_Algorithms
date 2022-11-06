#include "../headers/map.h"

void initialize_map(Map *map, int width, int height) {
    map->height = height;
    map->width = width;

    map->map = (char **)malloc(sizeof(char *) * height);
    for (int i = 0; i < height; i++) {
        map->map[i] = (char *)malloc(sizeof(char *) * width);
    }
}

void insert_line(Map *map, int position, char *line) {
    for (int i = 0; i < map->width; i++) {
        for (int j = 0; j < map->height; j++) {
            map->map[position][j] = line[j];
        }
    }
}

void print_field(Map *map) {
    for (int i = 0; i < map->width; i++) {
        for (int j = 0; j < map->height; j++) {
            printf("%c", map->map[i][j]);
        }
    }
}

void initialize_data(data *data) {
    data->number_of_recursions = -1;
}

int beginMovement(Map *map, data *data, int **track, int* index) {
    int result;
    int n = map->height * map->width;
    int *sequence;
    int actualPosition[2];
    actualPosition[0] = 0;
    fibonnaci(sequence, n);
    for (int i = 0; i < map->width; i++) {
        actualPosition[1] = i;
        result = movement(map, data, track, actualPosition, index, sequence);
        if (result) break;
    }
    return result;
}

int movement(Map *map, data *data, int **track, int *actualPosition, int* index, int *sequence) {
    int result;
    int trackOk[2];
    int nextPosition[2];

    if (map->map[actualPosition[0]][actualPosition[1]] == sequence[(*index)] + '0') {
        trackOk[0] = actualPosition[0];
        trackOk[1] = actualPosition[1];
        track[(*index)] = trackOk;
        (*index) = (*index) + 1;
        if (actualPosition[0] == map->height) return 1;

        if (actualPosition[0] > 0) //movement para esquerda
        {
            nextPosition[0] = actualPosition[0]-1;
            nextPosition[1] = actualPosition[1];
            result = movement(map, data, track, nextPosition, index, sequence);
            if (result) return 1;
        }

        if (actualPosition[0] < map->width-1) //movement para direita
        {
            nextPosition[0] = actualPosition[0]+1;
            nextPosition[1] = actualPosition[1];
            result = movement(map, data, track, nextPosition, index, sequence);
            if (result) return 1;
        }

        if (actualPosition[1] > 0) //movement para cima
        {  
            nextPosition[0] = actualPosition[0];
            nextPosition[1] = actualPosition[1]-1;
            result = movement(map, data, track, nextPosition, index, sequence);
            if (result) return 1;
        }

        if (actualPosition[0] < map->height-1) //movement para baixo
        {
            nextPosition[0] = actualPosition[0];
            nextPosition[1] = actualPosition[1]+1;
            result = movement(map, data, track, nextPosition, index, sequence);
            if (result) return 1;
        }
        (*index) = (*index) - 1;
    }

    return 0;
}