#include <stdio.h>
#include <windows.h>
#define OUTPUT_COUNT 10
int main() 
{
    SetConsoleOutputCP(CP_UTF8);
    for (int i = 0; i < OUTPUT_COUNT; i++)
    {
        printf("Hello\n");  
    }
    return 0;
}