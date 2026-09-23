#include <stdio.h>

int main()
{
    char name[30];
    printf("What is your name? ");
    scanf("%s", name);
    printf("hello, %s!\n", name);
    return 0;
}