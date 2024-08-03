#include "SelectionSorter.h"
#include "../SortUtils/sort_utils.h"

static int* sort_integers(int array[], int length) {
    for (
        int i = 0;
        !is_sorted(array, length);
        i = i < length - 1 ? i + 1 : 0
    ) {

        int min = i;
        for (int j = i + 1; j < length; j++) {
            if (array[j] < array[min]) {
                min = j;
            }
        }
        swap(&array[i], &array[min]);
    }

    return array;
}

SelectionSorter create_selection_sorter(void) {
    SelectionSorter sorter;

    sorter.integers = sort_integers;

    return sorter;
}