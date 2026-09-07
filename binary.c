#include <stdio.h>

int binary_search(int array[], int size, int target);

int main()
{
    int locked_array[] = {1, 3, 5, 10, 25, 26};

    int result = binary_search(locked_array, 6, 10);

    printf("Result: %d\n", result);
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