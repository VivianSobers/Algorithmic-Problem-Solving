#ifndef KNAPSACK_H
#define KNAPSACK_H

#define MAX_NAME  100

typedef struct item {
    char name[MAX_NAME];
    int weight;
    int profit;
} item;

#endif