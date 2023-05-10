#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n, pid[10], at[10], bt[10], ft[10], wt[10], ta[10], i, j, t, stt = 0, totta = 0, totwt = 0;
    float avgta, avgwt;
    printf("ENTER THE NO.OF PROCESSES: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        pid[i] = i;
        printf("\nENTER THE ARRIVAL TIME: ");
        scanf("%d", &at[i]);
        printf("\nENTER THE BURST TIME: ");
        scanf("%d", &bt[i]);
    }
    for (i = 1; i <= n; i++)
    {
        for (j = i + 1; j <= n; j++)
        {
            if (at[i] > at[j])
            {

                t = pid[i];
                pid[i] = pid[j];
                pid[j] = t;
                t = at[i];
                at[i] = at[j];
                at[j] = t;
                t = bt[i];
                bt[i] = bt[j];
                bt[j] = t;
            }
            stt = at[1];
        }
    }
    printf("\nTHE VALUES OF THE ARRIVAL TIME IS %d", stt);
    for (i = 1; i <= n; i++)
    {
        ft[i] = stt + bt[i];
        wt[i] = stt - at[i];
        ta[i] = ft[i] - at[i];
        totta = totta + ta[i];
        totwt = totwt + wt[i];
        stt = ft[i];
    }
    avgta = (float)totta / n;
    avgwt = (float)totwt / n;
    printf("\nPNO\tARRIVAL TIME\tBURST TIME\tCOMPLETION TIME\t\tWAITING TIME\tTAT\n");

    for (i = 1; i <= n; i++)
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", pid[i], at[i], bt[i], ft[i], wt[i], ta[i]);
    printf("\nAVERAGE TURN AROUND TIME=%f", avgta);
    printf("\nAVERAGE WAITING TIME=%f", avgwt);
}
