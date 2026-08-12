#include <stdio.h>

void print_secret(int key)
{
    printf("Secret code: %d\n", key);
}

int main()
{
    int mission_key = 42;

    print_secret(mission_key);

    return 0;
}