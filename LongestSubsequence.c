#include <stdio.h>

int main() {
    int numbers[10] = {27, 3, 6, 8, 9, 35, 40, 14, 16, 17};
    int counts[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    for(int j = 1; j < 10; j++) { //Начинаем смотреть на числа за выбранным числом
        for(int i = 0; i < j; i++) {
            if(numbers[j] > numbers[i] && counts[j] <= counts[i]) { //Если число больше предыдущего и длина
                counts[j] = counts[i] + 1; //последовательности совпадает, или меньше, то увеличиваем длину посл.
            }
            else {
                continue;
            }
        }
    } //Посчитали длины всевозможных последовательностей

    for(int q = 1; q < 10; q++) {
        if(counts[0] < counts[q]) {
            counts[0] = counts[q];
        }
    } //Нашли самую длинную последовательность

    printf("%d", counts[0]);
}