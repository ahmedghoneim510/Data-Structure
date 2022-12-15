#include <stdio.h>
#include <stdlib.h>
#include "global.h"
typedef struct listnode
{
    ListEntry entry;
    struct listnode *next;
}ListNode;
typedef struct list
{
    ListNode *head;
    int size;
}List;
void CreatList(List *pl)
{
    pl->head=NULL;
    pl->size=0;
}
int ListEmpty(List *pl)
{
    return (pl->size==0);
}
int ListFull(List *pl)
{
    return 0;
}
int ListSize(List *pl)
{
    return pl->size;
}
void DestroyList(List *pl)
{
   ListNode *q;
   while(pl->head)
   {
       q=pl->head->next;
       free(pl->head);
       pl->head=q;
   }
}
void display(ListEntry e)
{
    printf("Element  is : %d\n",e);
}
void TraverseList(List *pl,void (*visit)(ListEntry))
{
    ListNode *p=pl->head;
    while(p)
    {
        (*visit)(p->entry);
        p=p->next;
    }
}
void InsertList(int pos,ListEntry e,List *pl)
{
    int i;
    ListNode *p,*q;
    p=(ListNode *)malloc(sizeof(ListNode));
    p->entry=e;
    p->next=NULL;
    if(pos==0)
    {
        p->next=pl->head;
        pl->head=p;
    }
    else
    {
        for(q=pl->head, i=0;i<pos-1;i++)
        {
            q=q->next;
        }
        p->next=q->next;
        p->next=q;

    }
    pl->size++;
}
void  DeleteList(int pos ,ListEntry * pe,List *pl)
{
    int i=0;
    ListNode *temp,*q;
    if(pos== 0)
    {
        *pe=pl->head->entry;
        q=pl->head->next;
        free(pl->head);
        pl->head=q;
    }
    else
    {
        for(q=pl->head, i=0;i<pos-1;i++)
        {
            q=q->next;
        }
        *pe=q->next->entry;
        temp=q->next->next;
        free(q->next);
        q->next=temp;
    }
    pl->size--;

}
void RetrieveList(int pos ,ListEntry *pe,List *pl)
{
    int i;
    ListNode *q;
    for(q=pl->head, i=0;i<pos;i++)
    {
        q=q->next;
    }
    *pe=q->entry;
}
void ReplaceList(int pos ,ListEntry e,List *pl)
{
    int i;
    ListNode *q;
    for(q=pl->head, i=0;i<pos;i++)
    {
        q=q->next;
    }
    q->entry=e;
}

int main()
{
    List li;
    ListEntry element;
    int choice,pos;
    CreatList(&li);
    int size;
    printf("Enter Size of List \n");
    scanf("%d",&size);

    do
    {
        printf("Enter 1-Push \t 2-Pop \t 3-Display \t 4-Exit\n");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("-Enter positon then it's value\n");
            scanf("%d",&pos);
            scanf("%d",&element);
            InsertList(pos,element,&li);
        }
        else if(choice ==2)
        {
            printf("-Enter positon \n");
            scanf("%d",&pos);
            DeleteList(pos,&element,&li);
            printf("Element is %d\n",element);
        }
        else if (choice==3)
        {
            TraverseList(&li,&display);
        }
        else
        {
            printf("Enter a valid operation\n");
        }
    }
    while(choice !=4);

    return 0;
}
