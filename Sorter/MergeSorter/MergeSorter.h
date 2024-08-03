#ifndef MERGESORTER_H
#define MERGESORTER_H

typedef struct MergeSorter {
    int* (*integers)(int[], int);
} MergeSorter;

MergeSorter create_merge_sorter(void);

#endif