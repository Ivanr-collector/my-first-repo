#include <gtest/gtest.h>
#include "sort.hpp"

TEST(CocktailAdvanced, SortUnsorted) {
    int actual[] = {1, 8, 2, 5, 3, 11};
    const int actual_size = sizeof(actual) / sizeof(actual[0]);
    int expected[] = {1, 2, 3, 5, 8, 11};
    biv::cocktail_sort_advanced(actual, actual_size);
    for (int i = 0; i < actual_size; i++) ASSERT_EQ(expected[i], actual[i]);
}

TEST(CocktailAdvanced, SingleElement) {
    int actual[] = {42};
    biv::cocktail_sort_advanced(actual, 1);
    EXPECT_EQ(42, actual[0]);
}

TEST(CocktailAdvanced, AlreadySorted) {
    int actual[] = {-2, 0, 3, 7};
    const int actual_size = sizeof(actual) / sizeof(actual[0]);
    int expected[] = {-2, 0, 3, 7};
    biv::cocktail_sort_advanced(actual, actual_size);
    for (int i = 0; i < actual_size; i++) ASSERT_EQ(expected[i], actual[i]);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
