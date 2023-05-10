#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define memSize 50

int main()
{
    int shmid;
    char *sharedMemory;
    key_t key = 1;
    if ((shmid = shmget(key, memSize, 0666 | IPC_CREAT)) < 0)
    {
        perror("shmget Error");
        exit(1);
    }
    if ((sharedMemory = shmat(shmid, NULL, 0)) == (char *)-1)
    {
        perror("shmat Error");
        exit(1);
    }
    sprintf(sharedMemory, "Welcome to Shared Memory");
    sleep(1);
    return 0;
}