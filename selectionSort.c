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

    while(head!= NULL) {
        printf("%i ",head->val);
        head = head->next;
    }
    printf("\n");
}


nodeAddress sortList(nodeAddress head) {
    nodeAddress current = head, start = head, min = head, prevStart = NULL, prevMin = NULL, prevCurrent = NULL;
    nodeAddress temp = NULL;
    while (start != NULL) //Keep track of beginning of sub-list
    {
        current = start;
        min = start;
        // Find smallest element
        while (current!= NULL) 
        {
            if (current->val < min->val) {
                min = current;
                prevMin = prevCurrent;
            }
            prevCurrent = current;
            current = current->next;
        }        
        //Swap if start node is not smallest
        if (start != min) {
            // First node is not head
            if (start != head) {
                // Nodes are not adjacent
                if (start->next != min) {
                    // swap nodes
                    temp = min->next;
                    min->next = start->next;
                    start->next = temp;
                    prevStart->next = min;
                    prevMin->next = start;

                    // Update start pointer
                    start = min;
                } 
                // Node are adjacent
                else {
                    // Swap nodes
                    start->next = min->next;
                    min->next = start;
                    prevStart->next = min;

                    // Update start pointer
                    start = min;
                }
            }
            // First node is head
            else {
                // Nodes are not adjacent
                if (start-> next != min) {
                    // Swap nodes 
                    temp = min->next;
                    min->next = start->next;
                    start->next = temp;
                    prevMin->next = start;

                    // Update head
                    head = min;

                    // Update start pointer
                    start = min;
                }
                // Node are adjacent
                else {
                    // Swap nodes
                    start->next = min->next;
                    min->next = start;

                    // update start pointer
                    start = min;

                    // Update head
                    head = start;
                }
            }
        }
            
        prevStart = start;
        start = start-> next; //Increase size of sorted sub-list
    }
    return head; //Return head of sorted list
}


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
    printf("Sorted Array = ");
    printList(head);

    return 0;
}