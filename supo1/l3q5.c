#include <stdio.h>

void f(int j[5]) { 
    int i = sizeof j;
    printf("%d\n", i);
}

void g(int j[][10]) { 
    int i = sizeof j;
    printf("%d\n", i);
}


int main()
{
    int i = sizeof(char);

    i = sizeof(int);

    int a; 
    i = sizeof a;

    char b[5]; 
    i = sizeof(b);

    char *c=b; 
    i = sizeof(c);

    struct {int d; char e;} s; 
    i = sizeof s;

    int j[5];
    f(j);

    int k[4][10];
    g(k);

    //printf("%d\n", i);

    return 0;
}