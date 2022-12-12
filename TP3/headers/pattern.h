#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>
#include <math.h>

#define NO_CARTESIAN 4
#define NO_CHARS 256
#define BENCHMARK 10
#define LINE 16
#define COL 2

char **initializeCartesian();
// Boyer Moore algorithm
void badCharHeuristic(char *str, int size, int badChar[NO_CHARS]);
int search(char *txt, char pat1, char pat2);
// Function to generate the cartesian product and store in a matrix
void cartesianProduct(char **cartesian, char arr1[], char arr2[], int n);
// Function to select randomic values in the matrix of cartesian product to search for the pattern later
char *selectCartesian(char **cartesian);
// Function to calculate the similarity
double similarity(int A[], int B[]);
void printCartesian(char **cartesian);
void printPattern(char *pattern);
void printArrayAB(int A[], int B[]);
int max(int a, int b);