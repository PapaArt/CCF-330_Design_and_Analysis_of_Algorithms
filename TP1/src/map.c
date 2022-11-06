#include "../headers/map.h"

Map* initialize_map(int width, int height) {
    Map *map = (Map*)malloc(sizeof(Map));
    map->height = height;
    map->width = width;

    map->map = (int **)malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
        map->map[i] = (int *)malloc(width * sizeof(int));
    }
    return map;
}

void print_field(Map *map) {
    for (int i = 0; i < map->height; i++) {
        for (int j = 0; j < map->width; j++) {
            printf("%d ", map->map[i][j]);
        }
        printf("\n");
    }
}

void initialize_data(Data *data) {
    data->number_of_recursions = -1;
}

int beginMovement(Map *map, Data *data, int **track, int* index) {
    int result = FALSE;
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

int inTracking(int **track, int* position, int *index) {
    for (int i = 0; i < (*index)-1; i++) {
        if (track[i][0] == position[0] & track[i][1] == position[1]) return TRUE;
    }
    return FALSE;
}

void printTrack(int** track, int *index) {
    for (int i = 0; i <= *index; i++)
    {
        printf("(%d, %d)\n", (track[i][0])+1, (track[i][1])+1);
    }
    printf("\n");    
}

int movement(Map *map, Data *data, int **track, int *actualPosition, int* index, int *sequence) {
    int result;
    int trackOk[2];
    int nextPosition[2];
    data->number_of_recursions++;

    if (map->map[actualPosition[0]][actualPosition[1]] == sequence[(*index)]) {
        trackOk[0] = actualPosition[0];
        trackOk[1] = actualPosition[1];
        track[(*index)] = trackOk;

        if (actualPosition[0] == ((map->height)-1)) {
            printf("\n\nPosicoes: \n");
            printTrack(track, index);
            return 1;
        }

        (*index) = (*index) + 1;
        if (actualPosition[0] > 0) //movement para cima
        {   
            nextPosition[0] = actualPosition[0]-1;
            nextPosition[1] = actualPosition[1];
            if (!inTracking(track, nextPosition, index)) {
                result = movement(map, data, track, nextPosition, index, sequence);
                if (result) return 1;
            }
        }

        if (actualPosition[0] < map->width-1) //movement para baixo
        {
            nextPosition[0] = actualPosition[0]+1;
            nextPosition[1] = actualPosition[1];
            if (!inTracking(track, nextPosition, index)) {
                result = movement(map, data, track, nextPosition, index, sequence);
                if (result) return 1;
            }
        }

        if (actualPosition[1] > 0) //movement para esquerda
        {  
            nextPosition[0] = actualPosition[0];
            nextPosition[1] = actualPosition[1]-1;
            if (!inTracking(track, nextPosition, index)) {
                result = movement(map, data, track, nextPosition, index, sequence);
                if (result) return 1;
            }
        }

        if (actualPosition[0] < map->height-1) //movement para direita
        {
            nextPosition[0] = actualPosition[0];
            nextPosition[1] = actualPosition[1]+1;
            if (!inTracking(track, nextPosition, index)) {
                result = movement(map, data, track, nextPosition, index, sequence);
                if (result) return 1;
            }
        }
        (*index) = (*index) - 1;
    }
    return 0;
}