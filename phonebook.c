#include <stdio.h>
#include <string.h>
#include "inputf.h"

typedef struct Person {
    char* name;
    char* phone;
} Person;

int main(void) {
    const Person people[] = {
        (Person) {
            name: "Carter",
            phone: "(555) 555-5555"
        },
        (Person) {
            name: "David",
            phone: "(555) 555-5555"
        },
        (Person) {
            name: "John",
            phone: "(555) 555-5555"
        }
    };
    const int PHONEBOOK_LENGTH = 3;
    const char* name = inputf("Name: ");

    for (int i = 0; i < PHONEBOOK_LENGTH; i++) {
        Person person = people[i];
        if (strcmp(person.name, name) == 0) {
            printf("Found at index %d\n", i);
            printf("Phone: %s\n", person.phone);
            return 0;
        }
        printf("Not found\n");
    }
    return 1;
}