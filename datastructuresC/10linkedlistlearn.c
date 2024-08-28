/* Create a single linked list structure - create, append(eklemek)
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node  //  (hoca _Node şeklinde yazmıstı ama öyle terminalde hata veriyor)
{
    int data;
    struct Node* next;
} Node;

/*void append(Node* list, int value)   // for head and data (we are appending to the end)
{            // ^ pointer görüyorsak it is call by referance

    //1. There is no element
    if(list == NULL){   // demekki liste boş biz de yeni bir node oluşturduk

        Node* newElement = (Node*)malloc(sizeof(Node));
        newElement->data = value;
        newElement->next = NULL;

        list = newElement;  // doğru gibi gözükse de bu şekilde çalışmaz 
    }
} 
int main(){
    Node* head = NULL;
    append(head,5);
    printList(head);  // çalışmaz
}
 */
Node* append(Node* list, int value)   // for head and data (we are appending to the end)
{  

    //1. There is no element
    if(list == NULL){   // demekki liste boş biz de yeni bir node oluşturduk

        Node* newElement = (Node*)malloc(sizeof(Node));
        newElement->data = value;
        newElement->next = NULL;

        return newElement;  // append function will always return the list
    }
    //else return NULL;  (if there is no element bunu da ekle)

    //2. There are some elements
    Node* curr = list;
    while(curr != NULL && curr->next != NULL){   // 1 && 2  önce 1 i kontrol edecek sonra 2 yi yerleri değiştirirsek error verir
        curr = curr->next;                            //  çünkü curr null ise curr->next yoktur 
    }
    
    Node* newElement = (Node*)malloc(sizeof(Node));
    newElement->data = value;
    newElement->next = NULL;

    curr->next = newElement;
    return list;  // return newElement diyince yeni oluşturduğu element çıkıyor
    
    
} 

void printList(Node* list)
{
    Node* curr = list;
    while(curr != NULL){  // or while(!curr)
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main()
{
    Node* head = NULL;

    head = append(head, 12);  // liste boş fonksiyonda yeni node oluşturdu ve bunu head e atadı
    printList(head);


    head = append(head, 6);
    printList(head); 
    

}

