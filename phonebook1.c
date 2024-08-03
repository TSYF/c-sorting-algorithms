#include <stdio.h>
#include <string.h>
#include "inputf.h"

int main(void) {
    const char* names[] = { "Carter", "David", "John" };
    const char* phones[] = { "(555) 555-5555", "(555) 555-5555", "(555) 555-5555" };
    const int PHONEBOOK_LENGTH = 3;
    const char* name = inputf("Name: ");

    for (int i = 0; i < PHONEBOOK_LENGTH; i++) {
        if (strcmp(names[i], name) == 0) {
            printf("Found at index %d\n", i);
            printf("Phone: %s\n", phones[i]);
            return 0;
        }
        printf("Not found\n");
    }
    return 1;
}