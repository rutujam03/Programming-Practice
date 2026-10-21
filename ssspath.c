
#include <stdio.h>

#define V 4
#define E 5
#define INF 999

int main()
{
    int edges[E][3] = {
        {0, 1, 2},
        {0, 2, 3},
        {1, 2, 1},
        {1, 3, 4},
        {2, 3, 1}
    };

    int dist[V];
    int source = 0;

    for (int i = 0; i < V; i++)
        dist[i] = INF;

    dist[source] = 0;

    // Relax all edges V-1 times
    for (int i = 0; i < V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if (dist[u] != INF &&
                dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }

            // For an undirected graph, check reverse edge
            if (dist[v] != INF &&
                dist[v] + w < dist[u])
            {
                dist[u] = dist[v] + w;
            }
        }
    }

    // Check for negative-weight cycle
    for (int j = 0; j < E; j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];

        if (dist[u] != INF && dist[u] + w < dist[v])
        {
            printf("Negative-weight cycle detected\n");
            return 0;
        }
        if (dist[v] != INF && dist[v] + w < dist[u])
        {
            printf("Negative-weight cycle detected\n");
            return 0;
        }
    }

    printf("Shortest distances from source %d:\n", source);

    for (int i = 0; i < V; i++)
        printf("Vertex %d = %d\n", i, dist[i]);

    return 0;
}
