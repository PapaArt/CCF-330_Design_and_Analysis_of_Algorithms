#include "../headers/test_way.h"

int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int dinamic_fib(int n)
{
    /* Declare an array to store Fibonacci numbers. */
    int f[n + 1];
    int i;
  
    /* 0th and 1st number of the series are 0 and 1*/
    f[0] = 0;
    f[1] = 1;
  
    for (i = 2; i <= n; i++) {
        /* Add the previous 2 numbers in the series
         and store it */
        f[i] = f[i - 1] + f[i - 2];
    }
  
    return f[n];
}