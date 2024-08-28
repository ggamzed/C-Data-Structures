#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection(int a[], int N, int* numComparisons, int* numSwaps)
{
    *numComparisons = 0;
    *numSwaps = 0;
    int i, j, temp, min;
    for(i=0; i<N; i++)
    {
        min = i;
        for(j=i+1; j<N; j++)
        {
            (*numComparisons)++;
            if(a[j] < a[min]){
                min = j;
            }
        }
        (*numSwaps)++;
        temp = a[min];
        a[min] = a[i];
        a[i] = temp; 
    }
}

void insertion(int a[], int N, int* numComps, int* numSwaps)
{
    *numComps = 0;
    *numSwaps = 0;
    int i, j, v;
    for(i=1; i<N; i++)
    {
        v = a[i];
        j = i;
        while((*numComps)++ && a[j-1] > v && j > 0 )
        {
            (*numSwaps)++;
            a[j] = a[j-1];
            j--;
        }
        if(i != j){
            (*numSwaps)++;
        }
        a[j] = v;
    }
}

void bubble(int a[], int N, int* numComparisons, int* numSwaps)
{
    (*numComparisons) = 0;
    (*numSwaps) = 0;
    int i, j, temp;

    for(i=0; i<N; i++)
    {
        for(j=i+1; j<N; j++)
        {
            (*numComparisons)++;
            if(a[j] < a[i]){
                (*numSwaps)++;
                temp= a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void fillRandomValues(int a[],int N)
{
    srand(time(NULL));
    int i;
    for(i=0; i<N; i++)
    {
        a[i] = rand() % 100 +1;
    }
}

void fillOrderedValues(int a[], int N)
{
    int i;
    for(i=0; i<N; i++)
    {
        a[i] = i;
    }
    
}

void fillReverseOrdered(int a[], int N)
{
    int i;
    for(i=0; i<N; i++)
    {
        a[i] = N - i;
    }
}

void fillTheSameValues(int a[], int N)
{
    int i;
    for(i=0; i<N; i++)
    {
        a[i] = N;
    }
}

void printArrayList(int a[], int N)
{
    int i;
    for(i=0; i<N; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
// INSERTION SORT
// ( ordered or almost sorted it works linear (O(N)))

// N=100 , Random
// numComps: 2550  numSwaps: 2546
// numComps: 2409  numSwaps: 2402
// numComps: 2319  numSwaps: 2314

// N=100 , Ordered
// numComps: 99  numSwaps: 0
// numComps: 99  numSwaps: 0

// N=100 , Reverse Ordered  ( worst case)
// numComps: 5048  numSwaps: 5047
// numComps: 5048  numSwaps: 5047

// N=100 , Same Values
// numComps: 99  numSwaps: 0

// N=1000 , Random
// numComps: 244968  numSwaps: 244953
// numComps: 248846  numSwaps: 248834
// numComps: 254145  numSwaps: 254132

// N=1000 , Ordered
// numComps: 999  numSwaps: 0
// numComps: 999  numSwaps: 0
 
// N=1000 , Reverse Ordered  (worst case)
// numComps: 500498  numSwaps: 500497
// numComps: 500498  numSwaps: 500497

// N=1000 , Same Values
// numComps: 999  numSwaps: 0

// SELECTION SORT

// N=100 , Random
// numComps: 4950  numSwaps: 100
// numComps: 4950  numSwaps: 100

// N=100 , Ordered
// numComps: 4950  numSwaps: 100
// numComps: 4950  numSwaps: 100

// N=1000 , Random
// numComps: 499500  numSwaps: 1000 
// numComps: 499500  numSwaps: 1000

// N=1000 , Ordered
// numComps: 499500  numSwaps: 1000
// numComps: 499500  numSwaps: 1000

// BUBBLE SORT

// N=100 , Random
// numComps: 4950  numSwaps: 1622  
// numComps: 4950  numSwaps: 1893 
// numComps: 4950  numSwaps: 1488 

// N=100 , Ordered
// numComps: 4950  numSwaps: 0
// numComps: 4950  numSwaps: 0

// N=100 , Reverse Ordered
// numComps: 4950  numSwaps: 4950 
// numComps: 4950  numSwaps: 4950 

// N=100 , Same Values
// numComps: 4950  numSwaps: 0 
// numComps: 4950  numSwaps: 0 

// N=1000 , Random
// numComps: 499500  numSwaps: 44353
// numComps: 499500  numSwaps: 44118
// numComps: 499500  numSwaps: 43173

// N=1000 , Ordered
// numComps: 499500  numSwaps: 0 
// numComps: 499500  numSwaps: 0 

// N=1000 , Reverse Ordered
// numComps: 499500  numSwaps: 499500

// N=1000 , Same Values
// numComps: 499500  numSwaps: 0 


int main()
{
    int numComps;
    int numSwaps;

    int N = 1000;
    int a[N];
    //fillRandomValues(a, N);
    //fillOrderedValues(a,N);
    //fillReverseOrdered(a, N);
    fillTheSameValues(a, N);
    printArrayList(a, N);
    //selection(a, N, &numComps, &numSwaps);
    //insertion(a, N, &numComps, &numSwaps);
    bubble(a, N, &numComps, &numSwaps);
    printArrayList(a, N);
    printf("numComps: %d  numSwaps: %d \n", numComps, numSwaps);
}