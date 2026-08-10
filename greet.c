#include <stdio.h>
#include <windows.h>


int main(int argc, char *argv[]) 
{
    SetConsoleOutputCP(CP_UTF8);
if (argc == 2) {
        printf("Привет, %s!\n", argv[1]);
    }
    else {
        printf("Привет, незнакомец!\n");
        printf("попробуй вызвать команду вместе с именем\n");
    }
    return 0;
}