#include "prodcons.h" 

void producer()
{
    int i = 0, n;
    MEM *s = memory();
    while (1)
    {
        i++;
        sem_wait(&s->empty);
        sem_wait(&s->mutex);

        sem_getvalue(&s->full, &n);
        (s->buff)[n] = i;
        printf("[producer] placed item [%d] \n", i);
        sem_post(&s->mutex);
        sem_post(&s->full);
        sleep(PRODUCER_SLEEP_SEC);
    }
}
void main()
{
    init();
    producer();
}
