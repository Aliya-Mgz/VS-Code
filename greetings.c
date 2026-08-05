#include <stdio.h>

void greetUser(char name[])
{
    printf("Hello, %s! Welcome!\n", name);
}

int main()
{
    greetUser("Aliya");
    greetUser("Khan");
    
    return 0;
}