#include <stdio.h>

int main()
{
    printf("Enter the number of process: ");
    int n, r, k, p = 0, mark, deadlock = 1;
    scanf("%d", &n);
    k = n, mark = n;
    printf("Enter the number of resources: ");
    scanf("%d", &r);
    int alloc[n][r], max[n][r], avail[r], need[n][r], marked[n];
    for (int i = 0; i < n; i++)
        marked[i] = 0;
    for (int i = 0; i < n; i++)
    {
        // printf("Enter the allocated resources for P%d: ", i + 1);
        for (int j = 0; j < r; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        // printf("Enter the max resources for P%d: ", i + 1);
        for (int j = 0; j < r; j++)
        {
            scanf("%d", &max[i][j]);
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    printf("Enter the available resources: ");
    for (int i = 0; i < r; i++){
        scanf("%d", &avail[i]);
        printf("%d\n",avail[i]);
    }
    printf("\nALLOC\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
        {
            printf("%d ", alloc[i][j]);
        }
        printf("\n");
    }
    printf("\nMAX\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
        {
            printf("%d ", max[i][j]);
        }
        printf("\n");
    }
    printf("\nNEED\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
        {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
    // for(int i=0;i<r;i++) printf("%d ",avail[i]);
    printf("\nChecking....\n");
    for (int i = 0; i < n; i++)
    {
        if (marked[i] != 0)
            continue;
        int flag = 0;
        for (int j = 0; j < r; j++)
        {
            if (need[i][j] > avail[j])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            for (int j = 0; j < r; j++)
            {
                avail[j] += alloc[i][j];
            }
            p++;
            marked[i] = p;
            // printf("%d %d %d\n",i,marked[i],k);
            mark--;
        }
        if (mark == 0)
            break;
        if (i == n - 1)
        {
            i = -1;
            k--;
        }
        if (k == 0)
        {
            deadlock = 1;
            break;
        }
    }
    // for(int i=0;i<n;i++){
    //     printf("%d ",marked[i]);
    // }
    if (deadlock == 1&&mark!=0)
    {
        printf("!!!DEADLOCK!!!");
        return 0;
    }
    int ans[n];
    for (int i = 0; i < n; i++)
    {
        ans[marked[i] - 1] = i + 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (i < n - 1)
            printf("P%d->", ans[i]);
        else
            printf("P%d", ans[i]);
    }
    return 0;
}