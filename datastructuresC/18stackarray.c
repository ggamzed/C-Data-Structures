/* bunu linked list ile yapmak istersek
contrat will be the same as 18stackarray but we are going to do it with linkedlist.
so the main function will be the same (main function will never need to know)
usb interface will be the same
*/
#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 5

typedef struct _Stack
{
    int elems[CAPACITY];
    int depth;
}Stack;

void ClearStack();
void InitStack(Stack* s)
{
    // we need to initialize stack first
    ClearStack(s);
}

void ClearStack(Stack* s)
{
    // clear stack
    s->depth = 0;
}

int IsStackEmpty(Stack* s)
{
    return s->depth == 0;
}

int GetTopElementOfTheStack(Stack* s)
{
    return --s->depth;  //bu şekilde yapınca depth-1 i return ediyor, s->depth-- şeklinde yapınca depth i return ediyor sonra 1 çıkarıyor
}

int IsStackFull(Stack* s)
{
    return s->depth == CAPACITY;
}

int GetStackSize(Stack* s)
{
    return s->depth;
}

void PushToStack(Stack* s, int elem)
{
    /*  if(s->depth == CAPACITY){
        printf("The Stack OverFlow!\n");
        exit(1);    bunu her lazım olduğunda tekrardan yazmak yerine fonksiyon haline getirdik
    } */
    if(IsStackFull(s)){
        printf("Stack OverFlow!\n");
        exit(1);
    }
    s->elems[s->depth++] = elem;  // bu elem i depth in olduğu yere ata, daha sonra depth i 1 arttır
    
}

int PopFromStack(Stack* s)
{
    if(IsStackEmpty(s)){
        printf("Stack is empty!\n");
        exit(1);
    }
    return s->elems[--s->depth];
}

int main()
{
    Stack s1, s2, s3;
    InitStack(&s1);

    printf("is Stack Empty: %d  Stack size: %d \n", IsStackEmpty(&s1), GetStackSize(&s1));

    PushToStack(&s1, 10);
    printf("is Stack Empty: %d  Stack size: %d \n", IsStackEmpty(&s1), GetStackSize(&s1));

    PushToStack(&s1, 20);
    printf("is Stack Empty: %d  Stack size: %d \n", IsStackEmpty(&s1), GetStackSize(&s1));

    int topElem = PopFromStack(&s1);
    printf("is Stack Empty: %d  Stack size: %d  Pop from stack: %d \n", IsStackEmpty(&s1), GetStackSize(&s1), topElem);
    
    //ClearStack(&s1);

    topElem = PopFromStack(&s1);
    printf("is Stack Empty: %d  Stack size: %d  Pop from stack: %d \n", IsStackEmpty(&s1), GetStackSize(&s1), topElem);
    
    
    PushToStack(&s1, 10);
    printf("is Stack Empty: %d  Stack size: %d \n", IsStackEmpty(&s1), GetStackSize(&s1));
    PushToStack(&s1, 10);
    printf("is Stack Empty: %d  Stack size: %d \n", IsStackEmpty(&s1), GetStackSize(&s1));
    PushToStack(&s1, 10);
    printf("is Stack Empty: %d  Stack size: %d \n", IsStackEmpty(&s1), GetStackSize(&s1));
    PushToStack(&s1, 10);
    printf("is Stack Empty: %d  Stack size: %d \n", IsStackEmpty(&s1), GetStackSize(&s1));
    
    PushToStack(&s1, 10);
    printf("is Stack Empty: %d  Stack size: %d \n", IsStackEmpty(&s1), GetStackSize(&s1));
    

}