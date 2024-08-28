/* write a recursive program to compute the largest integer less than log2 üzeri N.
(Hint: for N>1, the value of this function for N/2 is one greater than for N)
ben log_2(N) den büyük en yakın integer yaptım */
// ceil(7.6) = 8  e yuvarlar
// floor(7.6) = 7 ye yuvarlar
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// returns the largest integer less than log_2(N)
// recursion way
int f(int N)
{
    if(N < 1){  // log 2 üzeri 1  = 0 eder
        return 0;
    }

    // the value of this function for N/2 is one greater than for N
    return 1 + f(N/2);
}

// solution for iterative way
int f_iterative(int N)
{
    int count = 0;
    for(int i = 1; i <= N; i *=2){
        count ++;
    }
    return count;
}

// solution with math.h library
int f_maths(int N)    
{
    double x = log2((double)N);
    
        if(N%2 ==0 || N == 1){
            return x + 1;
        }
        else{
            return ceil(x);
        }
    
}


int main()
{
    printf("Recorsive %6c Iterative  %6c math.h\n", ' ', ' ');
    for(int i=100; i>=1; i--){
        printf("f(%d) = %d  ,   %d    ,   %d\n", i, f(i), f_iterative(i), f_maths(i));  // üç yoldan birini koy birini koy 
    }
    
    
    printf("%f\n", log2(16));   // 4 
    printf("%f\n", floor(5.6));
    printf("%f\n", ceil(5.6));
    
    

    return 0;
}