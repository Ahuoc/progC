#include <stdio.h>
#include <string.h>

int cntlower(char str[]) {
    int strSize = strlen(str);
    int count = 0;
    for (int idx=0; idx<strSize; idx++) {
        if (str[idx] >= 97 && str[idx] < 123) {
            count++;
        }
    }
    return count;
}


int main() {
    char testStr[] = "test this HELLO";
    int count = cntlower(testStr);
    printf("%d\n", count);

    return 0;
}