#include <stdio.h>
#include <string.h>
#include <limits.h>
void bestFit(int *blocks, int *files, int *alloc, int nb, int nf)
{
    for (int i = 0; i < nf; i++)
    {
        int diff = INT_MAX, k = -1;
        for (int j = 0; j < nb; j++)
        {
            if (blocks[j] - files[i] <= diff && files[i] <= blocks[j])
            {
                k = j;
                diff = blocks[j] - files[i];
            }
        }
        if (k != -1)
        {
            alloc[i] = k;
            blocks[k] -= files[i];
        }
    }
    printf("File No.\tFile Size\tBlock Alloted\n");
    for (int i = 0; i < nf; i++)
    {
        if (alloc[i] != -1)
            printf("%d\t\t%d\t\t%d\n", i + 1, files[i], alloc[i] + 1);
        else
            printf("%d\t\t%d\t\tNot Alloted\n", i + 1, files[i]);
    }
}
int main()
{
    int nb, nf;
    printf("Enter the number of blocks: ");
    scanf("%d", &nb);
    printf("Enter the number of files ");
    scanf("%d", &nf);
    int blocks[nb], files[nf], alloc[nf];
    memset(alloc, -1, sizeof(alloc));
    printf("Enter the size of Blocks: \n");
    for (int i = 0; i < nb; i++)
    {
        printf("Block %d ", i + 1);
        scanf("%d", &blocks[i]);
    }
    printf("Enter the size of Files: \n");
    for (int i = 0; i < nf; i++)
    {
        printf("File %d ", i + 1);
        scanf("%d", &files[i]);
    }
    bestFit(blocks, files, alloc, nb, nf);
    return 0;
}