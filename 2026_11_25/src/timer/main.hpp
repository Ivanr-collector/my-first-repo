#pragma once

namespace biv {
struct NamedSort {
    const char *name;
    void (*func)(int *, const int);
};

double check_sort(void (*sort_func)(int *arr, const int size), int *arr,
                  const int size);
void generate_array(int *arr, const int size);
} // namespace biv
