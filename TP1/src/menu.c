#include "../headers/menu.h"

void menu(Map *map, data *data){

    FILE *fptr;
    int choice;
    print_menu1();
    scanf("%d", &choice);

    while (choice < 3)
    {
        print_menu1();
        scanf("%d", &choice);
        const char *base_path = "./data/";
        char filename[100], path[100];
        int width, height, resposta, file_not_found;
        int lines = 0, line_map = 0, column = 0; 

        if (choice == 1)
        {        
            initialize_data(data);
            // remap(map, fptr, filename, path, &lines, &height, &width, &line_map, &resposta, data, choice);
        }
        else if (choice == 2)
        {
            initialize_data(data);
            // remap(map, fptr, filename, path, &lines, &height, &width, &line_map, &resposta, data, choice);
            // printf("Total de chamadas recursivas: %d\n", data->number_of_recursions);
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

void remap(Map *map, FILE *fptr, char filename[100], char path[100], int *lines, int *height, int *width, int *line_map, int *resposta, data *data, int option)
{
    const char *base_path = "./data/";
    int number;
    int count;
    int *line;
    printf("Digite o nome do arquivo: ");
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
            map = initialize_map((*width), (*height));

            line = (int *)malloc((*width) * sizeof(int));
        }
        else if ((*lines) >= 1 && (*lines) <= 1 + (*height))
        {
            count = 0;
            while (fscanf((fptr), "%d", &number) != -1)
            {
                    line[count] = number;
                    count++;
            }
            insert_line(map, (*line_map), line);
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

    int** track;
    int* index;
    *lines = 0;
    printf("Lines value: %d\n", *lines);
    (*resposta) = beginMovement(map, data, track, index);

    if ((*resposta) == FALSE)
    {
        printf("IMPOSSIVEL!!!\n");
    }
    else
    {
        printf("Posicoes: \n");
        for (int i = 0; i < *index; i++)
        {
            printf("(%d, %d)\n", track[*index][0], track[*index][1]);
        }        
    }
}