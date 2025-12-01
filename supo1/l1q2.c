#include <stdio.h>

int main() {
    char i,j;
    j = 0;
    for (i=0; i<10, j<5; i++,j++) {
        printf("%d %d\n", i, j);
    }
    return 0;
}