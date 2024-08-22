#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sortNames(char** names, int count) {
    char* temp;
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(names[i], names[j]) > 0) {
                temp = names[i];
                names[i] = names[j];
                names[j] = temp;
            }
        }
    }
}

int main() {
    int count;
    printf("Enter the number of names: ");
    scanf_s("%d", &count);

    char** names = (char**)malloc(count * sizeof(char*));
    if (names == NULL) {
        perror("Failed to allocate memory");
        return 1;
    }

    for (int i = 0; i < count; i++) {
        names[i] = (char*)malloc(100 * sizeof(char));
        if (names[i] == NULL) {
            perror("Failed to allocate memory");
            return 1;
        }
        printf("Enter name %d: ", i + 1);
        scanf_s("%s", names[i], 100);
    }

    sortNames(names, count);

    printf("\nSorted names:\n");
    for (int i = 0; i < count; i++) {
        printf("%s\n", names[i]);
    }

    for (int i = 0; i < count; i++) {
        free(names[i]);
    }
    free(names);

    return 0;
}
