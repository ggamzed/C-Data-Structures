/* Create a single linked list structure - create, append(eklemek), remove
1. remove from middle
2. remove from back  -last element becomes null
3. remove from front
4. remove the only element  -head becomes null
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

Node* append(Node* list, int value)
{
    Node* newElement = (Node*)malloc(sizeof(Node));
    newElement->data = value;
    newElement->next = NULL;

    // 1. There is no element
    if(list == NULL){
        return newElement;
    }

    // 2. There are some elements
    Node* curr = list;
    while(curr != NULL && curr->next != NULL){
        curr = curr->next;
    }
    curr->next = newElement;  // yeni oluşturduğum elementi sonuncuya ekledim
    return list;
}

void removeFromList(Node* list, int value)  // ortadan siliyoruz, head değişmiyor. 
{                                           // bu yüzden Node* yerine void kullanabildik
    // 1. remove from middle
    // 2. remove from back  // curr->next is NULL (prev->next in de NULL olmasına ihtiyacımız var)
    // ikisinde de prev->next becomes curr->next
    Node* curr = list;
    Node* prev = list;
    int found = 0;

    while(curr != NULL){
        
        if(curr->data == value){
            found = 1;
            break; // break the loop
        }
        prev = curr;  // we need previous one
        curr = curr->next;
    }
    if(!found){  // if not found
        return;
    }
    prev->next = curr->next;   // data5_Node -> data15_Node (datası 20 olan node aradan cıkarmıs olduk)
    free(curr);  // datası 20 olan node u main memory den siliyoruz

}

void printList(Node* list)
{
    Node* curr = list;
    while(curr != NULL){
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main()
{
    Node* head = NULL;
    head = append(head, 5);
    head = append(head, 20);
    head = append(head, 15);
    head = append(head, 42);

    printList(head);  // 5 20 15 42

    /*removeFromList(head, 20); // we are removing from middle which is 20
    printList(head); */

    removeFromList(head, 42);  // remove from back  (head = şeklinde yapmaya gerek yok)
    printList(head);
    


}