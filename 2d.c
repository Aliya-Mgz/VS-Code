#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(void)
{
    SetConsoleOutputCP(CP_UTF8);
    int n;

    printf("Введите количество элементов для массива: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Ошибка ввода: требуется положительное число.\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL)
    {
        printf("Ошибка: не удалось выделить память (malloc).\n");
        return 1;
    }

    printf("\nВведите %d целых чисел:\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nВведенный массив (malloc): ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("\n=== Сравнение незаполненных блоков памяти ===");
    
    int *test_malloc = (int *)malloc(5 * sizeof(int));
    int *test_calloc = (int *)calloc(5, sizeof(int));

    if (test_malloc != NULL && test_calloc != NULL)
    {
        printf("\nЗначения в test_malloc (мусор): ");
        for (int i = 0; i < 5; i++)
        {
            printf("%d ", test_malloc[i]);
        }

        printf("\nЗначения в test_calloc (обнулены): ");
        for (int i = 0; i < 5; i++)
        {
            printf("%d ", test_calloc[i]);
        }
        printf("\n");
    }

    free(arr);
    if (test_malloc) free(test_malloc);
    if (test_calloc) free(test_calloc);

    printf("\nПамять успешно освобождена.\n");

    return 0;
}