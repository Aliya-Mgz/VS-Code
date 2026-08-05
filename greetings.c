#include <stdio.h>

void greetUser(char name[])
{
    printf("Hello, %s! Welcome\n", name);
}

int main()
{
    greetUser("Aliya");
    return 0;
}