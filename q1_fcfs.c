// WAP to implement the First Come First Serve Scheduling.

#include <stdio.h>

int main()
{
    // variable and array initializations
    int i, j, n, bt[30], wt[30], tat[30];
    float awt = 0, atat = 0;
    printf("Input the number of process: ");
    scanf("%d", &n);

    // Taking Burst Time input from the user.
    printf("Enter The Burst Time For %d Processes: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }

    // calculate the all waiting times and turn around times
    printf("\nPro\tB.T\tW.T\tTAT\n");
    for (i = 0; i < n; i++)
    {
        wt[i] = 0;
        tat[i] = 0;
        for (j = 0; j < i; j++) // Here important is (j<i)
        {
            wt[i] = wt[i] + bt[j]; // formula for waiting time for each processes
        }
        tat[i] = wt[i] + bt[i]; // formula for Turn around time for each processes
        awt = awt + wt[i];
        atat = atat + tat[i];
        printf("%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }
    printf("Average Wating Time: %.1f\n", awt / n);
    printf("Average Turn Around Time: %.1f", atat / n);
    return 0;
}