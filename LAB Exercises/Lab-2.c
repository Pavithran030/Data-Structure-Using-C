#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_SIZE 100

struct stack {
    char urls[MAX_SIZE][100];
    int top;
};

void initialize(struct stack *stack) {
    stack->top = -1;
}

bool isFull(struct stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

bool isEmpty(struct stack *stack) {
    return stack->top == -1;
}

void push(struct stack *stack, const char *url) {
    if (isFull(stack)) {
        printf("Stack is full\n");
        return;
    }
    stack->top++;
    strcpy(stack->urls[stack->top], url);
}

void pop(struct stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    stack->top--;
}

void display(struct stack *stack) {
    if (isEmpty(stack)) {
        printf("History is empty\n");
        return;
    }
    printf("Current history:\n");
    for (int i = 0; i <= stack->top; i++) {
        printf("%s\n", stack->urls[i]);
    }
}

int main() {
    struct stack history;
    initialize(&history);
    int choice;
    char url[100];

    while (1) {
        printf("\nMenu\n1. Visit new URL\n2. Go back (pop last URL)\n3. Display history\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the URL: ");
                scanf("%s", url);
                push(&history, url);
                break;
            case 2:
                pop(&history);
                break;
            case 3:
                display(&history);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100 

typedef struct {
    char data[MAX_SIZE]; 
    int top;             
} Stack;

void initialize(Stack* stack);
bool isFull(Stack* stack);
bool isEmpty(Stack* stack);
void push(Stack* stack, char element);
char pop(Stack* stack);
bool isBalanced(const char* expression);

int main() {
    char expression[MAX_SIZE];

    printf("Enter an expression: ");
    scanf("%99s", expression); 

    if (isBalanced(expression)) {
        printf("The expression is balanced.\n");
    } else {
        printf("The expression is not balanced.\n");
    }

    return 0;
}

void initialize(Stack* stack) {
    stack->top = -1;
}

bool isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, char element) {
    if (!isFull(stack)) {
        stack->data[++stack->top] = element; 
    }
}

char pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top--]; 
    }
    return '\0'; 
}

bool isBalanced(const char* expression) {
    Stack stack;
    initialize(&stack);
    
    for (int i = 0; expression[i] != '\0'; i++) {
        char current = expression[i];
        if (current == '(' || current == '{' || current == '[') {
            push(&stack, current);
        }
        else if (current == ')' || current == '}' || current == ']') {
            if (isEmpty(&stack)) {
                return false; 
            }
            char top = pop(&stack);
            if ((current == ')' && top != '(') ||
                (current == '}' && top != '{') ||
                (current == ']' && top != '[')) {
                return false; // Unbalanced
            }
        }
    }
    return isEmpty(&stack);
}

