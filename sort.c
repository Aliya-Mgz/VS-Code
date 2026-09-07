#include <stdio.h>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int array[] = {55, 25, 40, 15, 60};
    int n = 5;

    printf("Исходный массив: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    bubble_sort(array, n);

    printf("Отсортированный массив: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    
}
void bubble_sort(int array[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
