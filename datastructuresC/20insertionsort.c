/* insertion sort*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion(int a[], int N, int *numComps, int* numSwaps)
{
    *numComps = 0;
    *numSwaps = 0;
    int i, j, v;
    for(i=1; i<N; i++)
    {
        v = a[i];
        j = i;
        while((*numComps)++ && a[j-1] > v && j > 0) // for safety we add j > 0
        {  // bool bakımından hep 1 döndüreceği için sorun olmaz
            // shifting towards right
            (*numSwaps)++;
            a[j] = a[j-1];
            j--;
        }
        // actual insertion
        if(i != j){
            (*numSwaps)++;
        }
        a[j] = v;

    }
}

void fillRandomValues(int a[], int N)
{
    srand(time(NULL));

    int i;
    for(i=0; i<N; i++){
        a[i] = rand() % 100 + 1;
    }

}

void printfArrayValues(int a[], int N)
{
    int i;
    for(i=0; i<N; i++){
        printf("%d  ", a[i]);
    }
    printf("\n");
}

int main()
{
    int numComps;
    int numSwaps;

    int N=100;
    int a[N];
    fillRandomValues(a, N);
    printfArrayValues(a, N);
    insertion(a, N, &numComps, &numSwaps);
    printfArrayValues(a, N);
    printf("numComps = %d, numSwaps = %d\n", numComps, numSwaps);
                                            // N^2/4     N^2/4

    /*
    int a=10;
    int *p;
    p=&a;
    printf("%d\n",*p);  //p nin gösterdiği yeri basar
    // printf("%d\n",p);   // p nin degerini yani p nin gösterdigi yerin adresini basar
    printf("%d\n",a);    // a nın degerini basar
    // printf("%d\n",&a);   // a nın adresini basar
    printf("%d\n",&p);   // p nin adresini basar          */ 
                                  
    return 0;
}