#include <stdio.h>

int main()
{
    int blockSize[20], processSize[20];
    int allocation[20];
    int n, m, i, j, worstIndex;

    // Input number of memory partitions
    printf("Enter number of memory partitions: ");
    scanf("%d", &n);

    // Input partition sizes
    printf("Enter sizes of memory partitions:\n");
    for (i = 0; i < n; i++)
    {
        printf("Partition %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    // Input number of processes
    printf("Enter number of processes: ");
    scanf("%d", &m);

    // Input process sizes
    printf("Enter sizes of processes:\n");
    for (i = 0; i < m; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &processSize[i]);
    }

    // Initially, no process is allocated
    for (i = 0; i < m; i++)
    {
        allocation[i] = -1;
    }

    // Worst Fit Allocation
    for (i = 0; i < m; i++)
    {
        worstIndex = -1;

        for (j = 0; j < n; j++)
        {
            // Find partitions large enough
            if (blockSize[j] >= processSize[i])
            {
                // Choose the largest suitable partition
                if (worstIndex == -1 ||
                    blockSize[j] > blockSize[worstIndex])
                {
                    worstIndex = j;
                }
            }
        }

        // Allocate process
        if (worstIndex != -1)
        {
            allocation[i] = worstIndex;
            blockSize[worstIndex] = -1; // Partition is occupied
        }
    }

    // Display result
    printf("\nProcess No.\tProcess Size\tPartition No.\n");

    for (i = 0; i < m; i++)
    {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);

        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}
