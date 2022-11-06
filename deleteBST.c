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

nodeAddress successorSearch(nodeAddress root) {
    nodeAddress successor = NULL;
    // Assume that right child is the successor
    successor = root->right;

    // Search in left children of subsequent nodes to find successor
    while (successor->left) {
        successor = successor->left;
    }
    return successor;

}


nodeAddress searchAndDelete(nodeAddress root, int val) {
    // Check if end of BST reached
    if (root == NULL)
        return NULL;

    // Search for value
    if (root->val == val) {
        // Delete value
        // If element is leaf node
        if (!root->left && !root->right) {
            free(root);
            return NULL;
        }
        // If element has two children
        else if (root->left && root->right) {
            // Find in order successor
            nodeAddress successor = successorSearch(root);
            // Replace value of successor into spot
            root->val = successor->val;
            // Delete successor from the remaining BST
            root->right = searchAndDelete(root->right, successor->val);
            // Return current node
            return root;
        }
        // If element has one child 
        else {
            // Create pointer to the child
            nodeAddress toReturn = root->left? root->left : root->right;
            free(root);
            return toReturn;
        }
    }

    if (root->val > val)
        root->left = searchAndDelete(root->left, val);
    if (root->val < val)
        root->right = searchAndDelete(root->right, val);

    return root;
}


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

    // Delete node
    int del = 0;
    printf("Enter value to delete from BST\n");
    scanf("%i", &del);

    // Call delete function
    root = searchAndDelete(root, del);
}