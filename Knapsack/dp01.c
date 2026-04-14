#include<stdio.h>
#include<stdlib.h>
#include "knapsack.h"
/*
Dynamic Programming solution for 0/1 Knapsack.
Builds a 2D DP table where dp[i][j] stores the maximum
profit using the first i items with capacity j.
After filling the table, backtracking is used to print
the selected items.
*/
void dynamic_prog_01(item items[], int n, int W)
{
    //2D array aka dynamic programming table
    int dp[n+1][W+1];
    int i,j,take;

    //base case
    for(i=0; i<=n; i++)
        dp[i][0] = 0;
    for(j=0; j<=W; j++)
        dp[0][j] = 0;

    //fill the table
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=W; j++)
        {
            //dont take item i
            dp[i][j] = dp[i-1][j];

            //take item i if it fits
            if(items[i-1].weight <= j)
            {
                take = dp[i-1][j-items[i-1].weight] + items[i-1].profit;
                if(take > dp[i][j])
                    dp[i][j] = take;
            }

        }
    }
    //backtrack to find selected items
    printf("Selected items:\n");
    j = W;
    for(i=n; i>0 && j>0; i--)
    {
        if(dp[i][j] != dp[i-1][j])
        {
            printf("%s (weight=%d profit=%d)\n", items[i-1].name, items[i-1].weight, items[i-1].profit);
            j -= items[i-1].weight;
        }
    }
    printf("Maximum profit: %d\n", dp[n][W]);
    printf("\n");
}
int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("Usage: ./dp01 <testfile>\n");
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if(!f)
    {
        printf("Error opening file\n");
        return 1;
    }
    int n, W;
    fscanf(f, "%d %d", &n, &W);

    item *items = (item *)calloc(n, sizeof(item));
    for(int i = 0; i < n; i++)
        fscanf(f, "%s %d %d", items[i].name, &items[i].weight, &items[i].profit);

    dynamic_prog_01(items, n, W);
    free(items);
    fclose(f);
    return 0;
}