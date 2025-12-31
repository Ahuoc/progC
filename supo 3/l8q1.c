#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *adata = NULL;
int i, j;

int initialise(int dasize)
{
    for (int j = 0; j != dasize; j++)
        for (int i = 0; i != dasize; i++)
            adata[i + (j * dasize)] = i;
}

int dm_sumarray0(int dasize)
{
    int sum = 0;
    for (i = 0; i != dasize; i++)
    {
        for (j = 0; j != dasize; j++)
        {
            sum += adata[j + (i * dasize)];
        }
    }
    return sum;
}

int dm_sumarray1(int dasize)
{
    int sum = 0;
    for (i = 0; i != dasize; i++)
        for (j = 0; j != dasize; j++)
        {
            sum += adata[i + (j * dasize)];
        }
    return sum;
}

int dm_sumarray2(int dasize)
{
    int sum = 0;
    for (int j = 0; j != dasize; j++)
    {
        int i = 0;
        while (i != dasize)
        {
            int v = adata[i + (j * dasize)];
            sum += v;
            // Data-dependent loop - cannot unroll at compile time or prefetch during execution?
            i = v + 1;
        }
    }
    return sum;
}

int main()
{
    int dasize;
    for (dasize = 100; dasize <= 2000; dasize += 100) {
        adata = (int *)malloc(dasize * dasize * sizeof(int));
        initialise(dasize);
        printf("%d,", dasize);
        clock_t start, end;
        start = clock();
        int sum0 = dm_sumarray0(dasize);
        end = clock();
        printf("%lf,", ((double)(end - start)) / CLOCKS_PER_SEC);
        start = clock();
        int sum1 = dm_sumarray1(dasize);
        end = clock();
        printf("%lf,", ((double)(end - start)) / CLOCKS_PER_SEC);
        start = clock();
        int sum2 = dm_sumarray2(dasize);
        end = clock();
        printf("%lf\n", ((double)(end - start)) / CLOCKS_PER_SEC);
        free(adata);
    }

    return 0;
}