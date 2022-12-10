#include <stdio.h>
#include <stdlib.h>

#define max 7

struct stackNode {
    int values[max];
    int top;
};
typedef struct stackNode * stackAddress;

void print(stackAddress stack) {
    for (int i = 0; i < stack->top+1; i++) {
        printf("%d ", stack->values[i]);
    }
    printf("\n");
}

void insert(stackAddress stack, int val) {
    // Check if stack is full
    if (stack->top+1 >= max) {
        printf("Stack is full\n");
        return;
    }
    // Insert into top
    stack->top++;
    stack->values[stack->top] = val;
}

void pop (stackAddress stack) {
    printf("%d\n", stack->values[stack->top]);
    stack->top--;
}
int main () {
    // Create stack
    stackAddress stack = malloc(sizeof(struct stackNode));
    stack->top = -1;
    
    insert(stack, 1);
    print(stack);
    insert(stack, 2);
    print(stack);
    insert(stack, 3);
    print(stack);
    insert(stack, 0);
    print(stack);
    insert(stack, 4);
    print(stack);
    insert(stack, 5); 
    print(stack);
    pop(stack);
    print(stack);
    pop(stack);
    print(stack);
    pop(stack);
    print(stack);
    insert(stack, 6);
    print(stack);
    insert(stack, 7);
    print(stack);
    insert(stack, 8);
    print(stack);
    insert(stack, 9);
    print(stack);
    insert(stack, 10);
    print(stack);
    insert(stack, 10);
    print(stack);
    pop(stack);
    print(stack);
    insert(stack, 10);
    print(stack);
    return 0;
}