#include "../headers/map.h"

void initialize_map(Map** map, int width, int height) {
    (*map)->height = height;
    (*map)->width = width;

    (*map)->map = (int **)malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
        (*map)->map[i] = (int *)malloc(width * sizeof(int));
    }
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

int beginMovement(Map *map, Data *data) {
    int result = FALSE;
    int n = map->height * map->width;
    int actualPosition[2];
    int index = 0;
    actualPosition[0] = 0;

    int *sequence = (int*)malloc(n * sizeof(int));
    fibonnaci(sequence, n);

    int** track = (int**)malloc(n * (sizeof(int*)));
    for (int i = 0; i < n; i++)
    {
        track[i] = (int*)malloc(2 * sizeof(int));
    }  


    for (int i = 0; i < map->width; i++) {
        actualPosition[1] = i;
        result = movement(map, data, track, actualPosition, &index, sequence);
        if (result) break;
    }

    free(sequence);
    for (int i = 0; i < n; i++)
    {
        free(track[i]);
    } 
    free(track);

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
    int nextPosition[2];
    data->number_of_recursions++;

    if (map->map[actualPosition[0]][actualPosition[1]] == sequence[(*index)]) {
        track[(*index)][0] = actualPosition[0];
        track[(*index)][1] = actualPosition[1];

        if (actualPosition[0] == ((map->height)-1)) {
            printf("\n\nPosicoes: \n");
            printTrack(track, index);
            return TRUE;
        }

        (*index) = (*index) + 1;
        if (actualPosition[0] > 0) //movement para cima
        {   
            nextPosition[0] = actualPosition[0]-1;
            nextPosition[1] = actualPosition[1];
            if (!inTracking(track, nextPosition, index)) {
                result = movement(map, data, track, nextPosition, index, sequence);
                if (result) return TRUE;
            }
        }

        if (actualPosition[0] < map->width-1) //movement para baixo
        {
            nextPosition[0] = actualPosition[0]+1;
            nextPosition[1] = actualPosition[1];
            if (!inTracking(track, nextPosition, index)) {
                result = movement(map, data, track, nextPosition, index, sequence);
                if (result) return TRUE;
            }
        }

        if (actualPosition[1] > 0) //movement para esquerda
        {  
            nextPosition[0] = actualPosition[0];
            nextPosition[1] = actualPosition[1]-1;
            if (!inTracking(track, nextPosition, index)) {
                result = movement(map, data, track, nextPosition, index, sequence);
                if (result) return TRUE;
            }
        }

        if (actualPosition[0] < map->height-1) //movement para direita
        {
            nextPosition[0] = actualPosition[0];
            nextPosition[1] = actualPosition[1]+1;
            if (!inTracking(track, nextPosition, index)) {
                result = movement(map, data, track, nextPosition, index, sequence);
                if (result) return TRUE;
            }
        }
        (*index) = (*index) - 1;
    }
    return FALSE;
}