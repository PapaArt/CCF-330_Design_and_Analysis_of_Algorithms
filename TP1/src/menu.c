#include "../headers/menu.h"

void menu(map *map, data *data){

    FILE *fptr;
    int choice;
    print_menu1();

    while (choice < 3)
    {
        const char *base_path = "./data/";
        char *line, filename[100], path[100];
        int width, height, resposta, file_not_found;
        int lines = 0, line_map = 0; 

        if (choice == 1)
        {
            remap(map, fptr, filename, path, &line, &lines, &height, &width, &line_map, &resposta, data, &choice);
            break;
        }
        else if (choice == 2)
        {
            initialize_data(data);
            remap(map, fptr, filename, path, &line, &lines, &height, &width, &line_map, &resposta, data, &choice);
            printf("Total de chamadas recursivas: %d\n", data->number_of_recursions);
            break;
        }
        else
        {break;}
    }
    

}

void print_menu1(){
    
    int i;
    fputs(" ", stdout);
    for (i = 0; i < 113; i++)
    {
        fputs("_", stdout);
    }
    printf("\n|");
    for (i = 0; i < 113; i++)
    {
        fputs(" ", stdout);
    }
    printf("|\n|");
    for (i = 0; i < 56; i++)
    {
        fputs(" ", stdout);
    }
    printf("MENU");
    for (i = 0; i < 53; i++)
    {
        fputs(" ", stdout);
    }
    printf("|");
    printf("\n");
    printf("|");
    for (i = 0; i < 113; i++)
    {
        fputs("_", stdout);
    }
    printf("|\n|");
    for (i = 0; i < 113; i++)
    {
        fputs(" ", stdout);
    }
    printf("|\n|                                            ");
    printf("Selecione o modo de execução:");
    for (i = 0; i < 40; i++)
    {
        fputs(" ", stdout);
    }
    printf("|");

    printf("\n|                                ");
    printf("(1)Normal            (2)Análise            (3)Sair");
    for (i = 0; i < 31; i++)
    {
        fputs(" ", stdout);
    }
    printf("|");

    printf("\n|");
    for (i = 0; i < 113; i++)
    {
        fputs("_", stdout);
    }
    printf("|");
    printf("\n");
    printf("---------->");
    fflush(stdin);

}

void remap(map *map, FILE *fptr, char filename[100], char path[100], char **line, int *lines, int *height, int *width, int *line_map, int *resposta, data *data, int *option)
{
    const char *base_path = "./data/";
    scanf("%s", filename);

    strcat(strcpy(path, base_path), filename);
    printf("%s\n", path);

    (fptr) = fopen(path, "r");

    while (!(fptr))
    {
        printf("Erro ao ler arquivo!\n");
        printf("Insira o nome do arquivo novamente: ");

        scanf("%s", filename);

        strcat(strcpy(path, base_path), filename);

        (fptr) = fopen(path, "r");
    }

    while (!feof(fptr))
    {
        if ((*lines) == 0)
        {
            // Dimensions of the map
            fscanf(fptr, "%d %d", &(*height), &(*width));
            initialize_map(map, (*width), (*height));

            (*line) = (char *)calloc((*width), sizeof(char));
        }
        else if ((*lines) >= 1 && (*lines) <= 1 + (*height))
        {
            // Map itself
            fscanf((fptr), "%s", (*line));
            insert_line(map, (*line_map), (*line));
            (*line_map)++;
        }
        else
        {
            break;
        }

        (*lines)++;
    }

    printf("Arquivo carregado com sucesso!\n");
    printf("\n");

    fclose(fptr);

    int direction = 0;

    (*resposta) = movement(map, direction, data, *lines, map->height);

    if ((*resposta) == 0)
    {
        printf("IMPOSSIVEL!!!");
    }
    else
    {
        printf("Posicoes:");
    }
}