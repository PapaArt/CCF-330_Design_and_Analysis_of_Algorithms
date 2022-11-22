#include "../headers/menu.h"

void menu(map *map){
    //printMenu1();
    //printMenu2();
    mapping(map);
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

int readBuffer(char *buffer, int *sz){
    int ret;
    if ((*sz) == 0) return 0;
    buffer[*sz] = '\0';
    sscanf(buffer, "%d", &ret);
    *sz = 0;
    return ret;
}

char **initFrame()
{
    char **frame = (char **)malloc(LINE * sizeof(char *));
    int i, j;
    for (i = 0; i < LINE; i++)
    {
        frame[i] = (char *)malloc(COL * sizeof(char));
        for (j = 0; j < COL; j++)
        {
            frame[i][j] = ' ';
        }
    }
    return frame;
}

void rocket(char **frame)
{

}

void printRocket(char **frame)
{

}