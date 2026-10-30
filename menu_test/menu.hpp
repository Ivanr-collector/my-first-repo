#pragma once

namespace ivanr {
    struct MenuItem {
        const char* title;
        const MenuItem* (*func)(const MenuItem* current);

        const MenuItem* parent;

        const MenuItem* const* children = nullptr;
        int children_count = 0;

        const char* heading = nullptr;
    };
}