/*Implementation of Hashing Techniques
A content management system needs to store articles by their unique titles and 
ensure quick retrieval when searching for a specific article. A hash table is 
used for storing articles, with each article title being hashed for efficient access.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

typedef struct art {
    char title[100];
    char cont[1000];
    struct art *next;  
} art;

art *hashTable[TABLE_SIZE];

unsigned int hash(const char *title) {
    unsigned int hashValue = 0;
    while (*title) {
        hashValue = (hashValue << 5) + *title++;
    }
    return hashValue % TABLE_SIZE;
}

void insertart(const char *title, const char *cont) {
    unsigned int ind = hash(title);
    art *newart = (art *)malloc(sizeof(art));
    if (newart == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    strcpy(newart->title, title);
    strcpy(newart->cont, cont);
    newart->next = hashTable[ind];
    hashTable[ind] = newart;
}

art *searchart(const char *title) {
    unsigned int ind = hash(title);
    art *art = hashTable[ind];
    while (art != NULL) {
        if (strcmp(art->title, title) == 0) {
            return art;
        }
        art = art->next;
    }
    return NULL;
}

void displayart(art *art) {
    if (art == NULL) {
        printf("Article not found.\n");
    } else {
        printf("Title: %s\n", art->title);
        printf("Content: %s\n", art->cont);
    }
}

int main() {

    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }

    int choice;
    char title[100];
    char cont[1000];
    do {
        printf("\nContent Management System\n");
        printf("1. Add Article\n");
        printf("2. Search Article\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 
        switch (choice) {
            case 1:
                printf("Enter Article title: ");
                fgets(title, 100, stdin);
                title[strcspn(title, "\n")] = 0; 
                printf("Enter Article content: ");
                fgets(cont, 1000, stdin);
                cont[strcspn(cont, "\n")] = 0; 
                insertart(title, cont);
                break;
            case 2:
                printf("Enter title to search: ");
                fgets(title, 100, stdin);
                title[strcspn(title, "\n")] = 0; 
                art *art = searchart(title);
                displayart(art);
                break;
            case 3:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);
     return 0;
}


