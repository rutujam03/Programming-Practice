#include <stdio.h>

int parent[10];

int find(int i)
{
    while (parent[i] != i)
        i = parent[i];

    return i;
}

void unionSet(int i, int j)
{
    int a = find(i);
    int b = find(j);

    parent[a] = b;
}

int main()
{
    int cost[10][10];
    int n, i, j;
    int edges = 0, minCost = 0;
    int u, v, min;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    for (i = 0; i < n; i++)
        parent[i] = i;

    printf("\nEdges in Minimum Spanning Tree:\n");

    while (edges < n - 1)
    {
        min = 999;

        // Find minimum edge
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        // Check for cycle
        if (find(u) != find(v))
        {
            printf("%d - %d = %d\n", u, v, min);

            minCost += min;
            unionSet(u, v);
            edges++;
        }

        // Remove selected edge
        cost[u][v] = 999;
        cost[v][u] = 999;
    }

    printf("Minimum Cost = %d\n", minCost);

    return 0;
}