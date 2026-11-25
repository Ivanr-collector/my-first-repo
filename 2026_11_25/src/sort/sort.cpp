#include "sort.hpp"

void biv::bubble_sort_basic(int *arr, const int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int buffer = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = buffer;
            }
        }
    }
}

void biv::bubble_sort_with_flag(int *arr, const int size) {
    bool need_swap = false;
    int i = 0;
    do {
        need_swap = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int buffer = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = buffer;
                need_swap = true;
            }
        }
        i++;
    } while (need_swap);
}

void biv::bubble_sort_optimized(int *arr, const int size) {
    int end = size - 1;
    bool need_swap = true;
    do {
        need_swap = false;
        int last_swap = 0;
        for (int j = 0; j < end; j++) {
            if (arr[j] > arr[j + 1]) {
                int buffer = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = buffer;
                last_swap = j;
                need_swap = true;
            }
        }
        end = last_swap;
    } while (need_swap);
}

void biv::cocktail_sort(int *arr, const int size) {
    int begin = 0;
    int end = size - 1;
    bool need_swap = true;
    while (need_swap) {
        need_swap = false;
        for (int i = begin; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                int buffer = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = buffer;
                need_swap = true;
            }
        }
        end--;
        if (!need_swap) {
            break;
        }
        for (int i = end; i > begin; i--) {
            if (arr[i - 1] > arr[i]) {
                int buffer = arr[i - 1];
                arr[i - 1] = arr[i];
                arr[i] = buffer;
                need_swap = true;
            }
        }
        begin++;
    }
}

void biv::cocktail_sort_advanced(int *arr, const int size) {
    int begin = 0;
    int end = size - 1;
    bool need_swap = true;
    while (need_swap) {
        need_swap = false;
        int last_swap = 0;
        for (int i = begin; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                int buffer = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = buffer;
                last_swap = i;
                need_swap = true;
            }
        }
        end = last_swap;
        if (!need_swap) {
            break;
        }
        for (int i = end; i > begin; i--) {
            if (arr[i - 1] > arr[i]) {
                int buffer = arr[i - 1];
                arr[i - 1] = arr[i];
                arr[i] = buffer;
                need_swap = true;
            }
        }
        begin++;
    }
}

void biv::parity_sort(int *arr, const int size) {
    bool need_swap = true;
    do {
        need_swap = false;
        for (int i = 0; i < size - 1; i += 2) {
            if (arr[i] > arr[i + 1]) {
                int buffer = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = buffer;
                need_swap = true;
            }
        }
        for (int i = 1; i < size - 1; i += 2) {
            if (arr[i] > arr[i + 1]) {
                int buffer = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = buffer;
                need_swap = true;
            }
        }
    } while (need_swap);
}

void biv::comb_sort_gapped(int *arr, const int size) {
    double factor = 1.25;
    int gap = size - 1;
    bool another_pass = true;
    if (size < 2) {
        return;
    }
    while (gap > 1 || another_pass) {
        another_pass = false;
        for (int i = 0; i + gap < size; i++) {
            if (arr[i] > arr[i + gap]) {
                int buffer = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = buffer;
                another_pass = true;
            }
        }
        if (gap > 1) {
            gap /= factor;
            another_pass = true;
        }
    }
}

void biv::selection_sort_min(int *arr, const int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_pos = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[min_pos] > arr[j]) {
                min_pos = j;
            }
        }
        if (min_pos != i) {
            int buffer = arr[i];
            arr[i] = arr[min_pos];
            arr[min_pos] = buffer;
        }
    }
}

void biv::insertion_sort_basic(int *arr, const int size) {
    for (int i = 1; i < size; i++) {
        int j = i;
        int key_val = arr[j];
        while (j > 0 && key_val < arr[j - 1]) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = key_val;
    }
}

void biv::insertion_sort_binary(int *arr, const int size) {
    for (int i = 1; i < size; i++) {
        int key_val = arr[i];
        int begin = 0;
        int end = i - 1;
        while (begin < end) {
            int middle = (begin + end) / 2;
            if (arr[middle] > key_val) {
                end = middle;
            } else {
                begin = middle + 1;
            }
        }
        if (key_val < arr[begin]) {
            for (int j = i; j > begin; j--) {
                arr[j] = arr[j - 1];
            }
            arr[begin] = key_val;
        }
    }
}

void biv::shell_sort_gapped(int *arr, const int size) {
    int gap = size / 2;
    while (gap > 0) {
        for (int i = gap; i < size; i++) {
            int j = i;
            int key_val = arr[j];
            while (j >= gap && key_val < arr[j - gap]) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = key_val;
        }
        gap /= 2;
    }
}
