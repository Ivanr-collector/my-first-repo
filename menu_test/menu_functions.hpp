#pragma once

#include "menu.hpp"

namespace ivanr {

    const MenuItem* show_menu(const MenuItem* current);
    const MenuItem* exit(const MenuItem* current);
    const MenuItem* go_back(const MenuItem* current);

    const MenuItem* do_databases(const MenuItem* current);
    const MenuItem* do_multithreading(const MenuItem* current);
    const MenuItem* do_networks(const MenuItem* current);
    
    const MenuItem* do_learn_langs(const MenuItem* current);
    const MenuItem* do_algorithms(const MenuItem* current);
    
    const MenuItem* do_football(const MenuItem* current);
}