#include "fib.h"
#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
int main() {
    system("chcp 1251");
    int k;
    printf("������� ����� ����� ���������: ");
    scanf("%d", &k);
    int result = fib(k);
    printf("������ ���� ��������� ����� �����: %d", result);
    return 0;
}
