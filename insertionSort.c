#include <stdio.h>
#include <stdlib.h>

void printArray(int values[], int n) {
    for (int i = 0; i < n; i++) {
        printf(i? ", %i": "%i", values[i]);
    }
    printf("\n");
}

void sortArray(int values[], int n) {
    int i, tmp, currentIndex, j;
    for (i = 1; i<n; i++) {
        currentIndex = i;
        for (j = i-1; j>=0;j--){
            if (values[j] <= values[currentIndex])
                break;
            tmp = values[currentIndex];
            values[currentIndex] = values[j];
            values[j] = tmp;
            currentIndex--;
        }
    }
}

int main() {
    // Accept array as user input
    printf("Enter length of array list\n");
    int n;
    scanf("%i",&n);

    // Check if length > 0
    if (n <= 0)
        return 1;

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
    sortArray(values, n);
    // Print sorted array
    printf("Sorted Array = ");
    printArray(values, n);

    return 0;
}