#include "Sorter.h"

Sorter create_sorter(void) {
    static Sorter sorter;

    sorter.bubble = create_bubble_sorter();
    sorter.selection = create_selection_sorter();
    sorter.merge = create_merge_sorter();

    return sorter;
}