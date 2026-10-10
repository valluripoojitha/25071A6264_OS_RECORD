#include <stdio.h>

int main()
{
    int pageSize, numPages;
    int pageTable[100];
    int logicalAddress;
    int pageNumber, offset;
    int frameNumber, physicalAddress;
    int i;
    printf("roll number 25071A6264");

    printf("PAGING MEMORY MANAGEMENT\n");
    printf("------------------------\n");

    printf("Enter page size: ");
    scanf("%d", &pageSize);

    printf("Enter number of pages: ");
    scanf("%d", &numPages);

    if (pageSize <= 0 || numPages <= 0 || numPages > 100)
    {
        printf("Invalid input!\n");
        return 0;
    }

    printf("\nEnter page table:\n");

    for (i = 0; i < numPages; i++)
    {
        printf("Enter frame number for page %d: ", i);
        scanf("%d", &pageTable[i]);
    }

    printf("\nEnter logical address: ");
    scanf("%d", &logicalAddress);

    if (logicalAddress < 0)
    {
        printf("Invalid logical address!\n");
        return 0;
    }

    pageNumber = logicalAddress / pageSize;
    offset = logicalAddress % pageSize;

    if (pageNumber >= numPages)
    {
        printf("\nInvalid logical address!\n");
        printf("Page number %d does not exist.\n", pageNumber);
        return 0;
    }

    frameNumber = pageTable[pageNumber];

    physicalAddress = (frameNumber * pageSize) + offset;

    printf("\n----- RESULT -----\n");
    printf("Logical Address  = %d\n", logicalAddress);
    printf("Page Number      = %d\n", pageNumber);
    printf("Offset           = %d\n", offset);
    printf("Frame Number     = %d\n", frameNumber);
    printf("Physical Address = %d\n", physicalAddress);

    return 0;
}
