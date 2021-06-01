//
// Created by Nikita on 24.04.2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "binaryHeap.h"
#define TRUE 1;
#define FALSE 0;
#define FIRST_INDEX 1

struct strminBinaryHeap{
    int *list;
    int storage;
    int cntElements;
};

minBinaryHeap init() {
    minBinaryHeap heap = (minBinaryHeap) malloc(sizeof(struct strminBinaryHeap));
    heap->storage = 10;
    heap->cntElements = 0;
    heap->list = (int*) malloc(sizeof(int) * (heap->storage + 1));
    return heap;
}

void deInit(minBinaryHeap heap) {
    free(heap->list);
    free(heap);
}

void add(minBinaryHeap heap, int key) {
    if (heap->cntElements == heap->storage) {
        increaseArray(heap);
    }
    setElement(heap, ++heap->cntElements, key);
    bubbleUp(heap, heap->cntElements);
}

void swap(minBinaryHeap heap, int i, int j) {
    assert(i>=1 && i<=heap->cntElements && j>=1 && j<=heap->cntElements);

    int temp = getElement(heap, i); //heap->list[i];
    setElement(heap, i, getElement(heap, j)); //heap->list[j];
    setElement(heap, j, temp);
}

void bubbleUp(minBinaryHeap heap, int index) {
    assert(index>=1 && index<=heap->cntElements);
    int parentIndex = index/2;
    if (index > 1 && getElement(heap, index) < getElement(heap, parentIndex)) {
        swap(heap, parentIndex, index);
        bubbleUp(heap, parentIndex);
    }
}

void bubbleDown(minBinaryHeap heap, int index) {
    int x = 2 * index;
    if (x <= heap->cntElements) {
        if (x+1 <= heap->cntElements && getElement(heap, x + 1) < getElement(heap, x)) {
            x++;
        }
        if (getElement(heap, index) > getElement(heap, x)) {
            swap(heap, index, x);
            bubbleDown(heap, x);
        }
    }
}

void increaseArray(minBinaryHeap heap) {
    int newStorage = 2 * heap->storage;
    int *newKeyArr = (int*) malloc(sizeof(int) * (newStorage + 1));
    for (int i = FIRST_INDEX; i <= heap->cntElements; i++) {
        setElement((minBinaryHeap) newKeyArr, i, getElement(heap, i));
    }

    free(heap->list);
    heap->list = newKeyArr;
    heap->storage = newStorage;
}

minBinaryHeap sortOurHeap(int *keyArray, int i) {
    minBinaryHeap heap = (minBinaryHeap) malloc(sizeof(struct strminBinaryHeap));
    heap->cntElements = 0;
    heap->storage = i;
    heap->list = (int*) malloc(sizeof(int) * (heap->storage + 1));
    heap->cntElements = i;
    for (int j = 0; j < i; j++) {
        setElement(heap, j + 1, keyArray[j]);
    }

    for (int j = (heap->storage + 1) / 2; j > 0; j--) {
        bubbleDown(heap, j);
    }
    return heap;
}

int findSmallestElement(minBinaryHeap heap) {
    return getElement(heap, FIRST_INDEX); //heap->list[FIRST_INDEX];
}

void deleteSmallestElement(minBinaryHeap heap) {
    swap(heap, FIRST_INDEX, heap->cntElements);
    heap->cntElements--;
    bubbleDown(heap, FIRST_INDEX);
}

int size(minBinaryHeap heap) {
    return heap->cntElements;
}

int isEmpty(minBinaryHeap heap) {
     return heap->cntElements <= 0;

}

int getElement(minBinaryHeap heap, int index) {
    assert(index >= 1 && index <= heap->cntElements);
    return heap->list[index - 1];
}

void setElement(minBinaryHeap heap, int index, int key) {
    assert(index >= 1 && index <= heap->cntElements);
    heap->list[index - 1] = key;
}

int contains(minBinaryHeap heap, int element) {
    for (int i = FIRST_INDEX; i <= heap->cntElements; i++) {
        if (getElement(heap, i) == element) {
            return TRUE;
        }
    }
    return FALSE;
}

int* getHeapList(minBinaryHeap heap) {
    return heap->list;
}


