#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

void printArray(int values[], int n) {
    for (int i = 0; i < n; i++) {
        printf(i? ", %i": "%i", values[i]);
    }
    printf("\n");
}

void heapifyDown(int heap[], int nodeIndex, int n) {
    // printf("%i\n",n);
    int leftChildIndex =  nodeIndex*2 + 1;
    int rightChildIndex = nodeIndex*2 + 2;
    if (leftChildIndex >= n && rightChildIndex >= n) {
        return;
    }
    int node = heap[nodeIndex], temp = 0;
    int leftChild = heap[leftChildIndex];
    int rightChild = heap[rightChildIndex];
    // Check if node smaller than children
    if (node < leftChild || node < rightChild) {
        // Check if both children exist
        if (rightChildIndex > n) {
            temp = node;
            heap[nodeIndex] = leftChild;
            heap[leftChildIndex] = temp;
            heapifyDown(heap, leftChildIndex, n);
        }
        // Check for bigger child
        else if (leftChild > rightChild) {
            temp = node;
            heap[nodeIndex] = leftChild;
            heap[leftChildIndex] = temp;
            heapifyDown(heap, leftChildIndex, n);

        } else {
            temp = node;
            heap[nodeIndex] = rightChild;
            heap[rightChildIndex] = temp;
            heapifyDown(heap, rightChildIndex, n);
        }
    }
}

void extractMax(int values[], int n) {
    int temp=0;
    // Swap value from first index into last unsorted index
    temp = values[0];
    assert(temp = values[0]);
    values[0] = values[n];
    values[n] = temp;
    // printArray(values, 12);
    // if (values[0] == 41 && values[1] == 5705 && values[2] == 6334)
    //     temp = 0;
    heapifyDown(values, 0, n-1);
}

void buildHeap(int values[], int n) {
    int i, half = n/2, temp;
    for (i = half-1; i>=0; i--) {
        heapifyDown(values, i, n);
    }
    for (i = n-1; i>=0; i--) {
        extractMax(values, i);
    }
}

int main() {
    printf("Enter length of array\n");
    int n;
    scanf("%i",&n);

    // Check if length > 0
    if (n <= 0)
        return 1;

    int values[n];
    for (int i=0;i<n;i++) {
        printf("Value:");
        scanf("%i",&values[i]);
        // values[i] = rand();
    }
    
    // Print unsorted array
    printf("Unsorted Array = ");
    printArray(values, n);
    // Sort Array
    buildHeap(values, n);
    // Print sorted array
    printf("Sorted Array = ");
    printArray(values, n);
}