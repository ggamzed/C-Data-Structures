#include <stdio.h>

int main(){
    int *pi;   
    int x;
    pi = &x; 
    *pi =100;

    printf("%d", x);  // 100
    printf("%d", *pi);

    /*
    int* a;
    int count =3;
    a = &count;
    printf("%p ", a);
    */
};