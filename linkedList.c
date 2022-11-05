#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
};

typedef struct node * nodeAddress;

nodeAddress chunkReverseList(nodeAddress head, int k) {
    if (head == NULL) {
        printf("Cannot chunk reverse empty list");
        return head;
    }

    nodeAddress temp = NULL, new_head = NULL, head_copy = head;
    // Reverse the chunk
    for (int i = 0; i < k; i++) {
        temp = head -> next;
        head->next = new_head;
        new_head = head;
        head = temp;
    }
    // Point the last element of chunk to the first element of remaining array
    head_copy ->next = head;

    return (new_head);
}

nodeAddress reverseList(nodeAddress head) {
    if (head == NULL) {
        printf("Cannot reverse empty list");
        return head;
    }
    nodeAddress temp = NULL, new_head = NULL;
    while(head != NULL) {
        temp = head -> next;
        head->next = new_head;
        new_head = head;
        head = temp;
    }
    return (new_head);
}

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

    while(head!= NULL) {
        printf("%i ",head->val);
        head = head->next;
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
    // Print linked list
    printList(head);
    // Reverse Linked List
    head = reverseList(head);
    printList(head);

    // Chunk reverse list
    printf("Enter size of chunk to reverse\n");
    int k;
    scanf("%i", &k);

    // Check if chunk is too large
    if (k > n)
        return 1;

    head = chunkReverseList(head, k);
    printList(head);

    // Free linked list
    freeList(head);
    return 0;
}