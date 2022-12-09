#include "../headers/menu.h"

void simulation(){
    int A[4], B[4];
    int aux1, aux2;
    aux1 = 0;
    aux2 = 1;
    int i;
    int n = 2 * NO_CARTESIAN;
    char txt[] = "ACTG";
    char txt2[] = "ACTG";
    char hum[] = "AACCCTG";
    char chim[] = "AACCTG";
    char **cartesian = initializeCartesian();
    cartesianProduct(cartesian, txt, txt2, n, n);
    char *pattern = selectCartesian(cartesian);
    for (i = 0; i < 4; i++)
    {
        A[i] = search(hum, pattern[aux1], pattern[aux2]);
        B[i] = search(chim, pattern[aux1], pattern[aux2]);
        aux1 += 2;
        aux2 += 2; 
    }
    for (i = 0; i < 4; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    for (i = 0; i < 4; i++)
    {
        printf("%d ", B[i]);
    }printf("\n");
    //printPattern(pattern);
    
}