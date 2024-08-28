#include <stdio.h>
int fib(int N)
{
    if(N<=1){       
        return 1;   
    }
    return fib(N-1) + fib(N-2);
}

int main()
{
    int num;
    scanf("%d",&num);
    printf("%d",fib(num));
}