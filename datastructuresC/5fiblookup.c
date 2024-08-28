#include <stdio.h>
#include <stdlib.h>

unsigned long long fibonacci_lookup[200] = {1,1};  // {1,1,0,0,0,0,0,0,0....}

unsigned long long fib_lookup(long long N)
{
    if(N<=1){
        return 1;
    }
    else if(fibonacci_lookup[N]!=0){   // demekki önceden hesaplanmış
        return fibonacci_lookup[N];    // tekrar hesaplamadan önceki sonucu return ediyoruz
    }
    else{
        fibonacci_lookup[N] = fib_lookup(N-1) + fib_lookup(N-2);  // hesaplanmamış, ve hesaplayız 
        return fibonacci_lookup[N];    // lookup table a ekliyoruz
    }
}

int main()
{
    int i;
    for(i=0;i<100;i++){
        printf("fib(%d) = %llu \n", i , fib_lookup(i));
    }

    return 0;
}