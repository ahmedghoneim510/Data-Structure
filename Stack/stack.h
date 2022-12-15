#include "Global.h"
#define LINKED_STACK


void TestImplementation();
void push (StackEntry *,Stack *);
void pop (Stack *);
_Bool stackEmpty (Stack *);
void CreateStack	(Stack *);
void StackTop (StackEntry *, Stack *);
int	StackSize (Stack *);
void ClearStack (Stack *);
void TraverseStack (Stack *, void (*)(StackEntry));
