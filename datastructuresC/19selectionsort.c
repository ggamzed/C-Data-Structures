#include <stdio.h>
#include <time.h>
#include <stdlib.h>

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

void fillRandomValues(int a[], int N)
{
    srand(time(NULL)); // to generate random numbers 
    // bu satırı silince rand() fonksiyonu kodu her çalıştırdığımda aynı değeri döndürüyor
    
    int i;
    for(i=0; i<N; i++){
        //a[i] = rand();
        a[i] = rand() % 100 + 1; // daha kücük sayılar görmek icin, +1 de 0 görmemek icin
    }
}

void printArrayList(int a[], int N)
{
    int i;
    for(i=0; i<N; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int numComps = 0;
    int numSwaps = 0;  // burada pointer olarak yazmadık cünkü. su an actual variable lara ihtiyacımız var

    int N = 10;
    int a[N];

    int b = rand(); // srand(time(NULL)) kullanmadan önce yazdığım icin hep aynı degeri döndürüyor
    printf("%d \n", b);

    fillRandomValues(a, N); // which array? this array , how many values? N
    printArrayList(a, N);

    selection(a, N, &numComps, &numSwaps);
    printArrayList(a, N);
    printf("numComps = %d, numSwaps = %d\n", numComps, numSwaps); 
                                           // N^2/2      N       bunların sayısı hic degismiyor
     
    return 0;
}