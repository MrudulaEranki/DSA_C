#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
bool visited[MAX_VERTICES];
int vertices;

// Function to perform Breadth First Search
void BFS(int startVertex)
{
    int queue[MAX_VERTICES];
    int front = 0;
    int rear = -1;

    // Enqueue the starting vertex and mark it as visited
    queue[++rear] = startVertex;
    visited[startVertex] = true;

    printf("Breadth First Search: ");
    while (front <= rear)
    {
        int currentVertex = queue[front++];

        printf("%d ", currentVertex);

        for (int i = 0; i < vertices; i++)
        {
            if (graph[currentVertex][i] && !visited[i])
            {
                queue[++rear] = i;
                visited[i] = true;
            }
        }
    }
}

int main()
{
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
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
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    BFS(startVertex);
    printf("\n");

    return 0;
}