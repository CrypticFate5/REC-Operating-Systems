#include <stdio.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <fcntl.h>
#define BUFFER_SIZE 10
#define CONSUMER_SLEEP_SEC 3
#define PRODUCER_SLEEP_SEC 1
#define KEY 1010;
typedef struct
{
    int buff[BUFFER_SIZE];
    sem_t mutex, empty, full;
} MEM;

MEM *memory()
{
    key_t key = KEY;
    int shmid = shmget(key, sizeof(MEM), IPC_CREAT | 0666);
    return (MEM *)shmat(shmid, NULL, 0);
}
void init()
{
    MEM *m = memory(0);
    sem_init(&M->mutex, 1, 1);
    sem_init(&M->empty, 1, BUFFER_SIZE);
    sem_init(&M->full, 1, 0);
}