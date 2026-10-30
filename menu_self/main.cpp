#include <iostream>
#include <cstdlib>

struct MenuItem;
const MenuItem* show_menu(const MenuItem* current);

struct MenuItem {
    const char* title; 
    const MenuItem* (*func)(const MenuItem*); 
    const MenuItem* parent;          
    const MenuItem* children;        
    int children_count;              
};

const MenuItem* action_football(const MenuItem*) { 
    std::cout << "\n>> Ура, футбол! Выход.\n"; 
    return nullptr; 
}

const MenuItem* action_exit(const MenuItem*) { 
    std::cout << "\n>> Выход из программы.\n"; 
    return nullptr; 
}

const MenuItem* action_langs(const MenuItem*) { 
    std::cout << "\n>> Изучение языков (выполнено)\n"; 
    return nullptr; 
}

const MenuItem* action_algorithms(const MenuItem*) { 
    std::cout << "\n>> Алгоритмы (выполнено)\n"; 
    return nullptr; 
}

const MenuItem* action_databases(const MenuItem*) { 
    std::cout << "\n>> Базы данных (выполнено)\n"; 
    return nullptr; 
}

const MenuItem* action_multithreading(const MenuItem*) { 
    std::cout << "\n>> Многопоточность (выполнено)\n"; 
    return nullptr; 
}

const MenuItem* action_networks(const MenuItem*) { 
    std::cout << "\n>> Сетевые технологии (выполнено)\n"; 
    return nullptr; 
}

const MenuItem* go_back(const MenuItem* current) {
    if (current->parent != nullptr) {
        return current->parent;
    }
    return nullptr;
}

const MenuItem* show_menu(const MenuItem* current) {
    std::cout << "\n=== " << current->title << " ===\n";
    
    for (int i = 1; i < current->children_count; i++) {
        std::cout << i << ". " << current->children[i].title << "\n";
    }
    std::cout << "0. " << current->children[0].title << "\n";
    
    std::cout << "> ";
    int choice;
    std::cin >> choice;

    return &current->children[choice];
}

int main() {
    MenuItem level3_children[] = {
        { "Назад", go_back, nullptr, nullptr, 0 }, 
        { "Базы данных", action_databases, nullptr, nullptr, 0 },
        { "Многопоточное программирование", action_multithreading, nullptr, nullptr, 0 },
        { "Сетевые технологии", action_networks, nullptr, nullptr, 0 }
    };

    MenuItem level3_root = { 
        "Другие технологии", 
        show_menu, 
        nullptr, 
        level3_children, 
        4 
    };

    MenuItem level2_children[] = {
        { "Назад", go_back, nullptr, nullptr, 0 }, 
        { "Изучать языки", action_langs, nullptr, nullptr, 0 },
        { "Алгоритмы", action_algorithms, nullptr, nullptr, 0 },
        { "Другие технологии", show_menu, nullptr, nullptr, 0 } 
    };

    MenuItem level2_root = { 
        "Изучать программирование", 
        show_menu, 
        nullptr, 
        level2_children, 
        4 
    };

    MenuItem level1_children[] = {
        { "Выход", action_exit, nullptr, nullptr, 0 }, 
        { "Изучать программирование", show_menu, nullptr, nullptr, 0 }, 
        { "Пойти играть в футбол", action_football, nullptr, nullptr, 0 }
    };

    MenuItem main_root = { "Главное меню", show_menu, nullptr, level1_children, 3 };

    level2_children[3].children = level3_children;
    level2_children[3].children_count = 4;

    level1_children[1].children = level2_children;
    level1_children[1].children_count = 4;

    for (int i = 0; i < 3; i++) level1_children[i].parent = &main_root;
    for (int i = 0; i < 4; i++) level2_children[i].parent = &level2_root;
    for (int i = 0; i < 4; i++) level3_children[i].parent = &level3_root;

    level2_root.parent = &main_root;
    level3_root.parent = &level2_root;

    const MenuItem* current = &main_root;
    
    while (current != nullptr) {
        current = current->func(current);
    }

    return 0;
}