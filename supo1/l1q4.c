#include <stdio.h>

int main() {
    char i[] = "HelloWorld";
    int iSize = sizeof(i)/sizeof(i[0]);


    int done = 0; // Use as a boolean
    while (!done) {
        done = 1;
        for (int idx=0; idx<iSize-2; idx++) { // -2 due to the null terminator
            int comparable1 = i[idx];
            if (comparable1 >= 97 && comparable1 <= 122) {
                comparable1 -= 32;
            }
            int comparable2 = i[idx+1];
            if (comparable2 >= 97 && comparable2 <= 122) {
                comparable2 -= 32;
            }
            if (comparable1 > comparable2) {
                int temp = i[idx];
                i[idx] = i[idx+1];
                i[idx+1] = temp;
                done = 0;
            }
        }
    }

    for (int idx=0; idx<iSize-1; idx++) // -1 due to the null terminator
        printf("%c\n",i[idx]);
    return 0;
}