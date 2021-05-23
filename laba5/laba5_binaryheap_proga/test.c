//
// Created by Nikita on 02.05.2021.
//
#include <stdio.h>
#include "binaryHeap.h"

void addTest() {
    minBinaryHeap h = init();
    add(h, 2);
    add(h, 4);
    add(h, 1);
    add(h, 8);
    int digit = getElement(h, 1);
    if (digit == 1) {
        printf("test 1 passed\n");
    }
    else {
        printf("test 1 failed\n");
    }

    if (contains(h, 9) == 0) {
        printf("test 2 passed\n");
    }
    else {
        printf("test 2 failed\n");
    }

    if (contains(h, 4) == 1) {
        printf("test 3 passed\n");
    }
    else {
        printf("test 3 failed\n");
    }

    if (size(h) == 4) {
        printf("test 4 passed\n");
    }
    else {
        printf("test 4 failed\n");
    }

    if (findSmallestElement(h) == 1) {
        printf("test 5 passed\n");
    }
    else {
        printf("test 5 failed\n");
    }

    if(isEmpty(h) == 0) {
        printf("test 6 passed\n");
    }
    else {
        printf("test 6 failed\n");
    }

    if (getElement(h, 2) == 4) {
        printf("test 7 passed\n");
    }
    else {
        printf("test 7 failed\n");
    }
}
