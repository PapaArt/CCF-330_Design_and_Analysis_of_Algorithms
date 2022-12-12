#include "../headers/menu.h"

void simulation(){
    int A[NO_CARTESIAN], B[NO_CARTESIAN];
    int aux1, aux2;
    aux1 = 0;
    aux2 = 1;
    int i;
    int n = 4;
    char txt[] = "ACTG";
    char txt2[] = "ACTG";
    
    char *firstSequence;
    char *secSequence;
    firstSequence = (char *)malloc(220000 * sizeof(char));
    secSequence = (char *)malloc(220000 * sizeof(char));

    char **cartesian = initializeCartesian();
    cartesianProduct(cartesian, txt, txt2, n);
    
    char *pattern = selectCartesian(cartesian);
    readFile(firstSequence, secSequence);

    for (i = 0; i < NO_CARTESIAN; i++)
    {
        A[i] = search(firstSequence, pattern[aux1], pattern[aux2]);
        B[i] = search(secSequence, pattern[aux1], pattern[aux2]);
        aux1 += 2;
        aux2 += 2; 
    }
    
    printPattern(pattern);
    similarity(A, B);   
}

void readFile(char *firstSequence, char *secSequence)
{
    srand(time(0));
    FILE *fptr;
    FILE *fptr2;
    char filename[100], filename2[100];
    char buffer[1000];
    char path[100], path2[100];
    const char *basePath = "./data/";
    int randomSequence = (rand() % (220000 - 4 + 1)) + 4;   

    printf("Digite o nome do primeiro arquivo: ");
    scanf("%s", filename);
    strcat(strcpy(path, basePath), filename);
    printf("%s\n", path);

    printf("Digite o nome do segundo arquivo: ");
    scanf("%s", filename2);
    strcat(strcpy(path2, basePath), filename2);
    printf("%s\n", path2);    

    fptr = fopen(path, "r");
    fptr2 = fopen(path2, "r");

    while (!(fptr))
    {
        printf("Erro ao ler arquivo!\n");
        printf("Insira o nome do primeiro arquivo novamente: ");

        scanf("%s", filename);

        strcat(strcpy(path, basePath), filename);

        (fptr) = fopen(path, "r");
    }

    while (!(fptr2))
    {
        printf("Erro ao ler arquivo!\n");
        printf("Insira o nome do segundo arquivo novamente: ");

        scanf("%s", filename2);

        strcat(strcpy(path2, basePath), filename2);

        (fptr2) = fopen(path2, "r");
    }

    for (int i = 0; i < randomSequence; i++)
    {
        fscanf(fptr, "%c", &firstSequence[i]);
        fscanf(fptr2, "%c", &secSequence[i]);
    }

    fclose(fptr);
    fclose(fptr2);
}