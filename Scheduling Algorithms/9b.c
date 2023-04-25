#include <stdio.h>
void main()
{
    int i, j, t, n, stt = 0, pid[10], at[10], bt[10], ft[10], att, wt[10], ta[10], totwt = 0, totta = 0;
    float avgwt, avgta;
    printf("ENTER THE NUMBER OF PROCESSES: ");
    scanf("%d", &n);
    printf("\nENTER THE ARRIVAL TIME: ");
    scanf("%d", &att);
    for (i = 1; i <= n; i++)
    {
        pid[i] = i;
        at[i] = att;
        printf("\nENTER THE BURST TIME: ");
        scanf("%d", &bt[i]);
    }
    for (i = 1; i <= n; i++)
    {
        for (j = i + 1; j <= n; j++)
        {
            if (bt[i] > bt[j])
            {
                t = pid[i];
                pid[i] = pid[j];
                pid[j] = t;
                t = bt[i];
                bt[i] = bt[j];
                bt[j] = t;
            }
            stt = att;
        }
    }
    for (i = 1; i <= n; i++)
    {
        ft[i] = stt + bt[i];
        wt[i] = stt - at[i];
        ta[i] = ft[i] - at[i];
        totta = totta + ta[i];
        totwt = totwt + wt[i];
        stt = ft[i];
    }

    avgwt = (float)totwt / n;
    avgta = (float)totta / n;
    printf("\nPNO\tARRIVAL TIME\tBURST TIME\tCOMPLETION TIME\t\tWAIT TIME\tTAT");
    for (i = 1; i <= n; i++)
    {
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", pid[i], at[i], bt[i], ft[i], wt[i], ta[i]);
    }
    printf("\nAVERAGE TURN AROUND TIME=%f", avgta);
    printf("\nAVERAGE WAITING TIME=%f", avgwt);
}
