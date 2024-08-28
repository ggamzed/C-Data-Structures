#include <stdio.h>
#include <time.h>

int factorial(int N){   // this is a recursive function
   if(N==0) return 1;
   return N*factorial(N-1);   
}

int main()
{
    int num;
    scanf("%d",&num);
    
    clock_t begin = clock();
    printf("%d",factorial(num));   // num yerine 99999999999 girince. stack overflow kaynaklı segmentation fault veriyor
    clock_t end = clock();          // 99999999999 bu sayıyı for döngüsü ile yaptığım factorial işleminde yapınca hata vermiyor
    double time_spent = (double)(end-begin) / CLOCKS_PER_SEC;
    printf("%lf", time_spent);

    return 0;


}
/* bunun gibi basit işlemleri for döngüsü ile yapmak daha karlı memory space ve CPU süresi bakımından
#include <stdio.h>
#include <time.h>

int main()
{
    int num;
    int fac=1;
    scanf("%d",&num);

    clock_t begin = clock();
    for(int i=1; i<=num;i++){   
        fac = fac*i;
    }
    clock_t end = clock();
    double time_spent = (double)(end-begin) / CLOCKS_PER_SEC;

    printf("%d",fac);
    printf("%lf", time_spent);
}
*/