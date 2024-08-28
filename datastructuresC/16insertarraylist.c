/* create a system where you add and remove elements of 
in to/from a data structure in such a way that elements
in the structure are always kept in an ordered way
-create a linked list implementation
--create an array implementation
(for removel if the list is already ordered, when we remove elements
it will still be ordered)
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct ArrayList // _ArrayList hoca böyle yazdı
{
    int data[100];
    int numElements;
} ArrayList;

void initArrayList(ArrayList* list)
{
    list->numElements = 0;  // there is no element in the beginning
}

void printArrayList(ArrayList* list)
{
    for(int i= 0; i< list->numElements; i++){
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

void insertArrayList(ArrayList* list, int value)
{
    int pos = 0;
    int found = 0;
    int i = 0;
    for(i = 0; i < list->numElements; i++){
        if(list->data[i] >= value){
            pos = i;  // insert pozition - orn: listede 20 olsun ve 5 ekleyelim bu 5 i ekleyecegim yer pos 0
            found =1;
            break;
        }
        
    }
    if(!found){  // so it is the last element
        pos = list->numElements;
        list->data[pos] = value;
        list->numElements ++;
    }
    else{
    // we have the insertion position in "pos"
    // 1. shift remaining elements to right by 1 place
    for(i= list->numElements-1; i>=pos; i--){ // kaydırdıgımız elementi kaybetmemek icin sondan basladık
        list->data[i+1] = list->data[i];
    }
    // 2. put the value into position "pos"
    list->data[pos] = value;

    // 3. increment numElements
    list->numElements ++;
    }
}

void removeArrayList(ArrayList* list, int value)
{
    // burayı kendin yapp
}

int main()
{
    ArrayList list;
    initArrayList(&list);  // call by referance
    
    insertArrayList(&list, 20);
    insertArrayList(&list, 5);
    insertArrayList(&list, 10);
    insertArrayList(&list, 42);

    printArrayList(&list);
    
    
}