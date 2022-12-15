#include <stdio.h>
#include <stdlib.h>
int IsDigit(char c)
{
    return(c>='0' && '9'>=c)
}
int precedent(char op1,char op2)
{
    if(op1=='$')
        return 1;
    if( (op1=='*') || (op1=='/'))
        return !(op2=='$')
    if( (op1=='+') || (op1=='-'))
        return ((op2!='$') && (op1!='*') &&(op1!='/'))

}
double Evaluatepostfix(char exper[])
{
    int i;
    char c;
    double op1,op2,val;
    Stack s;
    CreatStack(&s);
    for(i=0;(c=exper[i])!='\0';i++)
    {
        if(IsDigit(c))
        {
            PushStack((double)(c-'0'),&s);
        }
        else
        {
            PopStack(&op2,&s);
            PopStack(&op1,&s);
            val=Oper(op1,op2,c);
            PushStack(val,&s);
        }
        PopStack(&val,&s);
        return val;
    }
}
void InfixtoPostfix(char infex[],char postfix[])
{
    int i,j;
    char op,c;
    Stack s;
    CreatStack(&s);
    for (int i =0;j=0;(c=infex[i])!='\0';i++)
    {
        if(IsDigit(c))
        {
            postfix[j++]=c;
        }
        else
        {
            if(!StackEmpty(&s))
            {
               StackTop(&op,&s);
               while(!StackEmpty(&s) && precedent(op,c))
               {
                   pop(&op,&s);
                   postfix[j++]=op;
                   if(!StackEmpty(&s))
                     StackTop(&op,&s);
               }
            }
            push(c,&s);
        }
        while(!StackEmpty(&s))
        {
            pop(&op,&s);
            postfix[j++]=op;
        }
        postfix[j++]='\0';
    }
}
int main()
{
    char infix[]="1+2*3$4/5+6";
    char postfix[80];
    InfixtoPostfix(infix,postfix);

    char xper[]="345*+2$";
    double x;
    x=Evaluatepostfix(exper);

    return 0;
}
