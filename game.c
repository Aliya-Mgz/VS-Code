#include <stdio.h>
#include <windows.h>

int main() 
{
    SetConsoleOutputCP(CP_UTF8); 
    int secret_number = 25;
    int guess;

    printf("Я загадала число от 1 до 30, сможешь угадать? \n");
    printf("Ваша догадка: ");
    scanf("%i", &guess);

    while (guess != secret_number) 
    {
        if (guess < secret_number) 
        {
            printf("Попробуйте снова: ");
        } 
        else 
        {
            printf("Попробуйте снова: ");
        }
        scanf("%i", &guess);
    }
    printf("Поздравляю! Вы угадали число %i!\n", secret_number);

   
    while (secret_number > 0)
    {
        printf("%i\n", secret_number);
        secret_number = secret_number - 1;

    }
printf("Поехали!\n");
    return 0;
}
