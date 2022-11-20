#include "../headers/menu.h"

void menu(){
    //printMenu1();
    //printMenu2();
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

int readBuffer(char *buffer, int *sz){
    int ret;
    if ((*sz) == 0) return 0;
    buffer[*sz] = '\0';
    sscanf(buffer, "%d", &ret);
    *sz = 0;
    return ret;
}

void remap(){
    travel *travel = (struct travel*)malloc(sizeof(travel));
    FILE *fptr;
    char filename[100];
    char buffer[1000];
    char path[100];
    const char *basePath = "./data/";
    char ch;
    int count = 0;
    int lines = 0;
    char *line;
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
    int i = 0;
    int j;
    while ((ch = fgetc(fptr)) != EOF)
    {
        if (isdigit(ch))
        {
            buffer[count++] = ch;
        }
        else if (i == 0)
        {
            height = readBuffer(buffer,&count);
            i++;
        }
        else if (i == 1)
        {
            width = readBuffer(buffer,&count);
            initializeTrip(travel, width, height);
            i++;
        }
        else
        {
             = readBuffer(buffer, &count);
            j++;
        }
        
    }
    fclose(fptr);
    printf("Grid: %d x %d\n", height, width);
    printGrid(travel);
    printf("\n");

    printf("Arquivo carregado com sucesso!\n\n");
}
