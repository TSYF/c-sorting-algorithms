#include <stdio.h>
#include <string.h>
#include "inputf.h"

int main(void) {
    const char* strings[] = { "battleship", "boot", "cannon", "iron", "thimble", "top hat" };
    const int NUMBERS_LENGTH = 6; 
    const char* string = inputf("String: "); 

    for (int i = 0; i < NUMBERS_LENGTH; i++) {
        if (strcmp(strings[i], string) == 0) {
            printf("Found at index %d\n", i);
            return 0;
        }
        printf("Not found\n");
    }
    return 1;
}