#include "Sorter.h"
#include "SortUtils/sort_utils.h"
#include <stdio.h>

int main(void) {
    int length = 10;
    int list1[] = { 10, 6, 3, 5, 1, 4, 7, 2, 9, 8 };
    int list2[] = { 10, 6, 3, 5, 1, 4, 7, 2, 9, 8 };
    int list3[] = { 10, 6, 3, 5, 1, 4, 7, 2, 9, 8 };
    
    printf("Unsorted:\n%s\n", list_to_string(list1, length));

    Sorter sorter = create_sorter();
    
    int* bubble = sorter.bubble.integers(list1, length);
    printf("Bubble Sorted:\n%s\n", list_to_string(bubble, length));
    
    int* selection = sorter.selection.integers(list2, length);
    printf("Selection Sorted:\n%s\n", list_to_string(selection, length));

    int* merge = sorter.merge.integers(list3, length);
    printf("Merge Sorted:\n%s\n", list_to_string(merge, length));
}