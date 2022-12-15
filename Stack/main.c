#include <stdio.h>
#include <stdlib.h>
#include "Global.h"
// either   #define LINKED_STACK or not
//#define LINKED_STACK
#ifdef LINKED_STACK
typedef struct stacknode
{
    StackEntry entry;
    struct stacknode *next;
}StackNode;
typedef struct stack
{
    StackNode *top;
    int size;
}Stack;
void CreatStack(Stack *ps)
{
    ps->top=NULL;
    ps->size=0;
}
void Push(StackEntry e , Stack *ps)
{
    StackNode *pn=(StackNode*)malloc(sizeof(StackNode)); // make a node of pointer and element
    pn->entry=e; // put in our new node element
    pn->next=ps->top; // pointer refer to top of stack
    ps->top=pn;  // stack top pointer refer to our new node
    ps->size++; // increase size by 1
}
void Pop(StackEntry *pe,Stack *ps)
{
    StackNode *pn; // we use it only to refer to node we want to pop
    *pe=ps->top->entry; // this is equal get stack top
    pn=ps->top; // pn refer to ps->top
    ps->top=ps->top->next; // refer to next node after first one
    free(pn); // this is used to free things where pointer refer to
     ps->size--; // decrease size by one
}
void Clear_stack(Stack *ps)
{
    StackNode *pn=ps->top;   // first we make a pointer to refer to
    while(pn)  // while it not = null continue
    {
        pn= pn->next;  // poiter refer to element after top
        free(ps->top);  // free top
        ps->top=pn;   // top refer to the next top element
    }
    ps->size=0;
    // complexity O(n)
}
void display(StackEntry e)
{
    printf("Element  is : %d\n",e);
}
void Traverse_Stack(Stack *ps, void (*pf)(StackEntry))
{
    StackNode *pn=ps->top;  // make a pointer refer to top then for it element by element
    while(pn)
    {
        (*pf)(pn->entry);
        pn=pn->next;
    }
    // this code also equal
    // for(stackNode *pn=ps->top;pn;pn=pn->next)
    //   (*pf)(pn->entry);
}
int StackSize(Stack *ps)
{
    return ps->size;  // more efficient
   /* int x;
    StackNode *pn=ps->top;
    for(x=0;pn;pn=pn->next)
    {
        x++;
    }
    return x;  */ // O(N)
}
#else
typedef struct stack
{
    int top;
    StackEntry entry[MAXSTACK];
}Stack;
void CreatStack(Stack *ps) // for initionalize stack
{
    ps->top=0; // == *ps.top=0;
}
void Push(StackEntry e,Stack *ps  )
{
    ps->entry[ps->top]=e;
    ps->top++;
    //  2 line up == ps->entry[ps->top++];
}
int FullStack(Stack *ps) // we use pointer for not making  a copy from stack and take time
{
    if(ps->top==MAXSTACK)  //  Remember that we start from 0 to MAXSTACK-1
        return 1;
    else
        return 0;
    // this code also == return ps->top>=MAXSTACK;
}
void Pop(StackEntry *pe,Stack *ps)
{
    ps->top--; // we always add 1 to top to push new element
    // so here we 'll subtract 1 to stand on last element
    *pe=ps->entry[ps->top]; // we 'll return last element in stack in e

    // this code also equal *pe=ps->entry[--ps->top];

}
int Stac_Empty(Stack *ps)
{
    if(ps->top==0)
        return 1;
    else
        return 0;
    // this code also == return ps->top==0;
}
void Stack_Top(StackEntry *pe,Stack *ps)
{
    *pe=ps->entry[ps->top-1];  // return last element without change the original top
}
int Stack_Size(Stack *ps)
{
    return ps->top; // return top 0->MAXSTACK-1 == Top
}
void Clear_Stack(Stack *ps)
{
    ps->top=0;
}
void display(StackEntry e)
{
    printf("e is : %d\n",e);
}
void Traverse_Stack(Stack *ps, void (*pf)(StackEntry))
{
    for(int i=ps->top;i>0;i--)
    {
           (*pf)(ps->entry[i-1]);
    }

}
void StackTop(StackEntry *pe,Stack *ps) // Make by user (user Level)
{
    Pop(pe,ps); // send address for ps ,pe
    Push(*pe,ps); // send element of e and address of ps
}
#endif
int main()
{
    Stack s;
    CreatStack(&s);
    int x;
    scanf("%d\n",&x);
    StackEntry e;
    for(int i=0;i<x;i++)
    {
        scanf("%d",&e);
        Push(e , &s);
    }
    Traverse_Stack(&s,&display);



    return 0;
}
