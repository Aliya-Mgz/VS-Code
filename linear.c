#include <stdio.h>

int linear_search(int array[], int size, int target);

int main()
{
    int locked_array[] = {25, 3, 10, 1, 26, 5};

    int result = linear_search(locked_array, 6, 1);

    printf("Result: %d\n", result);
}

int linear_search(int array[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == target)
        {
            return i;
        }
    }

    return -1;
}