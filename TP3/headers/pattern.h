#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define NO_CHARS 256

void badCharHeuristic(char *str, int size, int badChar[NO_CHARS]);
void search(char *txt, char *pat);
int max(int a, int b);
 