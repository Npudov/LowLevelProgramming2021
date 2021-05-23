#include <stdio.h>
#include <stdlib.h>
#include "binaryHeap.h"

int main(int argc, char *argv[]) {
    //����� �������� ������� ������� � �������
    system("chcp 1251");
    if (argc < 2 || argc > 3) {
        printf("������� ������ � �������: ������� ���� [�������� ����] (���� ��������� ����� ���, ����� ����� �������������� � �������)");
        getchar();
        return 1;
    }
    FILE *input;
    char *name = argv[1]; //"input.txt";
    if ((input = fopen(name, "r")) == NULL)
    {
        printf("�� ������� ������� ����");
        getchar();
        return 1;
    }
    minBinaryHeap h = init();
    int num;
    int hasRead = 1;
    while (hasRead == 1) {
        hasRead = fscanf(input, "%d", &num);
        if (hasRead == 1){
            add(h, num);
        }
    }
    fclose(input);

    FILE *output;
    char *nameOutput = argv[2];//output.txt
    output = fopen(nameOutput, "w");
    int flag = 0;
    if (output == NULL) {
        printf("�� ������� ����� �������� ����. ����������� ����� � �������\n");
        flag = 1; //���� ������ � �������
    }
    while(size(h) != 0) {
        //��������� � ����
        int element = findSmallestElement(h);
        if (flag == 0) {
            fprintf(output, "%d ", element);
        }
        else {
            printf("%d ", element);
        }
        deleteSmallestElement(h);
    }
    deInit(h);
    getchar();
    fclose(output);
    return 0;
}
