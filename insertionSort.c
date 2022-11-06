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

nodeAddress sortList(nodeAddress head) {
    nodeAddress temp = NULL, current = head->next, insert = NULL, prevInsert = NULL, prevCurrent = NULL;
    while (current != NULL)
    {
        insert = head;
        // Find the correct place to insert the value
        while(insert->val < current->val && insert != current) {
            prevInsert = insert;
            insert = insert->next;
        }
        // Swap if element not at correct place
        if (insert != current) {
            // First node is not head
            if (insert != head) {
                // Nodes are not adjacent
                if (insert->next != current) {
                    // swap nodes
                    temp = current->next;
                    current->next = insert;
                    prevInsert->next = current;
                    prevCurrent->next = temp;
                    // start->next = temp;

                    // Update start pointer
                    current = prevCurrent;
                } 
                // Node are adjacent
                else {
                    // Swap nodes
                    insert->next = current->next;
                    current->next = insert;
                    prevInsert->next = current;

                    // Update start pointer
                    current = insert;
                }
            }
            // First node is head
            else {
                // Nodes are not adjacent
                if (insert-> next != current) {
                    // Swap nodes 
                    temp = current->next;
                    current->next = insert;
                    // insert->next = temp;
                    prevCurrent->next = temp;

                    // Update head
                    head = current;

                    // Update start pointer
                    current = prevCurrent;
                }
                // Node are adjacent
                else {
                    // Swap nodes
                    insert->next = current->next;
                    current->next = insert;

                    // Update head
                    head = current;

                    // update start pointer
                    current = insert;
                }
            }
        }
        prevCurrent = current;
        current = current->next;
    }
    
    return head;
}

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
    sortArray(values, n);
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