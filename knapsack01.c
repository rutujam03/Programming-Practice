#include <stdio.h>

int max(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

int main()
{
    int n, capacity;
    int weight[10], profit[10];
    int dp[10][50];
    int i, w;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &weight[i]);

    printf("Enter profits:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &profit[i]);

    printf("Enter capacity of sack: ");
    scanf("%d", &capacity);

    // Initialize first row and column
    for(i = 0; i <= n; i++)
    {
        for(w = 0; w <= capacity; w++)
        {
            if(i == 0 || w == 0)
                dp[i][w] = 0;

            else if(weight[i - 1] <= w)
            {
                dp[i][w] = max(
                    profit[i - 1] + dp[i - 1][w - weight[i - 1]],
                    dp[i - 1][w]
                );
            }

            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    printf("Maximum Profit = %d\n", dp[n][capacity]);

    return 0;
}