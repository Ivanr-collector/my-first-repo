#include "sortings.hpp"

void biv::bubble_sort(int* const arr, const int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void biv::my_sort(int* const arr, const int size) {
    bubble_sort(arr, size);
}
