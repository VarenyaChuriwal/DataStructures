#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node * next;
};

typedef struct node * nodeAddress;

void printList(nodeAddress head) {
    // Check if list empty
    if (head == NULL)
        printf("List is empty");

    while(head->next!= NULL) {
        printf("%i -> ",head->val);
        head = head->next;
    }
    printf("%i ",head->val);
    printf("\n");
}


void arrange(nodeAddress head, nodeAddress last) {
    // Check if length of list is 1
    if (head==last) {
        return;
    }

    nodeAddress pivot = head, start = head, prevPivot = pivot;
    int temp;
    while (head != last) {
        if (head->val < last->val) { //If value less than pivot put in sub array
            // Swap values
            if (head != pivot) {
                temp = head->val;
                head->val = pivot->val;
                pivot->val = temp;
            }
            prevPivot = pivot;
            pivot = pivot->next;
        }
        head=head->next;
    }
    // Put pivot in correct place
    temp = last->val;
    last->val = pivot->val;
    pivot->val = temp;

    arrange(start, prevPivot);
    if (pivot != NULL)
        arrange(pivot, last);
}

nodeAddress sortList(nodeAddress head) {
    nodeAddress last = head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    arrange(head, last);
    
    return head;
}

nodeAddress generateLinkedList(int values[], int n) {
    // Special head case 
    nodeAddress head = malloc(sizeof(struct node));
    head->val = values[0];
    head->next = NULL;
    nodeAddress temp = head;
    // Iterate over values 
    for(int i = 1; i<n; i++) {
        temp->next = malloc(sizeof(struct node));  // allocate memory for a node
        temp = temp->next;
        temp->val = values[i];
        temp->next = NULL;
    }
    return head;
}


// Array functions
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
        printf("Value:");
        scanf("%i",&values[i]);
        // values[i] = rand();
    }

    //Create linked list from inputted array
    nodeAddress head = generateLinkedList(values, n);


    // Print unsorted array
    printf("Unsorted Array = ");
    printArray(values, n);
    // Sort Array
    sortArray(values, 0, n);
    // Print sorted array
    printf("Sorted Array = ");
    printArray(values, n);


    // Print unsorted list
    printf("Unsorted List = ");
    printList(head);
    // Sort List
    head = sortList(head);
    // Print sorted list
    printf("Sorted List = ");
    printList(head);

    return 0;
}