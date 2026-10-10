#include <stdio.h>

int main()
{
    int n, m;
    int alloc[10][10], max[10][10], need[10][10];
    int avail[10], finish[10] = {0}, safe[10];
    int i, j, count = 0;

    printf("=========================================\n");
    printf("          BANKER'S ALGORITHM\n");
    printf("=========================================\n");

    printf("Enter Number of Processes : ");
    scanf("%d", &n);

    printf("Enter Number of Resource Types : ");
    scanf("%d", &m);

    if (n <= 0 || n > 10 || m <= 0 || m > 10)
    {
        printf("Invalid number of processes or resources.\n");
        return 1;
    }

    printf("\nEnter Allocation Matrix:\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d : ", i);
        for (j = 0; j < m; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("\nEnter Maximum Matrix:\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d : ", i);
        for (j = 0; j < m; j++)
        {
            scanf("%d", &max[i][j]);

            if (max[i][j] < alloc[i][j])
            {
                printf("Error: Maximum cannot be less than Allocation.\n");
                return 1;
            }
        }
    }

    printf("\nEnter Available Resources : ");
    for (j = 0; j < m; j++)
    {
        scanf("%d", &avail[j]);
    }

    /* Calculate Need Matrix */
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    /* Banker's Algorithm */
    while (count < n)
    {
        int found = 0;

        for (i = 0; i < n; i++)
        {
            if (finish[i] == 0)
            {
                int flag = 1;

                /* Check Need <= Available */
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = 0;
                        break;
                    }
                }

                if (flag == 1)
                {
                    /* Process can execute */
                    for (j = 0; j < m; j++)
                    {
                        avail[j] = avail[j] + alloc[i][j];
                    }

                    safe[count] = i;
                    count++;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        /* No process can execute */
        if (found == 0)
        {
            break;
        }
    }

    /* Display Need Matrix */
    printf("\n=========================================\n");
    printf("              NEED MATRIX\n");
    printf("=========================================\n");

    for (i = 0; i < n; i++)
    {
        printf("P%d : ", i);

        for (j = 0; j < m; j++)
        {
            printf("%d ", need[i][j]);
        }

        printf("\n");
    }

    printf("\n=========================================\n");

    /* Check Safe State */
    if (count == n)
    {
        printf("System is in SAFE State.\n");

        printf("Safe Sequence : ");

        for (i = 0; i < n; i++)
        {
            printf("P%d", safe[i]);

            if (i != n - 1)
            {
                printf(" -> ");
            }
        }

        printf("\n");
    }
    else
    {
        printf("System is NOT in SAFE State.\n");
        printf("Deadlock may occur.\n");
    }

    printf("=========================================\n");

    return 0;
}
