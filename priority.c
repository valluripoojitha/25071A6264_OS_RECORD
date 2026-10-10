#include <stdio.h>
int main() {
    printf("Roll no: 25071A6264\n");
    int n, p[10], at[10], bt[10], pr[10];
    int rt[10], ct[10], tat[10], wt[10];
    int cur = 0, completed = 0;
    float twt = 0, ttat = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        p[i] = i + 1;
printf("Enter Arrival Time, Burst Time and Priority for P%d: ",
               i + 1);
        scanf("%d%d%d", &at[i], &bt[i], &pr[i]);
        rt[i] = bt[i];
    }
    while(completed < n) {
        int idx = -1;
        int highest = 9999;
        for(int i = 0; i < n; i++) {
            if(at[i] <= cur && rt[i] > 0 && pr[i] < highest) {
                highest = pr[i];
                idx = i;
            }
        }
        if(idx == -1) {
            cur++;
        }
        else {
            rt[idx]--;
            cur++;

            if(rt[idx] == 0) {
                ct[idx] = cur;
                completed++;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        twt += wt[i];
        ttat += tat[i];
    }
    printf("\nProcess\tAT\tBT\tPriority\tCT\tWT\tTAT\n");
    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n",
               p[i], at[i], bt[i], pr[i],
               ct[i], wt[i], tat[i]);
    }
    printf("\nAverage Waiting Time = %.2f\n", twt / n);
    printf("Average Turnaround Time = %.2f\n", ttat / n);
    return 0;
}
