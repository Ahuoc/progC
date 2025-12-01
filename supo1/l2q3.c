#include <stdio.h>
#define SWAP1(t, x, y) ({ t temp = x; x = y; y = temp; })
#define SWAP2(t, x, y) ({ x=x^y; y=x^y; x=x^y; })

int f(int x) {
    return x;
}

int main()
{
    int a = 42;
    int b = 727;
    printf("%d, %d\n", a, b);
    SWAP2(int, a, b);
    printf("%d, %d\n", a, b);

    int v[] = {1,2};
    int i = 0;
    int w[] = {3,4};
    int x = 1;
    printf("%d %d %d %d\n", v[0], v[1], w[0], w[1]);
    SWAP1(int, v[i++], w[f(x)]);
    printf("%d %d %d %d\n", v[0], v[1], w[0], w[1]);

    int c=1000;
    int *p = &c;
    int *q = &c;
    printf("%d %d %p %p\n", *p, *q, p, q);
    SWAP1(int, *p,*q);
    printf("%d %d %p %p\n", *p, *q, p, q);

    int d=1000;
    int *e = &d;
    int *f = &d;
    printf("%d %d %p %p\n", *e, *f, e, f);
    SWAP1(int, *e,*f);
    printf("%d %d %p %p\n", *e, *f, e, f);

    return 0;
}