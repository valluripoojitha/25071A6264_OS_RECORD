#include <stdio.h>

int main() {
    int pages[50], frames[10];
    int n, f, i, j;
    int faults = 0, hits = 0, pointer = 0;
    int found;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++)
        frames[i] = -1;

    for (i = 0; i < n; i++) {
        found = 0;

        for (j = 0; j < f; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                hits++;
                break;
            }
        }

        if (!found) {
            frames[pointer] = pages[i];
            pointer = (pointer + 1) % f;
            faults++;
        }

        printf("Page %d: ", pages[i]);
        for (j = 0; j < f; j++) {
            if (frames[j] == -1)
                printf("- ");
            else
                printf("%d ", frames[j]);
        }

        printf(found ? "Hit\n" : "Fault\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);
    printf("Total Page Hits = %d\n", hits);

    return 0;
}
