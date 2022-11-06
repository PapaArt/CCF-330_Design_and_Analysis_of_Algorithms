#include "../headers/menu.h"

void menu() {
    Data *data = (Data*)malloc(sizeof(data)); 
    int choice;
    int flag = TRUE;
    const char *base_path = "./data/";
    char filename[100], path[100];
    while (flag) {
        print_menu1();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                initialize_data(data);
                remap(data);
                break;
            case 2:
                initialize_data(data);
                remap(data);
                printf("Total de chamadas recursivas: %d\n", data->number_of_recursions);
                break;
            case 3:
                printf("Programa finalizado com sucesso!!!\n");
                flag = FALSE;
                break;
            default:
                break;            
        }
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

void remap(Data *data)
{   
    Map *map = (Map*)malloc(sizeof(Map));
    FILE *fptr;
    char filename[100];
    char path[100];
    const char *base_path = "./data/";
    int count = 0;
    char *line;
    int j;
    char* word;
    int height = 1, width;
    int resposta;
    int flag;
    
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
   
    printf("Arquivo carregado com sucesso!\n\n");

    while (!feof(fptr))
    {
        flag = fgets(line, 100, fptr);
        if (flag) {
            if (count == 0) {
                sscanf(line, "%d %d", &height, &width);
                initialize_map(&map, width, height);
            } else {
                j = 0;
                word = strtok(line, " ");
                map->map[count-1][j] = atoi(word);
                j++;
                while ((word = strtok(NULL, " ")) != NULL) {
                    map->map[count-1][j] = atoi(word);
                    j++;
                }		
            }
        }        
        count++;
    }
    fclose(fptr);    
    printf("Matriz: %d x %d\n", height, width);
    print_field(map);
    printf("\n");

    resposta = beginMovement(map, data);

    for (int i = 0; i < height; i++)
    {
        free(map->map[i]);
    }    
    free(map->map);
    free(map);

    if (resposta == FALSE)
    {
        printf("IMPOSSÍVEL!\n");
    }
}