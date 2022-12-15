#include <stdio.h>
#include <stdlib.h>
#include "global.h"


typedef struct ilst
{
    ListEntry entry [MAXLIST];
    int sz;

}List;
void creatlist(List *pl)
{
    pl->sz=0;
}
int ListEmpty(List *pl)
{
    return !pl->sz;
}
int ListFull(List *pl)
{
    return pl->sz==MAXLIST;
}
int ListSize(List *pl)
{
    return pl->sz;
}
void DestroyList(List *pl)
{
    pl->sz=0;
}
void Insert_List(int pos,ListEntry e, List *pl)
{
    for(int i =pl->sz-1;i>=pos;i--)
        {pl->entry[i+1]=pl->entry[i];}
    pl->entry[pos]=e;
    pl->sz++;
}
void DeleteList(int pos , ListEntry *pe, List *pl)
{
    *pe=pl->entry[pos];
    for(int i=pos+1;i<=pl->sz-1;i++)
    {
        pl->entry[i-1]=pl->entry[i];
    }
    pl->sz--;
}
void RetrieveList(int pos ,ListEntry *pe ,List *pl)
{
    *pe=pl->entry[pos];
}
void ReplaceList(int pos ,ListEntry e,List *pl)
{
    pl->entry[pos]=e;
}
void display(ListEntry e)
{
    printf("Element  is : %d\n",e);
}
void TraverseList(List *pl,void (*visit)(ListEntry))
{
    for(int i=0;i<=pl->sz-1;i++)
    {
        (*visit)(pl->entry[i]);
    }
}
int main()
{

    List li;
    ListEntry element;
    int choice,pos;
    creatlist(&li);
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
            Insert_List(pos,element,&li);
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
