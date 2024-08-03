#include <stdlib.h>
#include <stdio.h>
#include "inputf.h"

#define CHUNK_SIZE 5

char* inputf(char* text) {

    char* input = (char*) malloc(CHUNK_SIZE);
    size_t allocatedSize = CHUNK_SIZE; // sizeof input
    size_t usedSize = 0;

    printf("%s", text);

    char c;
    while((c = getchar()) != '\n' && c != '\r' && c != EOF) {
        if (allocatedSize == usedSize - 1) {
            allocatedSize += CHUNK_SIZE;
            char* temp = (char*) realloc(input, allocatedSize);

            if (temp == NULL) {
                perror("Memory allocation failure.\n");
                free(input);
                return "Memory allocation failure.\n";
            }

            input = temp;
        }

        input[usedSize++] = c;
    }

    return input;
}