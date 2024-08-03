#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
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

int main(void) {
    int list_length = 10;
    int number_list[] = { 10, 6, 3, 5, 1, 4, 7, 2, 9, 8 };
    
    
    bool sorted = false;
    
    int complexity = list_length * list_length;

    int total_laps = 0;
    for (int i = 0; total_laps < complexity; i = i < list_length - 1 ? i + 1 : 0) {
        printf("Current List:\n%s\n", list_to_string(number_list, list_length));
        printf("Last number: %d\n", number_list[list_length - 1]);
        printf("Current index: %d\n", i);
        if (is_sorted(number_list, list_length)) {
            sorted = true;
            break;
        }

        int a = number_list[i];
        int b = number_list[i + 1];

        if (a > b && a != number_list[list_length - 1]) {
            swap(
                &number_list[i],
                &number_list[i + 1]
            );
        }
        total_laps++;
    }

    if (sorted) {
        printf("List has been sorted:\n");
        printf("%s\n", list_to_string(number_list, list_length));
    }
}