#include "sort.hpp"

#include <chrono>
#include <cstdlib>
#include <iostream>

#include "main.hpp"

int main() {

    biv::NamedSort funcs_arr[] = {
        {"bubble_sort_basic", biv::bubble_sort_basic},
        {"bubble_sort_with_flag", biv::bubble_sort_with_flag},
        {"bubble_sort_optimized", biv::bubble_sort_optimized},

        {"cocktail_sort", biv::cocktail_sort},
        {"cocktail_sort_advanced", biv::cocktail_sort_advanced},

        {"parity_sort", biv::parity_sort},

        {"comb_sort_gapped", biv::comb_sort_gapped},

        {"selection_sort_min", biv::selection_sort_min},

        {"insertion_sort_basic", biv::insertion_sort_basic},
        {"insertion_sort_binary", biv::insertion_sort_binary},

        {"shell_sort_gapped", biv::shell_sort_gapped},
    };

    int size;
    std::cin >> size;

    int arr_to_check[size];
    biv::generate_array(arr_to_check, size);

    int func_count = sizeof(funcs_arr) / sizeof(funcs_arr[0]);
    for (int i = 0; i < func_count; i++) {
        double func_time =
            biv::check_sort(funcs_arr[i].func, arr_to_check, size);
        std::cout << funcs_arr[i].name << ": " << func_time << " s"
                  << std::endl;
    }

    return 0;
}

double biv::check_sort(void (*sort_func)(int *arr, const int size), int *arr,
                       const int size) {
    int arr_copy[size];
    for (int i = 0; i < size; i++) {
        arr_copy[i] = arr[i];
    }

    auto start = std::chrono::steady_clock::now();
    sort_func(arr_copy, size);
    auto end = std::chrono::steady_clock::now();

    double duration = std::chrono::duration<double>(end - start).count();
    return duration;
}

void biv::generate_array(int *arr, const int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = std::rand() % 200000;
    }
}
