#include<stdio.h>
#include<stdlib.h>
/*
Partition array b into 3 parts based on pivot value:
1. Elements less than pivot go to less[]
2. Elements equal to pivot go to equal[]
3. Elements greater than pivot go to greater[]
*/
void partition(int b[], int m, int pivot, 
                int less[], int *lsize,
                int equal[], int *esize,
                int greater[], int *gsize) 
{
    *lsize = *esize = *gsize = 0; 
    int i;
    for(i=0;i<m;i++)
    {
        if(b[i]<pivot)
            less[(*lsize)++] = b[i];
        else if(b[i]==pivot)
            equal[(*esize)++] = b[i];
        else
            greater[(*gsize)++] = b[i];
    }
}
/*
Dual Array Partitioning(DAP)
Used to count elements in array B that are in array A using divide and conquer
A is sorted, B is unsorted
Partitions B by using pivot = A[median]
*/
int dap(int A[], int n, int B[], int m)
{
    //base case
    if(n==0 || m==0)
        return 0;
    
    //Fining pivot
    int mid = n/2;
    int pivot = A[mid];

    //Creating less, equal and greater arrays
    int *less = (int*) calloc(m, sizeof(int));
    int *equal = (int*) calloc(m, sizeof(int));
    int *greater = (int*) calloc(m, sizeof(int));
    int lsize, esize, gsize;

    //Partitioning B into less, equal and greater
    partition(B, m, pivot, less, &lsize, equal, &esize, greater, &gsize);

    //Recurse of left half of A
    int left = dap(A, mid, less, lsize);

    //Recurse on right half of A
    int right = dap(A+mid+1, n-mid-1, greater, gsize);

    free(less);
    free(equal);
    free(greater);
    return left+esize+right;
}
int main(int argc, char *argv[]) 
{
    if (argc < 2) 
    {
        printf("Usage: ./dap <testfile>\n");
        return 1;
    }
    FILE *f = fopen(argv[1], "r");
    if (!f) {
        printf("Error opening file\n");
        return 1;
    }

    int n, m;
    fscanf(f, "%d", &n);
    int *A = (int *) calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
        fscanf(f, "%d", &A[i]);

    fscanf(f, "%d", &m);
    int *B = (int *) calloc(m, sizeof(int));
    for (int i = 0; i < m; i++)
        fscanf(f, "%d", &B[i]);

    int result = dap(A, n, B, m);
    printf("Count: %d\n", result);
    free(A);
    free(B);
    fclose(f);
    return 0;
}