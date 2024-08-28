#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 5

/* Accessors */
/*int isEmpty();
int size();
int getFirst(); */

/* Modifiers */
/*void clear();
void addLast();
int removeFirst();  */
void ClearQueue();


typedef struct _Queue
{
    int elems[CAPACITY];
    int front;
    int back;
    int length;
} Queue;

void InitQueue(Queue* q)  
{  // initialize queue  
    ClearQueue(q);
}

void ClearQueue(Queue* q)  // size of the structure is large also we want to modifie the contents so we used a pointer
{       // eğer (Queue q) şeklinde yapsaydık sadece value yu kopyalayıp getirirdi structure ı getirmezdi
    // call by referance yaptığımız icin  asagıda degisen her sey _Queue structure ında da degisecek
    // call by value ise yaramazdı
    q->front = 0;
    q->back = 0;
    q->length = 0;
}

int IsQueueEmpty(Queue* q)
{
    return q->length == 0; // true ise 1 false ise 0 döndürecek
}

int GetQueueSize(Queue* q)
{
    return q->length;
}

void AddToQueue(Queue* q, int elem)  // void AddToQueue(int elem) ama hangi Queue?
{           // this Queue and this element
    if(q->length == CAPACITY){
        printf("Queue is full! ");
        exit(1);
    }
    q->elems[q->back++] = elem;  // elem sayısını q[0] a ekliyor sonra back i arttırıyor
    if(q->back == CAPACITY){
        q->back = 0;
    }
    q->length++;

}

int RemoveFromQueue(Queue* q)
{
    if(IsQueueEmpty(q)){
        printf("Queue is empty\n");
        exit(1);
    }
    int frontElem = q->elems[q->front];
    q->front++;
    if(q->front == CAPACITY){
        q->front = 0;
    }
    q->length--;

    return frontElem;
}

int main()
{
    Queue q1;
    InitQueue(&q1);

    printf("Is Empty: %d \n", IsQueueEmpty(&q1));
    
    printf("get Size: %d \n", GetQueueSize(&q1));
    /* örneğin burada q1.length şeklinde queue nin size ina ulasabilirdik. 
    ama baskası veya biz ileride bir gün Queue structure ı icindeki verileri
    degistirdigimizde, getSize() fonksiyonunun icini degistirdigimizde
    hicbir sorun cıkmayacak cünkü biz burada sadece fonksiyonu cagırıyoruz
    fonksiyonun icerisinde ne olduguyla ilgilenmiyoruz (biri dediki hadi burada array yerine
    linked list kullanalım basitce gidip o fonksiyonun icinde isini yapıyor
    ve bu noktada hicbir sey degismiyor) this is a safe programming style*/

    AddToQueue(&q1, 5);
    printf("Is Empty: %d  size: %d\n", IsQueueEmpty(&q1), GetQueueSize(&q1));
    
    AddToQueue(&q1, 10);
    printf("Is Empty: %d  size: %d\n", IsQueueEmpty(&q1), GetQueueSize(&q1));
    
    AddToQueue(&q1, 40);
    AddToQueue(&q1, 16);
    printf("Is Empty: %d  size: %d\n", IsQueueEmpty(&q1), GetQueueSize(&q1));

    
    // printf("%d %d %d", function1(), function2(), function3()); // printf ilk olarak function3 yi çağırır
    /* o yüzden bu şekilde yapınca önce size ı cağırıyor ve remove u cagırdıktan sonra size degisse de coktan ekrana yazmıs oluyor
    ve size hic silmemis gibi kalıyor
    RemoveFromQueue(&q1);
    printf("Remove From Queue: %d  Is Empty: %d  size: %d\n", RemoveFromQueue(&q1), IsQueueEmpty(&q1), GetQueueSize(&q1));
    */
    /* dogrusu bu sekilde
    RemoveFromQueue(&q1);
    printf("size: %d Is Empty: %d  Remove From Queue: %d\n",GetQueueSize(&q1) , IsQueueEmpty(&q1), RemoveFromQueue(&q1)); */
    // en safe yolu da bu
    int frontValue;
    frontValue = RemoveFromQueue(&q1);
    printf("Remove From Queue: %d  Is Empty: %d  size: %d\n", frontValue, IsQueueEmpty(&q1), GetQueueSize(&q1)); 
    
    
    
    
    return 0;
}