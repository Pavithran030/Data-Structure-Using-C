/*Develop a Program for Various Searching Techniques
A telephone directory application needs to search for a specific contact’s 
phone number by their name. The contact list is stored using dynamic memory 
allocation, and the search should be efficient and work for any list size.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char phone[15];
} Contact;

void addContact(Contact **con, int *size, int *cap) {
    if (*size == *cap) {
        *cap *= 2;
        *con = (Contact *)realloc(*con, *cap * sizeof(Contact));
        if (*con == NULL) {
            printf("Memory allocation failed.\n");
            exit(1);
        }
    }

    printf("Enter name: ");
    getchar(); 
    fgets((*con)[*size].name, 50, stdin);
    (*con)[*size].name[strcspn((*con)[*size].name, "\n")] = 0;

    printf("Enter phone number: ");
    fgets((*con)[*size].phone, 15, stdin);
    (*con)[*size].phone[strcspn((*con)[*size].phone, "\n")] = 0; 

    (*size)++;
}

void searchcon(Contact *con, int size) {
    char searchNa[50];
    printf("Enter name to search: ");
    getchar(); 
    fgets(searchNa, 50, stdin);
    searchNa[strcspn(searchNa, "\n")] = 0; 

    for (int i = 0; i < size; i++) {
        if (strcmp(con[i].name, searchNa) == 0) {
            printf("Phone number: %s\n", con[i].phone);
            return;
        }
    }
    printf("Contact not found.\n");
}

int main() {
    int size = 0, cap = 2;
    Contact *con = (Contact *)malloc(cap * sizeof(Contact));
    if (con == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    int choice;
    do {
        printf("\nTelephone Directory\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(&con, &size, &cap);
                break;
            case 2:
                searchcon(con, size);
                break;
            case 3:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    free(con);
    return 0;
}
