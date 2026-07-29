#include <stdio.h>
#include <windows.h>

int main() 
{
    SetConsoleOutputCP(CP_UTF8); 
    int number;

    do
    {
        printf("Введите число больше 10: ");
        scanf("%i", &number);

        if(number <= 10)
        {
            printf("Попробуйте снова.\n");
        }
    } while (number <= 10);

    printf("Спасибо, вы ввели число: %i\n", number);
    }