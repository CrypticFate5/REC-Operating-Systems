#include "prodcons.h" 

void consumer()
{
    int n;
    MEM *s = memory();
    while (1)

    {
        sem_wait(&s->full);
        sem_wait(&s->mutex);
        sem_getvalue(&s->full, &n);
        printf("[consumer] removed item [%d]\n", (s->buff)[n]);
        sem_post(&s->mutex);
        sem_post(&s->empty);
        sleep(CONSUMER_SLEEP_SEC);
    }
}
void main()
{
    consumer();
}
