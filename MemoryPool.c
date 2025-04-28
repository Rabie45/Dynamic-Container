#include "MemoryPool.h"


MemoryPool *createPool(size_t size){
    MemoryPool *mp= (MemoryPool *)malloc(sizeof(MemoryPool));
    if(!mp){
        printf("there is no Space \n");
        return NULL;
    }
    mp->pool = (char*)malloc(100 *size);
    if(!mp->pool){
        printf("there is no Space \n");
        free(mp);
        return NULL;
    }
    mp->size = size;
    mp->used = 0;
    return mp;
}

void *allocteMemory(MemoryPool *mp, size_t size){
if(mp->used > mp->size){
    printf("No enough space\n");
  return NULL;

}
int ptr = (char*)mp->pool + mp->used;
mp->used += size;
return &ptr;
}


void freePool(MemoryPool *mp){
    free(mp->pool);
    free(mp);
}