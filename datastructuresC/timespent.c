#include <stdio.h>
#include <time.h>

int main(){
    int sum = 0;
    int N;
    
    clock_t begin = clock();

    for(int i =0; i<N;i++)   /* this for loop took 0.000006 time */
    sum++;

    clock_t end = clock();
    double time_spent = (double)(end-begin) / CLOCKS_PER_SEC;

    printf("%lf",time_spent);

    
}