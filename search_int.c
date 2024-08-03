#include <stdio.h>

int main(void) {
    int numbers[] = { 20, 500, 10, 5, 100, 1, 50 };
    int numbers_length = 7;
    int n;
    printf("Number: ");
    scanf("%d", &n);

    for (int i = 0; i < numbers_length; i++) {
        if (numbers[i] == n) {
            printf("Found at index %d\n", i);
            return 0;
        }
        printf("Not found\n");
    }
    return 1;
}