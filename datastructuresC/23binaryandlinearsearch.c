#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection(int a[], int N, int* numComparisons, int* numSwaps)
{
    *numComparisons = 0;
    *numSwaps = 0;

    int i, j, min, temp;
    for(i = 0; i < N; i++){
        min = i;  
        for(j = i+1; j < N; j++){
            // comparisons
            (*numComparisons)++;
            if(a[j] < a[min]){
                min = j;   // position of minimum becomes j
            }
        }
        // swaps or exchanges
        (*numSwaps)++;
        temp = a[min];  
        a[min] = a[i];
        a[i] = temp;    
    }
}

void fillRandom(int a[], int N)
{
    srand(time(NULL));

    int i;
    for(i=0; i<N; i++)
    {
        a[i] = rand() % 100 + 1;
    }
}

int getRandomValue()
{
    return rand() % 100 + 1;
}

void copyArray(int a[], int b[], int N)
{       // int* a seklinde yazmadık ve main fonksiyonda & ile cagırmadık ama hala 
        // call by ref çünkü dizilerde bir bakıma pointer
        // burada yaptıklarım her yerde degisti
    int i;
    for(i=0; i<N; i++)
    {
        b[i] = a[i];
    }
}

void printArray(int a[],int N)
{
    int i;
    for(i=0; i<N; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int linearSearch(int list[], int listLength, int key)
{
    int loc; // location
    for(loc=0; loc<listLength; loc++)
   {
    if(list[loc] == key)
        return loc;
   }
   return -1; 
}

int binarySearch(int list[], int listLength, int key)
{
    int first = 0;
    int last = listLength-1;
    int mid;
    int found = 0;

    while(first<=last && !found)
    {
        mid = (first + last)/2;
        if(list[mid] == key)
            found = 1;
        else
            if(list[mid] > key)
                last = mid - 1;
            else
                first = mid + 1;
    }
    if(found)
        return mid;
    else
        return -1;
}

int main()
{
    int N=10000;
    int a[N]; // this will be sorted array
    int b[N]; // this will be unsorted array
    int numComp = 0;
    int numSwap = 0;
    fillRandom(a, N);
    copyArray(a, b, N);

    printf("Sorting...\n");
    selection(a, N, &numComp, &numSwap);
    printf("Sorted!\n");

    printf("num cumps: %d,  num swaps: %d \n", numComp, numSwap);
    printArray(a, N);
    printArray(b, N);

    // linear search
    clock_t begin = clock();
    printf("Start time for linear search: %lf \n", (double)begin/CLOCKS_PER_SEC);

    srand(42);  // same seed value
    int i;
    for(i=0; i<10000; i++)
    {
        int key = getRandomValue();  // so keys are equal
        linearSearch(b, N, key);
    }
    clock_t end = clock();
    printf("Finish time for linear search: %lf \n", (double)end/CLOCKS_PER_SEC);
    printf("Time elapsed for linear search: %lf \n\n", (double)(end-begin)/CLOCKS_PER_SEC);

    // binary search
    begin = clock();
    printf("Start time for binary search: %lf \n", (double)begin/CLOCKS_PER_SEC);

    srand(42);  // same seed value
    for(i=0; i<10000; i++)
    {
        int key = getRandomValue();  // so keys are equal
        binarySearch(a, N, key);
    }
    end = clock();
    printf("Finish time for binary search: %lf \n", (double)end/CLOCKS_PER_SEC);
    printf("Time elapsed for binary search: %lf \n", (double)(end-begin)/CLOCKS_PER_SEC);

    // buradan da görüldüğü gibi küçük sayılar için çok bir fark yokken büyük sayılarda binary daha hesaplı

    
}