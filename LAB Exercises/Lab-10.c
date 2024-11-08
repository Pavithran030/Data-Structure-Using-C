/*Implementation of Minimum Spanning Tree Algorithm
An electricity provider needs to set up power lines to connect multiple towns in 
a region. The goal is to minimize the total cost of laying down the power lines 
while ensuring all towns are connected. The towns and distances between 
them are represented as a graph, and the program should dynamically handle 
updates to the network.*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

int graph[MAX][MAX];
int n; // Number of towns

int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, min_ind;

    for (int v = 0; v < n; v++)
        if (mstSet[v] == 0 && key[v] < min)
            min = key[v], min_ind = v;

    return min_ind;
}

void printMST(int par[]) {
    int totalCost = 0;
    printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++) {
        printf("%d - %d \t%d \n", par[i], i, graph[i][par[i]]);
        totalCost += graph[i][par[i]];
    }
    printf("Total cost of laying power lines: %d\n", totalCost);
}

void primMST() {
    int par[MAX];
    int key[MAX];
    int mstSet[MAX];

    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;
    par[0] = -1;

    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = 1;

        for (int v = 0; v < n; v++)
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                par[v] = u;
                key[v] = graph[u][v];
            }
    }

    printMST(par);
}

void updateGraph() {
    int u, v, w;
    printf("Enter the two towns to update connection (0 to %d) and the new weight: ", n - 1);
    scanf("%d %d %d", &u, &v, &w);
    if (u >= 0 && v >= 0 && u < n && v < n) {
        graph[u][v] = w;
        graph[v][u] = w;
    } else {
        printf("Invalid town numbers.\n");
    }
}

int main() {
    printf("Enter the number of towns: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use 0 if no direct connection exists):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    int choice;
    do {
        printf("\n--- Menu ---\n");
        printf("1. Find Minimum Cost to Connect All Towns\n");
        printf("2. Update Connection\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                primMST();
                break;
            case 2:
                updateGraph();
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 3);

    return 0;
}

