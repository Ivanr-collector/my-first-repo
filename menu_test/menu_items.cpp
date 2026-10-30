#include "menu_items.hpp"
#include "menu_functions.hpp"

// ==========================================
// УРОВЕНЬ 3 (Листья)
// ==========================================
const ivanr::MenuItem ivanr::DATABASES = {
    "1 — Базы данных", ivanr::do_databases, &ivanr::TECH
};

const ivanr::MenuItem ivanr::MULTITHREADING = {
    "2 — Многопоточное программирование", ivanr::do_multithreading, &ivanr::TECH
};

const ivanr::MenuItem ivanr::NETWORKS = {
    "3 — Сетевые технологии", ivanr::do_networks, &ivanr::TECH
};

const ivanr::MenuItem ivanr::TECH_BACK = {
    "0 — Выйти в предыдущее меню", ivanr::go_back, &ivanr::TECH
};

// ==========================================
// УРОВЕНЬ 2
// ==========================================
const ivanr::MenuItem ivanr::LANGS = {
    "1 — Изучать языки программирования", ivanr::do_learn_langs, &ivanr::PROG
};

const ivanr::MenuItem ivanr::ALGO = {
    "2 — Алгоритмы и структуры", ivanr::do_algorithms, &ivanr::PROG
};

const ivanr::MenuItem ivanr::PROG_BACK = {
    "0 — Выйти в главное меню", ivanr::go_back, &ivanr::PROG
};

// ==========================================
// УРОВЕНЬ 1
// ==========================================
// Создаем пункт для футбола (он будет под номером 2)
const ivanr::MenuItem ivanr::FOOTBALL = {
    "2 — Пойти играть в футбол", ivanr::do_football, &ivanr::MAIN
};

// Создаем кнопку выхода (она будет под номером 0)
const ivanr::MenuItem ivanr::EXIT = {
    "0 — Выход из программы", ivanr::exit, &ivanr::MAIN
};

namespace {
    // Массивы указателей на детей
    const ivanr::MenuItem* const tech_children[] = {
        &ivanr::TECH_BACK,
        &ivanr::DATABASES,
        &ivanr::MULTITHREADING,
        &ivanr::NETWORKS
    };
    const int tech_size = sizeof(tech_children) / sizeof(tech_children[0]);

    const ivanr::MenuItem* const prog_children[] = {
        &ivanr::PROG_BACK,
        &ivanr::LANGS,
        &ivanr::ALGO,
        &ivanr::TECH
    };
    const int prog_size = sizeof(prog_children) / sizeof(prog_children[0]);

    // ВАЖНО: порядок в массиве определяет, какая цифра будет у пункта
    const ivanr::MenuItem* const main_children[] = {
        &ivanr::EXIT,     // [0] - выведется в самом конце как 0
        &ivanr::PROG,     // [1] - выведется как 1
        &ivanr::FOOTBALL  // [2] - выведется как 2
    };
    const int main_size = sizeof(main_children) / sizeof(main_children[0]);
}

// ==========================================
// Корни меню
// ==========================================
const ivanr::MenuItem ivanr::TECH = {
    "3 - Другие технологии",
    ivanr::show_menu,
    &ivanr::PROG,
    tech_children,
    tech_size,
    "Третий уровень Другие технологии:"
};

const ivanr::MenuItem ivanr::PROG = {
    "1 - Изучать программирование",
    ivanr::show_menu,
    &ivanr::MAIN,
    prog_children,
    prog_size,
    "Второй уровень меню:"
};

const ivanr::MenuItem ivanr::MAIN = {
    nullptr,
    ivanr::show_menu,
    nullptr,
    main_children,
    main_size,
    "Главное меню:"
};