#include <stdio.h>
#include <stdlib.h>
#include "MemoryPool.h"
typedef struct {
    size_t size;
    size_t capacity;
    int *array;

}DynamicArray;


void arrayInit(DynamicArray *array,int size);
void freeArray(DynamicArray *array);
void insertItem(DynamicArray *array,int item);
int getItem(DynamicArray *array,int index);
void deleteItem(DynamicArray *array,int index);
void printArray(DynamicArray *array);
