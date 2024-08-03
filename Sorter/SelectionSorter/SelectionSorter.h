#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

typedef struct SelectionSorter {
    int* (*integers)(int[], int);
} SelectionSorter;

SelectionSorter create_selection_sorter(void);

#endif