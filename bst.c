#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

struct node {
    int val;
    struct node * left;
    struct node * right;
};
typedef struct node * nodeAddress;

// Function to insert node into BST
nodeAddress insertNode (nodeAddress root, int val) {
    // If root is pointing to NULL then create and populate new node
    if (root == NULL) {
        root = malloc(sizeof(struct node));
        root->val = val;
        root->left = NULL;
        root->right= NULL;
        return root;
    }
    // Check if value smaller or larger than node value
    if (val < root->val) {
        root->left = insertNode(root->left, val);
    } 
    if (val > root->val) {
        root->right = insertNode(root->right, val);
    }
    return root;

}

nodeAddress arrayToBST(int *a, int n) {
    if (n <= 0) {
        printf("Tree must have at least one element");
    }
    int i;
    nodeAddress root = NULL;

    // Iterate over values in the array
    for (i = 0; i < n; i++) {
        // For each value insert it into the BST
        root = insertNode(root, a[i]);
    }
    
    return root;
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
    
    // Build BST
    nodeAddress root = arrayToBST(values, n);
}