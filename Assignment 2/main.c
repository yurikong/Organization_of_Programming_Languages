#include "heap_manager.c"
#include <math.h>

/*
    This program uses my heap manager to
    solve a classic problem that requires dynamic storage.
*/

int main()
{
    int n, size, num;
    int *p;
    double sigma, mu;
    printf("Please enter a positive integer: ");
    scanf("%d", &n);
    if(n <= 0)
    {
        printf("Invalid input.\n");
        return -1;
    }
    size = n * sizeof(int);
    my_initialize_heap(size);
    p = my_malloc(size);
    printf("Please fill the array with %d numbers:\n", n);
    sigma = 0;
    mu = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        *(p + i) = num;
        // mu += num;
        mu += *(p + i);     // using my heap instead of stack
    }
    mu /= n;
    // standard deviation
    for(int i = 0; i < n; i++)
        sigma += pow(*(p + i) - mu, 2);
    sigma = sqrt(sigma / n);
    printf("Standard deviation = %f\n", sigma);
    return 0;
}