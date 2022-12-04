#include "../headers/pattern.h"


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

int max(int a, int b){
    return (a > b) ? a : b;
}