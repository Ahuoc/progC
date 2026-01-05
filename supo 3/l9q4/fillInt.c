#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    clock_t start = clock();
    long LARGE_ARRAY_SIZE = 10000000;
    int *array = (int *)malloc(LARGE_ARRAY_SIZE * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    for (long i = 0; i < LARGE_ARRAY_SIZE; i++) {
        array[i] = rand();
    }
    

    FILE *fptr = fopen("output.txt", "wb");
    if (fptr == NULL) {
        fprintf(stderr, "File opening failed\n");
        free(array);
        return 1;
    }
    fwrite(array, sizeof(int), LARGE_ARRAY_SIZE, fptr);
    fclose(fptr);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time to fill and write the array: %f seconds\n", time_spent);

    int sum = 0;
    for (long i = 0; i < LARGE_ARRAY_SIZE; i++) {
        sum += array[i];
    }
    printf("Sum: %d\n", sum);

    free(array);
    return 0;
}