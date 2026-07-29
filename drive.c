# include <stdio.h>
#include <windows.h> 

int main()
{
    SetConsoleOutputCP(CP_UTF8); 
    int age;
    
    printf("Сколько тебе лет? \n");
    scanf("%d", &age);

    if (age >= 18)
    {
        printf("Ты уже можешь водить машину!\n");
    }
    else
    {
        printf("Извини, тебе ещё надо подождать\n");
    }
}