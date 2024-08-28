#include <stdio.h>
#include <time.h>

int main()
{
    int num;
    int fac=1;
    scanf("%d",&num);

    clock_t begin = clock();
    for(int i=2; i<=num;i++){   
        fac = fac*i;
    }
    clock_t end = clock();
    double time_spent = (double)(end-begin) / CLOCKS_PER_SEC;

    printf("%d",fac);
    printf("\n%lf", time_spent);
}