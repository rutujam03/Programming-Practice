
#include <stdio.h>

#define N 3

int main()
{
    int keys[N] = {10, 20, 30};
    int freq[N] = {3, 2, 4};
    int cost[N][N] = {0};

    // Cost of subtrees containing one key
    for (int i = 0; i < N; i++)
        cost[i][i] = freq[i];

    // Calculate costs for larger subtrees
    for (int length = 2; length <= N; length++)
    {
        for (int i = 0; i <= N - length; i++)
        {
            int j = i + length - 1;
            cost[i][j] = 999999;

            int sum = 0;

            for (int k = i; k <= j; k++)
                sum += freq[k];

            for (int r = i; r <= j; r++)
            {
                int left = (r > i) ? cost[i][r - 1] : 0;
                int right = (r < j) ? cost[r + 1][j] : 0;

                int total = left + right + sum;

                if (total < cost[i][j])
                    cost[i][j] = total;
            }
        }
    }

    printf("Minimum Search Cost = %d\n", cost[0][N - 1]);

    return 0;
}
