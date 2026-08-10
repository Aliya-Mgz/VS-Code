#include <stdio.h>
#include <windows.h> 

int main()
{
    SetConsoleOutputCP(CP_UTF8); 
    char name[12];
    printf("Как тебя зовут? \n");
    scanf("%s", name);
    printf("Привет, %s! Очень рада тебя видеть!\n", name);
    return 0;
}