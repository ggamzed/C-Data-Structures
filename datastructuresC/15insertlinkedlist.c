/* create a system where you add and remove elements of 
in to/from a data structure in such a way that elements
in the structure are always kept in an ordered way
--create a linked list implementation
-create an array implementation
(for removel if the list is already ordered, when we remove elements
it will still be ordered)
20  - creating the list (insert after head)
5   - insert into front (insert after head)
10  - insert into middle (insert after prev)
42  - insert at the end (insert after prev)
5 10 20 42
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

Node* insert(Node* list, int value)
{
    Node* newElement = (Node*)malloc(sizeof(Node));
    newElement->data = value;
    newElement->next = NULL;

    // 1. there is no element
    if(list == NULL){
        // we have a list with one element now, which will be our new head
        return newElement;
    }

    // 2. there are some elements
    // 2.1. find the insert position
    Node* curr = list;
    Node* prev = list;
    while(curr != NULL)
    {
        if(curr->data >= value)
        {
            break;
        }
        
        prev = curr;
        curr = curr->next;
    }
    
    // if the new element is to be the first element
    if(prev == curr)  // insert after head       
    {                
        newElement->next = prev;  // head baslangıcta 20 yi gösteriyordu, artık head in gösterdiği yer 5 in gösteridigi yer oldu
        return newElement;         
    }
    
    // 2.2. append into middle
    newElement->next = prev->next;  // prev->next yerine curr kullanmamamızın sebebi en sona eklerken current null olabilir
    prev->next = newElement;

    return list;
}

Node* removeFromList(Node* list, int value)
{
    Node* curr = list;
    Node* prev = list;
    int found = 0;

    while(curr != NULL){
        if(curr->data == value){
            found = 1;
            break;
        }
        prev = curr;
        curr = curr->next;
    }
    if(!found){
        printf("there is no %d element on the list\n", value);
        return list;
    }

    if(prev == curr){
        free(curr);
        return prev->next;
    }
    else{
        prev->next = curr->next;
        free(curr);
        return list;
    }
    
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
    head = insert(head, 20);
    head = insert(head, 5);
    head = insert(head, 10);
    head = insert(head, 42);
    head = insert(head, 2);
    head = insert(head, 54);
    head = insert(head, 21);
    removeFromList(head, 21);
    
    
    printList(head);
}