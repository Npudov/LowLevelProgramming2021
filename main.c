#include "fib.h"
#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
int main() {
    system("chcp 1251");
    int k;
    printf("Введите номер члена Фибоначчи: ");
    scanf("%d", &k);
    int result = fib(k);
    printf("Данный член Фибоначчи будет равен: %d", result);
    return 0;
}
