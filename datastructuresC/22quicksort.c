#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// teorik olarak bu sekilde ama kod bir kac sayıyı dısarıda bırakarak sıralıyor
// bir ara bakarsın

void insertion_for_Qsort(int a[], int left, int right)
{
    int i, j, v;
    for(i=left+1; i<right; i++)
    {
        v = a[i];
        j = i;
        while(a[j-1] > v && j > 0 )
        {
            // shifting towards right
            a[j] = a[j-1];
            j--;
        }
        // actual insertion
        a[j] = v;
    }
}

void fillRandomValues(int a[], int N)
{
    srand(time(NULL));
    int i;
    for(i=0; i<N; i++)
    {
        a[i] = rand() % 100 + 1;
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

void Swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int Median3(int A[], int Left, int Right)
{
    int Center = (Left + Right) / 2;

    if(A[Left] > A[Center])
        Swap(&A[Left], &A[Center]);
    
    if(A[Left] > A[Right])
        Swap(&A[Left], &A[Right]);
    
    if(A[Center] > A[Right])
        Swap(&A[Center], &A[Right]);

    Swap(&A[Center], &A[Right-1]);
    return A[Right-1];
}

void Qsort(int A[], int Left, int Right)
{
    int i, j;
    int Pivot;

    if(Left + 10 <= Right)
    {
        Pivot = Median3(A, Left, Right);

        i = Left;
        j = Right-1;
        for( ; ; )
        {
            while(A[++i] < Pivot){ };
            while(A[--j] > Pivot){ };
            if(i<j)
                Swap(&A[i], &A[j]);
            else   
                break;
        }
        Swap(&A[i], &A[Right-1]);
        Qsort(A, Left, i-1);
        Qsort(A, i+1, Right);
    }
    else
        insertion_for_Qsort(A, Left, Right);
}
int main()
{
    int N = 10;
    int a[N];
    fillRandomValues(a, N);
    printArrayList(a, N);

    Qsort(a, 0, N-1);
    printArrayList(a, N);
}