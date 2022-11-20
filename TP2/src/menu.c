#include "../headers/menu.h"

void menu(){
    printMenu1();
    printMenu2();
    remap();
}

void printMenu1(){
    menuHeader1();
    printf("(1) Execução        (2) Extras          (3) Sair\n");
    printf("-------> \n");
}

void printMenu2(){
    menuHeader2();
    printf("(1) Caminho gráfico         (2) Gerar arquivo         (3) Sair\n");
    printf("-------> \n");
}

void menuHeader1(){
    printf("=========================\n");
    printf("|                       |\n|                       |\n|                       |\n|                       |\n|         MENU          |\n|                       |\n|                       |\n|                       |\n|                       |\n");
    printf("=========================\n");
}

void menuHeader2(){
    printf("=========================\n");
    printf("|                       |\n|                       |\n|                       |\n|                       |\n|        EXTRAS         |\n|                       |\n|                       |\n|                       |\n|                       |\n");
    printf("=========================\n");
}

void remap(){
    travel *travel = (travel)malloc(sizeof(travel));
    FILE *fptr;
    char filename[100];
    char path[100];
    const char *basePath = "./data/";
    int count = 0;
    char *line1;
    int *line2;
    char *word;
    int j;
    int height, width;
    int answer;
    int flag;

    printf("Digite o nome do arquivo: ");
    scanf("%s", filename);
    strcat(strcpy(path, basePath), filename);
    printf("%s\n", path);

    fptr = fopen(path, "r");

    while (!(fptr))
    {
        printf("Erro ao ler arquivo!\n");
        printf("Insira o nome do arquivo novamente: ");

        scanf("%s", filename);

        strcat(strcpy(path, basePath), filename);

        (fptr) = fopen(path, "r");
    }

    while (!feof(fptr))
    {
        if (count == 0)
        {
            sscanf(line1, "%d %d", &height, &width);
            initializeTrip(&travel, 0, width, height);
        }else if (count > 0 && count < (height)){
            fscanf(fptr, "%d", line2);
            insertLine(travel, count, line2);
        }
    }    

    fclose(fptr);
    printf("Grid: %d x %d\n", height, width);
    printGrid(travel);
    printf("\n");

    printf("Arquivo carregado com sucesso!\n\n");
}
