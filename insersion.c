#include <stdio.h>

void insertion_sort(int array[], int size);

int main()
{
    int example[] = {3, 25, 1, 10, 6, 11, 4, 19};
    int size = 8;

    printf("Before sorting: ");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", example[i]);
    }

    printf("\n");

    insertion_sort(example, size);

    printf("After sorting: ");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", example[i]);
    }

    printf("\n");

    return 0;
}

void insertion_sort(int array[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = key;
    }
}