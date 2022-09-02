#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

void creatStack(Stack *ps)
{
    ps->top =0;
}

int Push(StackEntry e,Stack *ps)
{
    if(ps->top == MaxStack)
    {
       return 0;
    }
    else
    { ps->entry[ps->top] = e;
      ps->top++;
      return 1;
    }
}

int StackFull(Stack *ps)
{
    return ps->top >= MaxStack;
}

int Pop(StackEntry *pe,Stack *ps)
{
    if(ps->top == 0)
    {
        return 0;
    }
    else
    {
        ps->top--;
       *pe = ps->entry[ps->top];
       return 1;
    }
}

int StackEmpty(Stack *ps)
{
    return ps->top == 0;
}

int StackSize(Stack *ps)
{
    return ps->top;
}

void ClearStack(Stack *ps)
{
    ps->top = 0;
}

void StackTop(StackEntry *pe, Stack *ps)
{
    *pe = ps->entry[ps->top-1];
}

void TraverseStack(Stack *ps ,void(*pe)(StackEntry))
{
    for(int i = ps->top; i>0; i--)
    {
        (*pe)(ps->entry[i-1]);
    }
}

