#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>

#define NO_CARTESIAN 2
#define NO_CHARS 256
#define LINE 16
#define COL 2

char **initializeCartesian();
// Boyer Moore algorithm
void badCharHeuristic(char *str, int size, int badChar[NO_CHARS]);
int search(char *txt, char pat1, char pat2);
// Function to generate the cartesian product and store in a matrix
void cartesianProduct(char **cartesian, char arr1[], char arr2[], int n, int n1);
// Function to select randomic values in the matrix of cartesian product to search for the pattern later
char *selectCartesian(char **cartesian);
void printCartesian(char **cartesian);
void printPattern(char *pattern);
int max(int a, int b);