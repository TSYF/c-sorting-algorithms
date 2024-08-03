#ifndef SORTER_H
#define SORTER_H

#include "BubbleSorter/BubbleSorter.h"
#include "SelectionSorter/SelectionSorter.h"
#include "MergeSorter/MergeSorter.h"

typedef struct Sorter {
    BubbleSorter    bubble;
    SelectionSorter selection;
    MergeSorter     merge;
} Sorter;

Sorter create_sorter(void);

// Sorter sorter;

#endif