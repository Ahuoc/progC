#include <stdio.h>

int main() {
    int i[] = {8,3,5,4,9,2,10,-20,-1};
    int iSize = sizeof(i)/sizeof(i[0]);


    int done = 0; // Use as a boolean
    while (!done) {
        done = 1;
        for (int idx=0; idx<iSize-1; idx++) {
            if (i[idx] > i[idx+1]) {
                int temp = i[idx];
                i[idx] = i[idx+1];
                i[idx+1] = temp;
                done = 0;
            }
        }
    }

    for (int idx=0; idx<iSize; idx++)
        printf("%d\n",i[idx]);
    return 0;
}