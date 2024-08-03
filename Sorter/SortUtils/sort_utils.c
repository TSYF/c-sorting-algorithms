#include "sort_utils.h"
#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool is_sorted(int list[], int length) {
    bool result = true;
    for (int i = 0; i < length - 1; i++) {
        if (list[i] > list[i + 1]) {
            result = false;
            break;
        }
    }
    return result;
}

char* list_to_string(int list[], int length) {
    int strlength = length * 3 + 5;
    char* string = malloc(sizeof(char) * strlength);

    sprintf(string, "%s%s", string, "[ ");
    sprintf(string, "%s%d", string, list[0]);
    for (int i = 1; i < length; i++) {
        sprintf(string, "%s, %d", string, list[i]);
    }
    sprintf(string, "%s%s", string, " ]");

    return string;
}