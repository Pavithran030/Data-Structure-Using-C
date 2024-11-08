// i

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100
int main() {
    char expression[MAX];
    int stack[MAX];
    int top = -1;
    printf("Enter a postfix expression: ");
    fgets(expression, sizeof(expression), stdin);

    for (int i = 0; expression[i] != '\0'; i++) {
        if (isspace(expression[i])) {
            continue;
        }
        if (isdigit(expression[i])) {
            stack[++top] = expression[i] - '0'; 
        } 
        else {
            int operand2 = stack[top--]; 
            int operand1 = stack[top--];
            switch (expression[i]) {
                case '+':
                    stack[++top] = operand1 + operand2; 
                    break;
                case '-':
                    stack[++top] = operand1 - operand2;
                    break;
                case '*':
                    stack[++top] = operand1 * operand2;
                    break;
                case '/':
                    stack[++top] = operand1 / operand2;
                    break;
                default:
                    printf("Invalid operator: %c\n", expression[i]);
                    return 1; 
            }
        }
    }
    printf("Result: %d\n", stack[top]);
    return 0;
}


// ii

#include <stdio.h>
#include <string.h>

#define MAX 100
char stack[MAX];
int top = -1;
void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    } else {
        printf("Stack overflow, cannot push '%c'\n", c);
    }
}
char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0'; 
}
void reverseString(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        push(str[i]);
    }
    for (int i = 0; i < len; i++) {
        str[i] = pop();
    }
}

int main() {
    char str[MAX];

    printf("Enter a string: \n");
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = '\0';

    reverseString(str);

    printf("Reversed string: %s\n", str);

    return 0;
}

