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

Node* removeFromList(Node* list, int value)  
{                                           
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
        printf("there is no %d ! List is: ", value);
        return list;
    }  

    // 3. remove from front
    // 4. remove the only element
     if(curr == prev){   // it is the first or only element
        
        free(curr);
        return prev->next;

        /*   hoca bu sekilde yaptı ne farkı var anlamadım
        Node* temp = prev->next;
        free(curr);
        return temp;
        */
    }

    else{  // it is either a middle element or the last element

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
    head = append(head, 5);
    head = append(head, 20);
    head = append(head, 15);
    head = append(head, 42);
    

    printList(head);  // 5 20 15 42

    printf("Removing 8: ");
    head = removeFromList(head, 8); // unexisting element
    printList(head);

    // this code only remove the first 5 in the list, what happens if there is more 5?
    // we can remove them all
    // or we can remove a specific 5
    // practice for them
    printf("Removing 5: ");
    head = removeFromList(head, 5); // we are removing the first element
    printList(head);  // 20 15 42

    printf("Removing 20: ");
    head = removeFromList(head, 20); 
    printList(head);

    printf("Removing 15: ");
    head = removeFromList(head, 15); 
    printList(head);

    printf("Removing 42: ");
    head = removeFromList(head, 42);  
    printList(head);  // list becomes empty 

    


}