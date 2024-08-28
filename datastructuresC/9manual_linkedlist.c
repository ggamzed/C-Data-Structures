/* Create a single linked list structure - create, append(eklemek)
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node  //  (hoca _Node şeklinde yazmıstı ama öyle terminalde hata veriyor)
{
    int data;
    struct Node* next;
} Node;

void append(Node* list, int value)   // for head and data
{
    // we are appending to the end
    /* 
    1. There is no element
    2. There are some elements 
    */
}

// function to printf the elements in a list (debug)
void printList(Node* list)
{
    Node* curr = list;
    while(curr != NULL){  // or while(!curr)
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

// fonksiyon kullanmadan manual olarak liste oluşturduk
int main()
{
    Node* head = NULL;   // it does not show anywhere

    // first node olusturuyoruz
    Node* newElement = (Node*)malloc(sizeof(Node));  // newElement olusturduk ve su an datası 5 olan yeri gösteriyor
    newElement->data = 5;
    newElement->next = NULL;

    //head hala hiçbir yeri göstermiyor, bu node u bağlamak için
    head = newElement; // artık head datası 5 olan node u gösteriyor ve artık tek elemanlı bir listemiz var

    printList(head);  // 5 basar

    Node* curr = newElement;  // ilk node current oldu

    // second element added
    newElement = (Node*)malloc(sizeof(Node));
    newElement->data = 20;
    newElement->next = NULL;
    
    curr->next = newElement;  // ilk node 2. yi gösteriyor
    
    printList(head);   // 5   20 basar

    // thirth element added
    curr = newElement;  //2. node current oldu 
    newElement = (Node*)malloc(sizeof(Node));
    newElement->data = 15;
    newElement->next = NULL;  // sonuncu elemente NULL atamazsak listenin sonuna geldiğimizi anlamaz

    curr->next = newElement;  // 2. node üçüncüyü gösteriyor

    printList(head); // 5 20 15
    printList(head->next);  // 20 15
    

}
