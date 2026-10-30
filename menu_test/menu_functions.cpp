#include <iostream>
#include <limits>
#include "menu_functions.hpp"

const ivanr::MenuItem* ivanr::show_menu(const MenuItem* current) {
    if (current->heading != nullptr) {
        std::cout << '\n' << current->heading << std::endl;
    }

    for (int i = 1; i < current->children_count; ++i) {
        std::cout << current->children[i]->title << std::endl;
    }
    std::cout << current->children[0]->title << std::endl;
    std::cout << "Ваш выбор> ";

    int user_input = 0;
    if (!(std::cin >> user_input)) {
        if (std::cin.eof()) {
            return nullptr;
        }

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ошибка: нужно ввести число" << std::endl;

        return current;
    }

    if (user_input < 0 || user_input >= current->children_count) {
        std::cout << "Нет такого пункта" << std::endl;
        return current;
    }

    
    return current->children[user_input];
}

const ivanr::MenuItem* ivanr::exit(const MenuItem*) {
    std::cout << "Выход из программы." << std::endl;
    return nullptr; 
}

const ivanr::MenuItem* ivanr::go_back(const MenuItem* current) {
    if (current->parent != nullptr && current->parent->parent != nullptr) {
        return current->parent->parent;
    }

    if (current->parent != nullptr) {
        return current->parent;
    }

    return current;
}


const ivanr::MenuItem* ivanr::do_databases(const MenuItem*) {
    std::cout << "\n>> Базы данных (выполнено)\n" << std::endl;
    return nullptr; 
}

const ivanr::MenuItem* ivanr::do_multithreading(const MenuItem*) {
    std::cout << "\n>> Многопоточность (выполнено)\n" << std::endl;
    return nullptr;
}

const ivanr::MenuItem* ivanr::do_networks(const MenuItem*) {
    std::cout << "\n>> Сетевые технологии (выполнено)\n" << std::endl;
    return nullptr;
}

const ivanr::MenuItem* ivanr::do_learn_langs(const MenuItem*) {
    std::cout << "\n>> Изучение языков (выполнено)\n" << std::endl;
    return nullptr;
}

const ivanr::MenuItem* ivanr::do_algorithms(const MenuItem*) {
    std::cout << "\n>> Алгоритмы (выполнено)\n" << std::endl;
    return nullptr;
}

const ivanr::MenuItem* ivanr::do_football(const MenuItem*) {
    std::cout << "\n>> Ура, футбол! (выполнено)\n" << std::endl;
    return nullptr; 
}