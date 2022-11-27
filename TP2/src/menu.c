#include "../headers/menu.h"

void menu(map *map){
    int choice[2];
    int **memo;
    printMenu1();
    scanf("%d", &choice[0]);
    if (choice[0] == 3)
    {
        printf("Programa encerrado com sucesso!!!\n");    
    }
    else
    {
        while (choice[0] == 1 || choice[1] == 1 || choice[0] == 2 || choice[1] == 2)
        {
            if (choice[0] == 1)
            {
                mapping(map);
                memo = initializeMemo(map);
                printf("Soma Mínima: %d\n", gridMap(map, memo));
                printf("Quantidade de caminhos: %d\n",numberWays(map, memo));
                printMenu1();
                scanf("%d", &choice[0]);            
            }
            else if (choice[0] == 2)
            {
                choice[0] = 3;
                printMenu2();
                scanf("%d", &choice[1]);
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
    printf("(1) Execução        (2) Extras          (3) Sair\n");
    printf("-------> ");
}

void printMenu2(){
    menuHeader2();
    printf("(1) Caminho gráfico         (2) Gerar arquivo         (3) Sair\n");
    printf("-------> ");
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

int readBuffer(char *buffer, int *sz){
    int ret;
    if ((*sz) == 0) return 0;
    buffer[*sz] = '\0';
    sscanf(buffer, "%d", &ret);
    *sz = 0;
    return ret;
}