/*A library management system needs to sort the titles of books alphabetically in 
an efficient manner. The program should dynamically allocate memory for storing 
the book titles and use a suitable sorting algorithm to handle a large number of books.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quickSort(char **titles, int left, int right) {
    int i = left, j = right;
    char *pivot = titles[(left + right) / 2];
    char *temp;

    while (i <= j) {
        while (strcmp(titles[i], pivot) < 0)
            i++;
        while (strcmp(titles[j], pivot) > 0)
            j--;
        if (i <= j) {
            temp = titles[i];
            titles[i] = titles[j];
            titles[j] = temp;
            i++;
            j--;
        }
    }

    if (left < j)
        quickSort(titles, left, j);
    if (i < right)
        quickSort(titles, i, right);
}

int main() {
    int n;
    printf("Enter the number of books: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of books.\n");
        return 1;
    }
    char **titles = (char **)malloc(n * sizeof(char *));
    if (titles == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the titles of the books:\n");
    getchar();  
    for (int i = 0; i < n; i++) {
        titles[i] = (char *)malloc(100 * sizeof(char)); 
        if (titles[i] == NULL) {
            printf("Memory allocation failed.\n");
            for (int j = 0; j < i; j++) 
                free(titles[j]);
            free(titles);
            return 1;
        }
        printf("Title %d: ", i + 1);
        fgets(titles[i], 100, stdin);
        titles[i][strcspn(titles[i], "\n")] = 0; 
    }

    quickSort(titles, 0, n - 1);

    printf("\nSorted book titles:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", titles[i]);
    }
    for (int i = 0; i < n; i++) {
        free(titles[i]);
    }
    free(titles);

    return 0;
}

