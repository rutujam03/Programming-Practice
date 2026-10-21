
#include <stdio.h>

#define N 4

int set[N] = {1, 2, 3, 4};
int target = 5;
int subset[N];

void sumOfSubsets(int index, int sum)
{
    if (sum == target)
    {
        printf("{ ");
        for (int i = 0; i < index; i++)
        {
            if (subset[i] == 1)
                printf("%d ", set[i]);
        }
        printf("}\n");
        return;
    }

    if (index == N || sum > target)
        return;

    // Include the current element
    subset[index] = 1;
    sumOfSubsets(index + 1, sum + set[index]);

    // Exclude the current element
    subset[index] = 0;
    sumOfSubsets(index + 1, sum);
}

int main()
{
    printf("Subsets with sum %d:\n", target);
    sumOfSubsets(0, 0);

    return 0;
}
