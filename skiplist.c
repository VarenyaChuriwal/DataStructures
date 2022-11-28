// Base code copied from my own previous implementation of linked lists and then edited
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    int val;
    struct node *next;
    struct node * next2;
};

typedef struct node * nodeAddress;

void freeList(nodeAddress head) {
    nodeAddress temp = head;
    while(head!= NULL) {
        temp = temp->next;
        free(head);
        head = temp;
    }
}

void printList(nodeAddress head) {
    // Check if lsit empty
    if (head == NULL)
        printf("List is empty");

    while(head-> next != NULL) {
        printf("%i -> ", head->val);
        head = head->next;
    }
    printf("%i", head->val);
    printf("\n");
}

nodeAddress arrayToLLWithNext2(int *a, int n) {
    // Check if array has values
    if (n <= 0) {
        printf("Array length must be positive\n");
        return NULL;
    }
    // Special head case first element in list
    nodeAddress head = malloc(sizeof(struct node));
    head->val = a[0];
    nodeAddress temp = head, current = NULL;

    // Create linked list using only next pointer
    for(int i = 1; i<n; i++) {
        temp->next = malloc(sizeof(struct node));  // allocate memory for a node
        temp = temp->next;
        temp->val = a[i];
    }
    temp->next = NULL; //Add NULL pointer at the end

    // Add the next2 pointer to each node
    current = head;
    while(current != NULL) {
        // Find 2nd element from current node
        temp = current;
        for (int i = 0; i < 2; i++) {
            if (temp == NULL)
                break;
            temp = temp->next;
        }
        current->next2 = temp; //Update next2 pointer to 2nd node
        current = current->next;
    }
    return head;
}

int main() {
    printf("Enter length of linked list\n");
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

    nodeAddress head = arrayToLLWithNext2(values, n);

    // Print linked list
    printList(head);


    // Free linked list
    freeList(head);
    return 0;
}