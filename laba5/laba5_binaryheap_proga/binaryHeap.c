//
// Created by Nikita on 24.04.2021.
//
#include <stdio.h>
#include <stdlib.h>
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

    heap->list[++heap->cntElements] = key;
    bubbleUp(heap, heap->cntElements);
}

void swap(minBinaryHeap heap, int i, int j) {
    //assert(i>=1 && i<=heap->cntElements && j>=1 && j<=heap->cntElements);
    int temp = heap->list[i];
    heap->list[i] = heap->list[j];
    heap->list[j] = temp;
}

void bubbleUp(minBinaryHeap heap, int index) {
    //assert(index>=1 && index<=heap->cntElements);
    int parentIndex = index/2;
    if (index > 1 && heap->list[index] < heap->list[parentIndex]) { //???
        swap(heap, parentIndex, index);
        bubbleUp(heap, parentIndex);
    }
}

void bubbleDown(minBinaryHeap heap, int index) {
    //assert(index>=1 && index<=heap->cntElements);
    //while (2*index <= heap->cntElements) {
        int x = 2 * index;
        if (x <= heap->cntElements) {
            if (x+1 <= heap->cntElements && heap->list[x + 1] < heap->list[x]) {
                x++;
            }
        /*if (x < heap->cntElements && heap->list[x + 1] < heap->list[x]) {
            x++;
        }*/
        if (heap->list[index] > heap->list[x]) {
            swap(heap, index, x);
            bubbleDown(heap, x);
        }
        /*if (heap->list[index] <= heap->list[x]) {
            break;
        }
        swap(heap, index,x);*/
    }
}

void increaseArray(minBinaryHeap heap) {
    int newStorage = 2 * heap->storage;
    int *newKeyArr = (int*) malloc(sizeof(int) * (newStorage + 1));
    for (int i = FIRST_INDEX; i <= heap->cntElements; i++) {
        newKeyArr[i] = heap->list[i];
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
        heap->list[j + 1] = keyArray[j];
    }

    for (int j = (heap->storage + 1) / 2; j > 0; j--) {
        bubbleDown(heap, j);
    }
    return heap;
}

int findSmallestElement(minBinaryHeap heap) {
    return heap->list[FIRST_INDEX];
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
    if (heap->cntElements <= 0) return TRUE
    else return FALSE;
}

int getElement(minBinaryHeap heap, int index) {
    return heap->list[index];
}

int contains(minBinaryHeap heap, int element) {
    for (int i = FIRST_INDEX; i <= heap->cntElements; i++) {
        if (heap->list[i] == element) {
            return TRUE;
        }
    }
    return FALSE;
}

int* getHeapList(minBinaryHeap heap) {
    return heap->list;
}





