#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
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
    nodeAddress turtle = head; 
    while(head!= NULL) {
        printf("%i ",turtle->val);
        head = head->next->next;
        turtle = turtle->next;
    }
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
    nodeAddress head = generateLinkedList(values, n);
    // Print first half of linked list
    printList(head);
    // Reverse Linked List
    

    // Free linked list
    freeList(head);
    return 0;
}