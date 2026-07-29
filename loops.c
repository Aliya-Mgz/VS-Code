#include <stdio.h>
#include <windows.h>

int main() 
{
    SetConsoleOutputCP(CP_UTF8); 
    for (int i = 0; i < 5; i++)
    {
        printf("Hello! Это цикл: #%i\n", i);
    }
    return 0;
}