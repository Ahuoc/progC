#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    int *stack = malloc(argc*sizeof(int));
    int stackCurrentLen = 0;
    for (int argi = 1; argi < argc; argi++) {
        // Assumes expression given is valid - to add safeguards can just add extra if statements based on stackCurrentLen.
        if (strcmp(argv[argi], "+") == 0) {
            stack--;
            int op1 = *stack;
            stack--;
            stackCurrentLen--;
            int op2 = *stack;
            *stack = op1+op2;
            stack++;
        }
        else if (strcmp(argv[argi], "-") == 0) {
            stack--;
            int op1 = *stack;
            stack--;
            stackCurrentLen--;
            int op2 = *stack;
            *stack = op2-op1;
            stack++;
        }
        else if (strcmp(argv[argi], "x") == 0) {
            stack--;
            int op1 = *stack;
            stack--;
            stackCurrentLen--;
            int op2 = *stack;
            *stack = op1*op2;
            stack++;
        }
        else if (strcmp(argv[argi], "/") == 0) {
            stack--;
            int op1 = *stack;
            stack--;
            stackCurrentLen--;
            int op2 = *stack;
            *stack = op2/op1;
            stack++;
        }
        else {
            *stack = atoi(argv[argi]);
            stackCurrentLen++;
            stack++;
        }
    }
    stack--;
    printf("%d\n", *stack);
    return 0;
}