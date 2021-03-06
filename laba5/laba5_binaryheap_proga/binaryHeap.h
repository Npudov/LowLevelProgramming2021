//
// Created by Nikita on 27.04.2021.
//

#ifndef LABA5_BINARYHEAP_PROGA_BINARYHEAP_H
#define LABA5_BINARYHEAP_PROGA_BINARYHEAP_H
typedef struct strminBinaryHeap *minBinaryHeap;

minBinaryHeap init();
void deInit(minBinaryHeap);
void add(minBinaryHeap, int);
void swap(minBinaryHeap, int, int);
void bubbleUp(minBinaryHeap, int);
void bubbleDown(minBinaryHeap, int);
void increaseArray(minBinaryHeap);
minBinaryHeap sortOurHeap(int*, int);
int findSmallestElement(minBinaryHeap);
void deleteSmallestElement(minBinaryHeap);
int size(minBinaryHeap);
int isEmpty(minBinaryHeap);
int getElement(minBinaryHeap, int);
void setElement(minBinaryHeap heap, int index, int key);
int contains(minBinaryHeap, int);
int* getHeapList(minBinaryHeap);
#endif //LABA5_BINARYHEAP_PROGA_BINARYHEAP_H
