#include "DynamicContainer.h"

MemoryPool *mp;
void arrayInit(DynamicArray *array,int size)
{
    if(size < 0){
        printf("cant Assgin 0 size\n");
        return NULL;
    }
    mp = createPool(size);
  
    if(!mp){
        printf("Cant assign \n");
        return;
    }
    array->array = (int*) malloc(size * sizeof(int));
    array->size=0;
    array->capacity=size;
}
void insertItem(DynamicArray *array,int item){

    if(array->size == array->capacity){
        printf("No space left lets increse the size\n");
        int * check = allocteMemory(mp,array->capacity+sizeof(int));
        if(!check){
            printf("Cant insert Element\n");
            return;
        }
        
    }

    array->array[array->size++]= item;

}
int getItem(DynamicArray *array,int index)
{
    if(index >=array->size || index < 0){
        printf("Index out of bound\n");
        return -1;
    }
        return array->array[index];
}


void deleteItem(DynamicArray *array,int index){
    if(index >=array->size || index <0){
        printf("Index Out of bounds\n");
        return;
    }
    for(int i =index ; i<array->size ; i++){
        array->array[i] =array->array[i+1];

    }
    array->size--;
    
}

void printArray(DynamicArray *array){
    printf("Array elements: "); 
    for (int i = 0; i < array->size; i++) { 
        printf("%d ", array->array[i]); 
    } 
    printf("\nSize: "); 
    printf("%lu", array->size); 
    printf("\nCapacity: "); 
    printf("%lu\n", array->capacity); 
}
void freeArray(DynamicArray *array){
    free(array->array);
    free(array);
}
DynamicArray array;
int main(){
arrayInit(&array,20);
printf("%ld",array.size);
for(int i=0;i<30;i++)
insertItem(&array,i);

deleteItem(&array,3);
printArray(&array);
}