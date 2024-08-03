#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void swap(int* a, int* b);
bool is_sorted(int list[], int length);
char* list_to_string(int list[], int length);

int main(void) {
    int list_length = 10;
    int number_list[] = { 10, 6, 3, 5, 1, 4, 7, 2, 9, 8 };
    
    for (
        int i = 0;
        !is_sorted(number_list, list_length);
        i = i < list_length - 1 ? i + 1 : 0
    ) {
        printf("Current List:\n%s\n", list_to_string(number_list, list_length));
        printf("Current index: %d\n", i);

        int min = i;
        for (int j = i + 1; j < list_length; j++) {
            if (number_list[j] < number_list[min]) {
                min = j;
            }
        }
        swap(&number_list[i], &number_list[min]);
    }

    printf("List has been sorted:\n");
    printf("%s\n", list_to_string(number_list, list_length));
}

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