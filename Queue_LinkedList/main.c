#include <stdio.h>
#include <stdlib.h>
typedef struct QueueNode
{
    QueuEntry entry;
    struct QueueNode *next;

}QueueNode;
typedef struct queue
{
    QueueNode *front;
    QueueNode *rear;
    int size;
}Queue;
void CreatQueue(Queue *pq)
{
    pq->front=NULL;
    pq->rear=NULL;
    pq->size=0;
}
void Append(QueuEntry e,Queue *pq)
{
    QueueNode *pn=(QueueNode *)malloc(sizeof(QueueNode))
    pn->entry=e;
    pn->next=NULL;
    if(!pq->rear)
        pq->front=pn
    else
    {pq->rear->next=pn;}
    pq->size++;
    pq->rear=pn;
}
void serve(QueueEntery *pe ,Queue *pq)
{
    QueueNode *pn=pq->front;
    *pe=pn->entry;
    pq->front=pn->next;
    free(pn);
    if(!pq->front)
    {
        pq->rear=NULL;
    }
    pq->size--;
}
int QueueEmpty(Queue *pq)
{
    return !pq->front;
}
int QueueFull(Queue *pd)
{
    return 0;
}
int QueueSize(Queue *pq)
{
    return pq->size;
}
void ClearQueue(Queue *pq)
{
    while(pq->front)
    {
        pq->rear=pq->front->next;
        free(pq->front);
        pq->front=pq->rear;
    }
    pq->size=0;
}
void display(QueueEntry e)
{
    printf("Element  is : %d\n",e);
}
void Traverse(Queue *pq,void(*pf)(QueueEntry))
{
    QueueNode *pn=pq->front;
    while(pn)
    {
        (*pf)(pn->entry);
        pn=pn->next;
    }
}
int main()
{

    return 0;
}
