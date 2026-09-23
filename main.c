#include <stdio.h>
#include <stdlib.h>

int linear_search(int array[], int size, int target, int *steps) {
*steps = 0;
for (int i = 0; i < size; i++) {
(*steps)++;
if (array[i] == target) {
return i;
}
}
return -1;
}

int binary_search(int array[], int size, int target, int *steps) {
int low = 0;
int high = size - 1;
*steps = 0;

while (low <= high) {
(*steps)++;
int mid = (low + high) / 2;

if (array[mid] == target) {
return mid;
} else if (array[mid] < target) {
low = mid + 1;
} else {
high = mid - 1;
}
}
return -1;
}

void insertion_sort_ascending(int arr[], int size) {
for (int i = 1; i < size; i++) {
int key = arr[i];
int j = i - 1;
while (j >= 0 && arr[j] > key) {
arr[j + 1] = arr[j];
j = j - 1;
}
arr[j + 1] = key;
}
}

void insertion_sort_descending(int arr[], int size) {
for (int i = 1; i < size; i++) {
int key = arr[i];
int j = i - 1;
while (j >= 0 && arr[j] < key) {
arr[j + 1] = arr[j];
j = j - 1;
}
arr[j + 1] = key;
}
}

int main() {
int arr[] = {12, 4, 5, 67, 3, 21, 9, 15};
int size = 8;

printf("--- ORIGINAL ARRAY ---\n");
for (int i = 0; i < size; i++) {
printf("%d ", arr[i]);
}
printf("\n\n");

insertion_sort_ascending(arr, size);
printf("--- AFTER ASCENDING SORT ---\n");
for (int i = 0; i < size; i++) {
printf("%d ", arr[i]);
}
printf("\n\n");

int target = 15;
int lin_steps = 0, bin_steps = 0;
int lin_res = linear_search(arr, size, target, &lin_steps);
int bin_res = binary_search(arr, size, target, &bin_steps);

printf("Search results for %d:\n", target);
printf("Linear search: index = %d, steps = %d\n", lin_res, lin_steps);
printf("Binary search: index = %d, steps = %d\n\n", bin_res, bin_steps);

insertion_sort_descending(arr, size);
printf("--- AFTER DESCENDING SORT ---\n");
for (int i = 0; i < size; i++) {
printf("%d ", arr[i]);
}
printf("\n");

return 0;
}