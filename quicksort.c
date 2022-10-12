#include <stdio.h>
#include <stdlib.h>

void printArray(int values[], int n) {
    for (int i = 0; i < n; i++) {
        printf(i? ", %i": "%i", values[i]);
    }
    printf("\n");
}

void sortArray(int values[], int start, int end) {
    if (end - start <= 1) {
        return;
    }
    int pivot = values[end - 1], i, j = start, tmp;
    for (i = start; i < end - 1; i++) {
        if(values[i] < pivot) {
            tmp = values[j];
            values[j] = values[i];
            values[i] = tmp;
            j++;
        }
    }
    // Put pivot in place
    tmp = values[j];
    values[j] = values[end - 1];
    values[end - 1] = tmp;

    // Perform on subarray
    sortArray(values, start, j);
    sortArray(values, j+1, end);

}

void main() {
    // Accept array as user input
    printf("Enter length of array list\n");
    int n;
    scanf("%i",&n);
    int values[n];
    for (int i=0;i<n;i++) {
        // printf("Value:");
        // scanf("%i",&values[i]);
        values[i] = rand();
    }

    // Print unsorted array
    printf("Unsorted Array = ");
    printArray(values, n);
    // Sort Array
    sortArray(values, 0, n);
    // Print sorted array
    printf("Sorted Array = ");
    printArray(values, n);
}