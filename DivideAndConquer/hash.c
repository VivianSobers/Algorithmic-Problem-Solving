#include<stdio.h>
#include<stdlib.h>

#define HASH_SIZE 2000003

typedef struct hash
{
    int data;
    int flag;   
} hash;
void initialize(hash ht[])
{
    int i;
    for(i = 0; i < HASH_SIZE; i++)
    {
        ht[i].data = -1;
        ht[i].flag = -1;
    }
}
int hash_func(int key)
{
    return abs(key) % HASH_SIZE;
}
void insert(hash ht[], int key)
{
    int index = hash_func(key);
    int start = index;

    while(ht[index].flag == 1)
    {
        if(ht[index].data == key)
            return;

        index = (index + 1) % HASH_SIZE;

        if(index == start)
        {
            printf("Hash Table is full\n");
            return;
        }
    }

    ht[index].data = key;
    ht[index].flag = 1;
}
int search(hash ht[], int key)
{
    int index = hash_func(key);
    int start = index;

    while(ht[index].flag != -1)
    {
        if(ht[index].flag == 1 && ht[index].data == key)
            return 1;

        index = (index + 1) % HASH_SIZE;

        if(index == start)
            break;
    }

    return 0;
}
int hash_count(int A[], int n, int B[], int m)
{
    int i, count = 0;
    hash *ht = (hash *)calloc(HASH_SIZE, sizeof(hash));

    initialize(ht);

    for(i = 0; i < n; i++)
        insert(ht, A[i]);

    for(i = 0; i < m; i++)
        if(search(ht, B[i]))
            count++;
    free(ht);
    return count;
}

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("Usage: ./hash <testfile>\n");
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if(!f)
    {
        printf("Error opening file\n");
        return 1;
    }

    int n, m, i;

    fscanf(f, "%d", &n);
    int *A = (int *)calloc(n, sizeof(int));

    for(i = 0; i < n; i++)
        fscanf(f, "%d", &A[i]);

    fscanf(f, "%d", &m);
    int *B = (int *)calloc(m, sizeof(int));

    for(i = 0; i < m; i++)
        fscanf(f, "%d", &B[i]);

    int result = hash_count(A, n, B, m);

    printf("Count: %d\n", result);
    free(A);
    free(B);
    fclose(f);
    return 0;
}