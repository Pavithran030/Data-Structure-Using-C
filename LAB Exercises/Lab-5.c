/*Initialize an empty Binary Search Tree (BST) for books.
Display a menu with options to add, find, show, or exit.
Process user choices for adding a book, finding a book by ISBN, or displaying books.
Ensure books are correctly positioned in the BST based on their ISBN.
Repeat the menu and processing until the user chooses to exit.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    char title[100];
    char author[100];
    char isbn[20];
    struct Book* left;
    struct Book* right;
};

struct Book* createBook(const char* title, const char* author, const char* isbn) {
    struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    strcpy(newBook->isbn, isbn);
    newBook->left = newBook->right = NULL;
    return newBook;
}

struct Book* addBook(struct Book* root, struct Book* newBook) {
    if (root == NULL) {
        return newBook;
    }
    if (strcmp(newBook->isbn, root->isbn) < 0) {
        root->left = addBook(root->left, newBook);
    } else if (strcmp(newBook->isbn, root->isbn) > 0) {
        root->right = addBook(root->right, newBook);
    }
    return root;
}

struct Book* findBook(struct Book* root, const char* isbn) {
    if (root == NULL || strcmp(root->isbn, isbn) == 0) {
        return root;
    }
    if (strcmp(isbn, root->isbn) < 0) {
        return findBook(root->left, isbn);
    } else {
        return findBook(root->right, isbn);
    }
}

void showBooksInOrder(struct Book* root) {
    if (root == NULL) {
        return;
    }
    showBooksInOrder(root->left);
    printf("    Title : %s\n    Author: %s\n    ISBN  : %s\n", root->title, root->author, root->isbn);
    showBooksInOrder(root->right);
}

int main() {
    struct Book* root = NULL;
    int option;
    char title[100], author[100], isbn[20];

    do {
        printf("\nMenu:\n");
        printf("1. Add a new book\n");
        printf("2. Find a book by ISBN\n");
        printf("3. Show all books in sorted order\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        getchar();

        switch (option) {
            case 1:
                printf("Enter book title: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0;

                printf("Enter author name: ");
                fgets(author, sizeof(author), stdin);
                author[strcspn(author, "\n")] = 0; 

                printf("Enter ISBN number: ");
                fgets(isbn, sizeof(isbn), stdin);
                isbn[strcspn(isbn, "\n")] = 0;

                root = addBook(root, createBook(title, author, isbn));
                break;

            case 2:
                printf("Enter ISBN to find: ");
                fgets(isbn, sizeof(isbn), stdin);
                isbn[strcspn(isbn, "\n")] = 0; 

                struct Book* foundBook = findBook(root, isbn);
                if (foundBook) {
                    printf("Book Found...........");
                    printf("    Book Name: %s \n    Author     : %s  (ISBN : %s)\n", foundBook->title, foundBook->author, foundBook->isbn);
                } else {
                    printf("Book not found.\n");
                }
                break;

            case 3:
                printf("Books in sorted order:\n");
                showBooksInOrder(root);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (option != 4);

    return 0;
}



