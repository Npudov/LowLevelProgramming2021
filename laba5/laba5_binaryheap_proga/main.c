#include <stdio.h>
#include <stdlib.h>
#if defined(_WIN64) || defined(_WIN32)
    #define isWin
    #include <windows.h>
#endif
#include "binaryHeap.h"

int main(int argc, char *argv[]) {
    //можно выводить русские символы в консоль
    #ifdef isWin
        SetConsoleOutputCP(CP_UTF8);
    #endif
    if (argc < 2 || argc > 3) {
        printf("Введите данные в формате: входной файл [выходной файл] (если выходного файла нет, вывод будет осуществляться в консоль)");
        getchar();
        return 1;
    }
    FILE *input;
    char *name = argv[1]; //"input.txt";
    if ((input = fopen(name, "r")) == NULL)
    {
        printf("Не удалось открыть файл");
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
        printf("Не удалось найти выходной файл. Осуществляю вывод в консоль\n");
        flag = 1; //флаг вывода в консоль
    }
    while(size(h) != 0) {
        //записываю в файл
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
