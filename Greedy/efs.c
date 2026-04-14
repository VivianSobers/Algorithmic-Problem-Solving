#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct event
{
    int start;
    int end;
    char *name;
}event;
/*
heapsort function sorts events in ascending order of their end time
First we contruct max heap and then when we extract the root and place it at the end of the array
We again heapify and repeat the process until we have sorted the array
*/

/*
Top down approach to heapify the array
*/
void heapify(event *events, int n, int i)
{
    int j,c;
    j = i;
    c = 2*j +1;
    event key = events[j];
    while(c<n)
    {
        if(c+1<n && events[c].end < events[c+1].end)
            c++;
        if(key.end < events[c].end)
        {
            events[j] = events[c];
            j = c;
            c = 2*j + 1;
        }
        else
            break;
    }
    events[j] = key;
}
void heapsort(event *events, int n)
{
    int i;
    //Max heap
    for(i=n/2-1; i>=0; i--)
        heapify(events, n, i);

    // extract elements one by one
    for (int i = n - 1; i > 0; i--) 
    {
        event temp    = events[0];
        events[0]     = events[i];
        events[i]     = temp;
        heapify(events, i, 0);
    }
}
/*
EFS => Early Finish Scheduling
sort events by end time, greedily
count max number of non-overlapping events
*/
int efs(event *events, int n)
{
    heapsort(events, n);
    int count = 1,i;
    int end = events[0].end;
    printf("\nSelected events:\n");
    printf("%s (start=%d end=%d)\n", events[0].name, events[0].start, events[0].end);
    for(i=1; i<n; i++)
    {
        if(events[i].start >= end)
        {
            count++;
            end = events[i].end;
            printf("%s (start=%d end=%d)\n", events[i].name, events[i].start, events[i].end);
        }
    }
    return count;
}
int main(int argc, char *argv[]) 
{
    if (argc < 2) {
        printf("Usage: ./efs <testfile>\n");
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (!f) {
        printf("Error opening file\n");
        return 1;
    }
    int n;
    fscanf(f, "%d", &n);

    event *events = (event *)calloc(n, sizeof(event));
    for (int i = 0; i < n; i++) {
        events[i].name = (char *)calloc(MAX, sizeof(char));
        fscanf(f, "%s %d %d", events[i].name, &events[i].start, &events[i].end);
    }

    int result = efs(events, n);
    printf("Maximum non-overlapping events: %d\n", result);
    printf("\n");
    for (int i = 0; i < n; i++)
        free(events[i].name);
    free(events);
    fclose(f);
    return 0;
}