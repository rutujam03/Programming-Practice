
#include <stdio.h>

#define V 4
#define INF 999

int main()
{
    int graph[V][V] = {
        {0, 2, 3, INF},
        {2, 0, 1, 4},
        {3, 1, 0, 1},
        {INF, 4, 1, 0}
    };

    int dist[V], visited[V] = {0};
    int source = 0;

    for (int i = 0; i < V; i++)
        dist[i] = INF;

    dist[source] = 0;

    for (int count = 0; count < V; count++)
    {
        int min = INF, u = -1;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && graph[u][v] != INF &&
                graph[u][v] != 0 &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Shortest distances from source %d:\n", source);

    for (int i = 0; i < V; i++)
        printf("Vertex %d = %d\n", i, dist[i]);

    return 0;
}
