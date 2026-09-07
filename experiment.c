#include <stdio.h>
int linear_search(int array[], int size, int target, int *steps)
{
    for (int i = 0; i < size; i++)
    {
        (*steps)++;

        if (array[i] == target)
        {
            return i;
        }
    }

    return -1;
}

int binary_search(int array[], int size, int target, int *steps)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        (*steps)++;

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
    int small_array[] = {1, 3, 5, 10, 25, 26};

    int medium_array[] = {1, 3, 5, 7, 10, 12, 15, 20, 25, 30};

    int large_array[] = {
        1, 3, 5, 7, 9,
        10, 12, 14, 15, 18,
        20, 22, 25, 27, 30,
        33, 35, 40, 45, 50
    };

    int target = 25;

    int linear_steps;
    int binary_steps;

    linear_steps = 0;
    binary_steps = 0;

    linear_search(small_array, 6, target, &linear_steps);
    binary_search(small_array, 6, target, &binary_steps);

    printf("Small array (6 elements):\n");
    printf("Linear search: %d steps\n", linear_steps);
    printf("Binary search: %d steps\n\n", binary_steps);

    linear_steps = 0;
    binary_steps = 0;

    linear_search(medium_array, 10, target, &linear_steps);
    binary_search(medium_array, 10, target, &binary_steps);

    printf("Medium array (10 elements):\n");
    printf("Linear search: %d steps\n", linear_steps);
    printf("Binary search: %d steps\n\n", binary_steps);

    linear_steps = 0;
    binary_steps = 0;

    linear_search(large_array, 20, target, &linear_steps);
    binary_search(large_array, 20, target, &binary_steps);

    printf("Large array (20 elements):\n");
    printf("Linear search: %d steps\n", linear_steps);
    printf("Binary search: %d steps\n\n", binary_steps);

    printf("Conclusion:\n");
    printf("Binary search requires fewer steps than linear search.\n");

    return 0;
}