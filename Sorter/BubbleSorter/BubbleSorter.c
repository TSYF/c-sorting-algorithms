#include "BubbleSorter.h"
#include "../SortUtils/sort_utils.h"

static int* sort_integers(int array[], int length) {
    for (
        int i = 0;
        !is_sorted(array, length);
        i = i < length - 1 ? i + 1 : 0
    ) {
        int a = array[i];
        int b = array[i + 1];

        if (a > b && a != array[length - 1]) {
            swap(
                &array[i],
                &array[i + 1]
            );
        }
    }

    return array;
}

BubbleSorter create_bubble_sorter(void) {
    BubbleSorter sorter;

    sorter.integers = sort_integers;

    return sorter;
}

