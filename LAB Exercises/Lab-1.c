#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *ne;
};

struct Node *head = NULL;

void add(int val) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->ne = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->ne != NULL) {
            temp = temp->ne;
        }
        temp->ne = newNode;
    }
}

void remove1(int val) {
    struct Node *temp = head, *prev = NULL;

    while (temp != NULL) {
        if (temp->data == val) {
            if (prev == NULL) {
                // Removing the head node
                head = temp->ne;
            } else {
                prev->ne = temp->ne;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->ne;
    }
    printf("Value %d not found.\n", val);
}

void display(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->ne;
    }
    printf("\n");
}

int main() {
    int choice, task;
    while (1) {
        printf("1. Add\n2. Remove specific number\n3. Display tasks\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter task: ");
                scanf("%d", &task);
                add(task);
                break;
            case 2:
                printf("Enter the task to remove: ");
                scanf("%d", &task);
                remove1(task);
                break;
            case 3:
                printf("Tasks: ");
                display(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Choice...\n");
        }
    }
    return 0;
}

