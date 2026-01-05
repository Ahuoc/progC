#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    clock_t start = clock();
    long LARGE_ARRAY_SIZE = 10000000;
    float *array = (float *)malloc(LARGE_ARRAY_SIZE * sizeof(float));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    FILE *fptr = fopen("output.txt", "rb");
    if (fptr == NULL) {
        fprintf(stderr, "File opening failed\n");
        free(array);
        return 1;
    }

    size_t itemsRead = fread(array, sizeof(float), LARGE_ARRAY_SIZE, fptr);
    if (itemsRead != LARGE_ARRAY_SIZE) {
        fprintf(stderr, "File reading failed\n");
        fclose(fptr);
        free(array);
        return 1;
    }
    fclose(fptr);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time to read the array: %f seconds\n", time_spent);

    float sum = 0.0f;
    for (long i = 0; i < LARGE_ARRAY_SIZE; i++) {
        sum += array[i];
    }
    printf("Sum: %f\n", sum);
    free(array);
    return 0;
}