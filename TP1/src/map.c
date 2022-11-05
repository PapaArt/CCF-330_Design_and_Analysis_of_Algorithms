// #include "../headers/map.h"

// void initialize_map(map *map, int width, int height)
// {
//     map->height = height;
//     map->width = width;

//     map->map = (int **)malloc(sizeof(int *) * width);
//     for (int i = 0; i < width; i++)
//     {
//         map->map[i] = (int *)malloc(sizeof(int *) * height);
//     }
// }

// void insert_line(map *map, int position, int *line)
// {
//     for (int i = 0; i < map->width; i++)
//     {
//         for (int j = 0; j < map->height; j++)
//         {
//             map->map[position][j] = line[j];
//         }
//     }
// }

// void initialize_data(data *data)
// {
//     data->number_of_recursions = -1;
// }

// int** tracking(map *map, data *data) {
//     int track[map->width][map->height];
//     int actualPosition = {0,0};
//     int sequence = 
//     do
//     {
//         movement(map, data, track, actualPosition, 0, );
//     } while (/* condition */);   
// }


// // Função para fazer a movimentação do fazendeiro, necessidade de definir os parâmetros
// int movement(map *map, data *data, int **track, int* actualPosition, int n, int* sequence) {
//     track[n] = actualPosition;
    

//     return movement(map, data, track, [1, 2], n+1);
// }


// // ARTHUR

// // int movement(map *map, int direction, data *data, int line, int column)
// // {
// //     if (direction == LEFT && !(already_visited(map, &direction)))
// //     {

// //         return movement(map, LEFT, data, line, column - 1) - movement(map, LEFT, data, line, column - 2);
// //     }   
// //     else if (direction == RIGHT && !(already_visited(map, &direction)))
// //     {
        
// //         return movement(map, RIGHT, data, line, column + 1) - movement(map, RIGHT, data, line, column + 2);
// //     }
// //     else if (direction == UP && !(already_visited(map, &direction)))
// //     {
// //         return movement(map, UP, data, line - 1, column) - movement(map, UP, data, line - 2, column);
// //     }
// //     else if (direction == DOWN && !(already_visited(map, &direction)))
// //     {
// //         return movement(map, DOWN, data, line + 1, column) - movement(map, DOWN, data, line + 2, column);
// //     }
// // }

// // int already_visited(map *map, int *direction)
// // {
// //     switch (*direction)
// //     {
// //     case UP:
// //         return TRUE;
// //         break;
// //     case DOWN:
// //         return TRUE;
// //         break;
// //     case RIGHT:
// //         return TRUE;
// //         break;
// //     case LEFT:
// //         return TRUE;
// //         break;
// //     default:
// //         return FALSE;
// //         break;
// //     }
// // }

// void results(map *map, int line, int column)
// {
     
// }

// void print_field(map *map)
// {
// 	for (int i = 0; i < map->width; i++)
//     {
//         for (int j = 0; j < map->height; j++)
//         {
//             printf("%c", map->map[i][j]);
//         }
//     }
    
// }