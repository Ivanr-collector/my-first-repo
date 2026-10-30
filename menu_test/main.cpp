#include "menu.hpp"
#include "menu_items.hpp"

int main() {
    const ivanr::MenuItem* current = &ivanr::MAIN;
    do {
        current = current->func(current);
    } while (current != nullptr);
    return 0;
}