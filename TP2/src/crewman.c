#include "../headers/crewman.h"

void initializeTrip(travel **travel, int sum, int width, int height)
{
    (*travel)->height = height;
    (*travel)->width = width;

    (*travel)->map = (int **)malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++)
    {
        (*travel)->map[i] = (int *)malloc(width * sizeof(int));
    }    
}

void insertLine(travel *travel, int position, int *line){
    for (int i = 0; i < travel->width; i++)
    {
        for (int j = 0; j < travel->height; j++)
        {
            travel->map[position][j] = line[j];
        }
    }
}

void printGrid(travel *travel){
    for (int i = 0; i < travel->height; i++) {
        for (int j = 0; j < travel->width; j++) {
            printf("%d ", travel->map[i][j]);
        }
        printf("\n");
    }
}

int gridTravel(int width, int height, int *memo)
{
    //int *key = width;
    // if (in(memo, sizeof(memo), key)) return memo[key];
    // if (width == 1 && height == 1) return 1;
    // if (width == 0 || height == 0) return 0;

    // memo[key] = gridTravel(width + 1, height, memo) + gridTravel(width, height + 1, memo);
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
