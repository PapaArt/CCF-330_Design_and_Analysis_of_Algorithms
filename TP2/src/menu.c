#include "../headers/menu.h"

void menu(map *map){
    int choice[2];
    int **memo;
    int somaAtual = 0;
    printMenu1();
    scanf("%d", &choice[0]);
    if (choice[0] == 3)
    {
        printf("Programa encerrado com sucesso!!!\n");    
    }
    else
    {
        while (choice[0] == 1)
        {
            if (choice[0] == 1)
            {
                mapping(map);
                memo = initializeMemo(map);
                printf("Soma Mínima: %d\n", gridMap(map, memo));
                printf("Quantidade de caminhos: %d\n",numberWays(map, memo, 0, 0, 0, somaAtual));
                printMenu1();
                scanf("%d", &choice[0]);            
            }
        }
        printf("Programa encerrado com sucesso!!!\n");
    }
}

void mapping(map *map){
    FILE *fptr;
    char filename[100];
    char buffer[1000];
    char path[100];
    const char *basePath = "./data/";
    
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

    int width = 0;
    int height = 0;

    fscanf(fptr,"%d %d",&width,&height);
    initializeMap(map,height,width);
    int *data = (int *)malloc(sizeof(int *) * (width * height));

    int positionWidth = 0 , positionHeight = 0;

    for (int i = 0 ; ((i < width * height) && (fscanf(fptr, "%d ", &data[i]) == 1)) ; ++i){
        if(i < height){
            positionWidth = i;
        }else{
            positionHeight = i / height;
            positionWidth = i - (height * positionHeight);
        }

        //printf("MAP [%d][%d] = %d \n",positionHeight,positionWidth,data[i]); 
        
        insertValue(map, positionHeight,positionWidth, data[i]);
    }
    
    printf("Arquivo carregado com sucesso!\n\n");
    printMap(map);
    fclose(fptr);
}

void printMenu1(){
    menuHeader1();
    printf("(1) Execução            (2) Sair\n");
    printf("-------> ");
}

void menuHeader1(){
    printf("=========================\n");
    printf("|                       |\n|                       |\n|                       |\n|                       |\n|         MENU          |\n|                       |\n|                       |\n|                       |\n|                       |\n");
    printf("=========================\n");
}