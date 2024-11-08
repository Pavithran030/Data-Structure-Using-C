/*Implementation of Shortest Path Algorithm
A logistics company needs to calculate the shortest route for a fleet of trucks 
to travel between multiple warehouses and client locations. The routes are 
represented as a weighted graph, and the program should allow dynamic updates as 
new destinations are added.*/


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100

typedef struct {
    int num;
    int adjmat[MAX_NODES][MAX_NODES];
} Graph;

void initGraph(Graph *graph, int num) {
    graph->num = num;
    for (int i = 0; i < num; i++)
        for (int j = 0; j < num; j++)
            graph->adjmat[i][j] = (i == j) ? 0 : INT_MAX;
}

void addEdge(Graph *graph, int src, int dest, int weight) {
    if (weight >= 0) {
        graph->adjmat[src][dest] = weight;
        graph->adjmat[dest][src] = weight;
    } else {
        printf("Invalid edge weight.\n");
    }
}

int minDistance(int dist[], int visited[], int num) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < num; v++)
        if (!visited[v] && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void dijkstra(Graph *graph, int src) {
    int num = graph->num, dist[MAX_NODES], visited[MAX_NODES] = {0};
    for (int i = 0; i < num; i++) dist[i] = INT_MAX;
    dist[src] = 0;

    for (int count = 0; count < num - 1; count++) {
        int u = minDistance(dist, visited, num);
        visited[u] = 1;
        for (int v = 0; v < num; v++)
            if (!visited[v] && graph->adjmat[u][v] != INT_MAX && dist[u] != INT_MAX &&
                dist[u] + graph->adjmat[u][v] < dist[v])
                dist[v] = dist[u] + graph->adjmat[u][v];
    }

    printf("Shortest distances from location %d:\n", src);
    for (int i = 0; i < num; i++)
        printf("Location %d: %d\n", i, dist[i] == INT_MAX ? -1 : dist[i]);

}

int main() {
    int num, num_edges, src, choice;
    Graph graph;

    printf("Enter the number of locations: ");
    scanf("%d", &num);
    if (num <= 0 || num > MAX_NODES) return 1;

    initGraph(&graph, num);
    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    for (int i = 0; i < num_edges; i++) {
        int src, dest, weight;
        printf("Enter source, destination, and weight for edge %d: ", i + 1);
        scanf("%d %d %d", &src, &dest, &weight);
        if (src >= 0 && src < num && dest >= 0 && dest < num) {
            addEdge(&graph, src, dest, weight);
        } else {
            printf("Invalid location.\n");
            i--;
        }
    }

    printf("Enter the starting location for the trucks: ");
    scanf("%d", &src);
    if (src < 0 || src >= num) return 1;

    while (1) {
        printf("\nDo you want to add a new route? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);
        if (choice == 0) break;

        int new_src, new_dest, new_weight;
        printf("Enter new source, destination, and weight: ");
        scanf("%d %d %d", &new_src, &new_dest, &new_weight);
        if (new_src >= 0 && new_src < num && new_dest >= 0 && new_dest < num) {
            addEdge(&graph, new_src, new_dest, new_weight);
        } else {
            printf("Invalid location.\n");
        }
    }

    printf("\nRe-calculating shortest paths from location %d...\n", src);
    dijkstra(&graph, src);

    return 0;
}


