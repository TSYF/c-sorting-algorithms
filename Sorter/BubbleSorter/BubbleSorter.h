#ifndef BUBBLESORTER_H
#define BUBBLESORTER_H

typedef struct BubbleSorter {
    int* (*integers)(int[], int);
} BubbleSorter;

BubbleSorter create_bubble_sorter(void);

#endif