#include<stdio.h>
#include<stdlib.h>
#include "knapsack.h"
/*
Compare function for qsort where we sort the profit to weight ratio of items
in descending order.
*/
int compare(const void *a, const void *b)
{
    float r1 = ((item*)a)->profit / (float)((item*)a)->weight;
    float r2 = ((item*)b)->profit / (float)((item*)b)->weight;
    if(r1 < r2) 
        return 1;
    else if(r1 > r2) 
        return -1;
    return 0;
}
/*
Greedy solution for fractional knapsack.
Items are sorted in descending order of profit-to-weight ratio.
The algorithm picks items fully while capacity allows,
and takes a fraction of the next item if needed to maximize profit.
*/
void frac_greedy(item items[], int n, int W)
{
    int i;
    //sort items by ratio in descending order
    qsort(items, n, sizeof(item), compare);

    float total_profit = 0.0;
    int remaining = W;
    printf("Selected items:\n");

    for(i=0; i<n; i++)
    {
        if(items[i].weight <= remaining) //take fully
        {
            total_profit += items[i].profit;
            remaining -= items[i].weight;
            printf("%s: taken fully (profit=%d)\n", items[i].name, items[i].profit);
        }
        else //take fraction
        {
            float frac = (float)remaining / items[i].weight;
            total_profit += frac * items[i].profit;
            printf("%s: taken %.2f%% (profit=%.2f)\n", items[i].name, frac * 100, frac * items[i].profit);
            remaining = 0;
            break;
        }
    }
    printf("Maximum profit: %.2f\n", total_profit);
    printf("\n");
}
int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("Usage: ./frac_greedy <testfile>\n");
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

    frac_greedy(items, n, W);
    free(items);
    fclose(f);
    return 0;
}