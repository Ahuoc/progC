#include <stdio.h>

int main()
{
    FILE *fptr;
    fptr = fopen("random_10mb.txt", "r");
    
    if (fptr == NULL) {
        printf("Error: Could not open file\n");
        return 1;
    }
    
    long total = 0;

    char myString[100];
    while(fgets(myString, 100, fptr)) {
        for (int i = 0; myString[i] != '\0'; i++) {
            total += (unsigned char) myString[i];
        }
    }

    fclose(fptr);

    printf("%ld\n", total);
    return 0;
}