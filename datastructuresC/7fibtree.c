// tree visualization
/* it should look like this
fib(5)
  +--fib(4)
  |   +--fib(3)
  |   |   +--fib(2)
  |   |   |   +--fib(1)
  |   |   |   +--fib(0)
  |   |   +--fib(1)
  |   +--fib(2)
  |       +--fib(1)
  |       +--fib(0)
  +--fib(3)
      +--fib(2)
      |   +--fib(1)
      |   +--fib(0)
      +--fib(1)


*/
#include <stdio.h>
#include <stdlib.h>

unsigned long long fib(long long N, int *numOfCalls)
{
    printf("fib(%lld)\n",N);
    *numOfCalls = 1;  // at least it is 1

    if(N<=1) {
        return 1;}

    int numOfCalls_N_1 = 0;
    int numOfCalls_N_2 = 0;
    unsigned long long result = fib(N-1, &numOfCalls_N_1) + fib(N-2, &numOfCalls_N_2);  // we are calling by reference so we have to give the address &
    *numOfCalls += numOfCalls_N_1 + numOfCalls_N_2;
    return result;
}

int main()
{
    int numOfCalls;
    unsigned long long i = 5;
    unsigned long long result = fib(i, &numOfCalls);
    printf("fib(%llu) = %llu  , num of calls = %d\n" ,i , result, numOfCalls);
    
    return 0;
}