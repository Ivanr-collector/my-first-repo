#pragma once

namespace biv {
void bubble_sort_basic(int *arr, const int size);
void bubble_sort_with_flag(int *arr, const int size);
void bubble_sort_optimized(int *arr, const int size);

void cocktail_sort(int *arr, const int size);
void cocktail_sort_advanced(int *arr, const int size);

void parity_sort(int *arr, const int size);

void comb_sort_gapped(int *arr, const int size);

void selection_sort_min(int *arr, const int size);

void insertion_sort_basic(int *arr, const int size);
void insertion_sort_binary(int *arr, const int size);

void shell_sort_gapped(int *arr, const int size);
} // namespace biv
