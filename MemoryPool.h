#include <stdio.h>
#include <stdlib.h>

typedef struct {
size_t size;
size_t used;
void *pool;
}MemoryPool;
MemoryPool *createPool(size_t size);
void *allocteMemory(MemoryPool *mp, size_t size);

void freePool(MemoryPool *mp);