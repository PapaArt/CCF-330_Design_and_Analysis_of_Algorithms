#include "../headers/pattern.h"

char **initializeCartesian()
{
    char **cartesian = (char**)malloc(LINE * sizeof(char *));
    int i, j;
    for (i = 0; i < LINE; i++)
        for (j = 0; j < COL; j++)
            cartesian[i][j] = ' ';

    return cartesian;    
}

void badCharHeuristic(char *str, int size, int badChar[NO_CHARS])
{
    int i;
    for (i = 0; i < NO_CHARS; i++)
    {
        badChar[i] = -1;
    }
    for (i = 0; i < size; i++)
    {
        badChar[str[i]] = i;
    }
}

void search(char *txt, char *pat)
{
    int m = strlen(pat);
    int n = strlen(txt);

    int badChar[NO_CHARS];

    badCharHeuristic(pat, m, badChar);

    int s = 0;

    while (s <= (n - m))
    {
        int j = m - 1;

        while (j >= 0 && pat[j] == txt[s+j])
            j--;
        if (j < 0)
        {
            printf("Pattern occurs at shift = %d\n", s);
            s += (s+m < n) ? m - badChar[txt[s+m]] : 1;
        }
        else
            s += max(1, (j - badChar[txt[s+j]]));
    }
}

void cartesianProduct(char *cartesian, char arr1[], char arr2[], int n, int n1)
{
        
}

void printCartesian(char **cartesian)
{
    for (int i = 0; i < LINE; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            printf("%c", cartesian[i][j]);
        }printf("\n");
    }    
}

int max(int a, int b){
    return (a > b) ? a : b;
}