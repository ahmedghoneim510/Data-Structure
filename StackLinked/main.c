#include <stdio.h>
#include <stdlib.h>
typedef int KeyType;
typedef struct elementtype{
	KeyType		key;
		int		year;
		float	age;
		int		tmp;
		char    ch;
	short int	etype;
	union{
		int		year;
		float	age;
		void	*ptr;
		char	par;
	}info;
}ElementType;

typedef ElementType StackEntry;

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
   // StackNode *pn=ps->top;  // make a pointer refer to top then for it element by element
  /*  while(pn)
    {
        (*pf)(pn->entry);
        pn=pn->next;
    }*/

    // this code also equal
     for(StackNode *pn=ps->top;pn;pn=pn->next)
      {
          (*pf)(pn->entry);
      }
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
int main()
{
    Stack s; // declartion

    CreatStack(&s); // initializtion

    StackEntry e;  // element

    for(int i=0;i<=9;i++)
    {
        scanf("%d",&e);
        Push( e , &s); // push element
    }

     Pop(&e ,&s); // pop element

    Traverse_Stack(&s,&display);

    printf("\n");

    int x=StackSize(&s);

    printf("Size is %d",x);
    return 0;
}
