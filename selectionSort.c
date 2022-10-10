#include <stdio.h>
#include <stdlib.h>

void printArray(int values[], int n) {
    for (int i = 0; i < n; i++) {
        printf(i? ", %i": "%i", values[i]);
    }
    printf("\n");
}

void sortArray(int values[], int n) {
    int i, min = 0, done;
    for (done = 0; done < n; done++) {
        min = done;
        for (i = done; i<n; i++) {
            if (values[i] < values[min]) {
                min = i;
            }
        }   
        int tmp = values[done];
        values[done] = values[min];
        values[min] = tmp;
    }
}

void main() {
    // Accept array as user input
    printf("Enter length of array list\n");
    int n;
    scanf("%i",&n);
    int values[n];
    for (int i=0;i<n;i++) {
        printf("Value:");
        scanf("%i",&values[i]);
    }

    // Print unsorted array
    printf("Unsorted Array = ");
    printArray(values, n);
    // Sort Array
    sortArray(values, n);
    // Print sorted array
    printf("Sorted Array = ");
    printArray(values, n);
}