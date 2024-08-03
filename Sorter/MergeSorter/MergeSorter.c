#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "MergeSorter.h"

static int* sort_integers(int[], int);
static int* merge(int left[], int right[], int left_length, int right_length);

MergeSorter create_merge_sorter(void) {
    static MergeSorter sorter;

    sorter.integers = sort_integers;

    return sorter;
}

static int* sort_integers(int list[], int length) {

    if (length == 1) {
        int* result = malloc(sizeof(int));
        *result = list[0];
        return result;
    }

    int half_length = (double)(length / 2);
    int left_length = round(half_length);
    int right_length = length - left_length;

    int* left = sort_integers(list, left_length);
    int* right = sort_integers(list + left_length, right_length);

    int* out = merge(left, right, left_length, right_length);

    free(left);
    free(right);
    return out;
}

static int* merge(int left[], int right[], int left_length, int right_length) {
    int length = left_length + right_length;
    int* out = malloc(length * sizeof(int));
    
    int i = 0, j = 0, k = 0;
    while (i < left_length && j < right_length) {
        out[k++] = left[i] < right[j] ? left[i++] : right[j++];
    }

    while (i < left_length) {
        out[k++] = left[i++];
    }

    while (j < right_length) {
        out[k++] = right[j++];
    }

    return out;
}