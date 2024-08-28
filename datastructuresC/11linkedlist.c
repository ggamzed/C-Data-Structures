/* Create a single linked list structure - create, append(eklemek)
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
    head = append(head, 6);
    head = append(head, 8);
    head = append(head, 12);
    head = append(head, 17);

    printList(head);  // 6 8 12 17

}