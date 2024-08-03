#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* sort(int[], int);
char* list_to_string(int list[], int length);
int* merge(int left[], int right[], int left_length, int right_length);

int main(void) {
    int length = 10;
    int list[] = { 10, 6, 3, 5, 1, 4, 7, 2, 9, 8 };

    int sorted[length];
    memcpy(sorted, sort(list, length), length * sizeof(int));

    printf(
        "List has been sorted:\n%s",
        list_to_string(sorted, length)
    );
}


int* sort(int list[], int length) {

    if (length == 1) {
        int* result = malloc(sizeof(int));
        *result = list[0];
        return result;
    }

    int half_length = (double)(length / 2);
    int left_length = round(half_length);
    int right_length = length - left_length;

    int* left = sort(list, left_length);
    int* right = sort(list + left_length, right_length);

    int* out = merge(left, right, left_length, right_length);

    free(left);
    free(right);
    return out;
}

int* merge(int left[], int right[], int left_length, int right_length) {
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

char* list_to_string(int list[], int length) {
    int strlength = length * 3 + 4;
    char* string = malloc(sizeof(char) * strlength);

    sprintf(string, "%s%s", string, "[ ");
    sprintf(string, "%s%d", string, list[0]);
    for (int i = 1; i < length; i++) {
        sprintf(string, "%s, %d", string, list[i]);
    }
    sprintf(string, "%s%s", string, " ]");

    return string;
}