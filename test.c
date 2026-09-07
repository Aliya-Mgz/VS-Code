#include <stdio.h>
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

int binary_search(int array[], int size, int target)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (array[mid] == target)
        {
            return mid;
        }
        else if (array[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int array[] = {1, 3, 5, 10, 25, 26};
    int size = 6;

    int target = 1;

    printf("=== Element at the beginning ===\n");
    printf("Target: %d\n", target);
    printf("Linear search: %d\n", linear_search(array, size, target));
    printf("Binary search: %d\n\n", binary_search(array, size, target));


    target = 10;

    printf("=== Element in the middle ===\n");
    printf("Target: %d\n", target);
    printf("Linear search: %d\n", linear_search(array, size, target));
    printf("Binary search: %d\n\n", binary_search(array, size, target));

    target = 26;

    printf("=== Element at the end ===\n");
    printf("Target: %d\n", target);
    printf("Linear search: %d\n", linear_search(array, size, target));
    printf("Binary search: %d\n\n", binary_search(array, size, target));


    target = 20;

    printf("=== Element is absent ===\n");
    printf("Target: %d\n", target);
    printf("Linear search: %d\n", linear_search(array, size, target));
    printf("Binary search: %d\n\n", binary_search(array, size, target));

    return 0;
}