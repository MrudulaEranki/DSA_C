#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
bool visited[MAX_VERTICES];
int vertices;

// Function to perform Depth First Search
void DFS(int vertex)
{
    printf("%d ", vertex);
    visited[vertex] = true;

    for (int i = 0; i < vertices; i++)
    {
        if (graph[vertex][i] && !visited[i])
        {
            DFS(i);
        }
    }
}

int main()
{
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    // Initialize the adjacency matrix and visited array
    for (int i = 0; i < vertices; i++)
    {
        visited[i] = false;
        for (int j = 0; j < vertices; j++)
        {
            graph[i][j] = 0;
        }
    }

    printf("Enter the adjacency matrix (1 if there's an edge, 0 otherwise):\n");
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    int startVertex;
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);

    printf("Depth First Search: ");
    DFS(startVertex);
    printf("\n");

    return 0;
}