#include <stdio.h>
#include <windows.h>

int main() 
{
    SetConsoleOutputCP(CP_UTF8);
    const int OUTPUT_COUNT = 10;
    for (int i = 0; i < OUTPUT_COUNT; i++)
    {
        printf("Hello\n");  
    }
    return 0;
}