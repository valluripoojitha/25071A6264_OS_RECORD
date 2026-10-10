#include <stdio.h>
int main() {
    printf("Roll no: 25071A6264\n");
    int n, p[10], at[10], bt[10], rt[10], ct[10], tat[10], wt[10];
    int cur = 0, completed = 0;
    int tq = 10;
    float twt = 0, ttat = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("Enter Arrival Time and Burst Time for P%d: ", i + 1);
        scanf("%d%d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }
    while(completed < n) {
        int executed = 0;
        for(int i = 0; i < n; i++) {
            if(at[i] <= cur && rt[i] > 0) {
                executed = 1;
                if(rt[i] > tq) {
                    cur += tq;
                    rt[i] -= tq;
                }
                else {
                    cur += rt[i];
                    rt[i] = 0;
                    ct[i] = cur;
                    completed++;
                }
            }
        }
        if(executed == 0)
            cur++;
    }
    for(int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        twt += wt[i];
        ttat += tat[i];
}
    printf("\nProcess\tAT\tBT\tCT\tWT\tTAT\n");

    for(int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i], at[i], bt[i], ct[i], wt[i], tat[i]);
    printf("\nAverage Waiting Time = %.2f\n", twt / n);
    printf("Average Turnaround Time = %.2f\n", ttat / n);
    return 0;
}
