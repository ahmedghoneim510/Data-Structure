#include <stdio.h>
#include <stdlib.h>
typedef struct queue
{
    int front;
    int rear;
    int size;
    QueueEntry entry[MAXQUEUE];
}Queue;
void Creatqueue(Queue *pq)
{
    pq->front=0;
    pq->rear=-1;
    pq->size=0;

}
void append(QueueEntry e,Queue *pq)
{
  /*  if(pq->rear== MAXQUEUE-1)
    {
        pq->rear=0;
    }
    else
    {
        pq->rear++;
    } this equal/*/
    pq->rear=(pq->rear+1)%MAXQUEUE;
    pq->entry[pq->rear]=e;
    pq->size++;
}
void Serve(QueueEntry *pe,Queue *pq)
{
    *pe=pq->entry[pq->front];
    pq->front=(pq->front+1)%MAXQUEUE;
    pq->size--;
}
int QueueEmpty(Queue *pq)
{
    return !pq->size;
}
int QueueFull(Queue *pq)
{
    return (pq->size==MAXQUEUE);
}
int QueueSize(Queue *pq)
{
    return pq->size;
}
void ClearQueue(Queue *pq)
{
     pq->front=0;
    pq->rear=-1;
    pq->size=0;
}
void TraverseQueue(Queue *pq,void (*pf)(QueueEntry))
{
    int pos ,s;
    for(pos=pq->front,s=0;s<pq->size;s++)
    {
        (*pf)(pq->entry[pos]);
        pos=(pos+1)%MAXQUEUE;
    }
}
int main()
{
    Queue q;
    Creatqueue(&q);
    return 0;
}
