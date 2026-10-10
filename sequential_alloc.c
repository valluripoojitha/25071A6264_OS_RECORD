#include <stdio.h>

#define MAX 50

int main() {
    int disk[MAX] = {0};
    int start, length,i;
    printf("roll number: 25071A6264");

    printf("SEQUENTIAL FILE ALLOCATION\n");

    printf("Enter starting block: ");
    scanf("%d", &start);

    printf("Enter number of blocks: ");
    scanf("%d", &length);

    // Check whether blocks are within range
    if (start < 0 || start + length > MAX) {
        printf("Invalid allocation!\n");
        return 0;
    }

    // Check whether all blocks are free
    for (i = start; i < start + length; i++) {
        if (disk[i] == 1) {
            printf("Allocation failed! Block %d is already occupied.\n", i);
            return 0;
        }
    }

    // Allocate blocks
    for (i = start; i < start + length; i++) {
        disk[i] = 1;
    }

    printf("\nFile allocated successfully.\n");
    printf("Allocated blocks: ");

    for (i = start; i < start + length; i++) {
        printf("%d ", i);
    }

    printf("\n");

    return 0;
}
