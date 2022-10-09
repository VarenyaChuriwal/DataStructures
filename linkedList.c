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
    while(head!= NULL) {
        printf("%i ",head->val);
        head = head->next;
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

void main() {
    printf("Enter length of linked list\n");
    int n;
    scanf("%i",&n);
    int values[n];
    for (int i=0;i<n;i++) {
        printf("Value:");
        scanf("%i",&values[i]);
    }
    nodeAddress head = generateLinkedList(values, n);
    // Print linked list
    printList(head);
    // Free linked list
    freeList(head);
}