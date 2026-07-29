#include <stdio.h>
#include <windows.h>

int main() 
{
    SetConsoleOutputCP(CP_UTF8); 
    int height;
    printf("Введите высоту пирамиды: ");
    scanf("%d", &height);
    for(int i = 1; i <= height; i++)
    {
        for (int j = 0; j < height - i; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}   