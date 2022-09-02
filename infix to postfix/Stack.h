


#ifndef _STACK_H
#define _STACK_H
#define StackEntry ElementType
#define MaxStack 100


typedef struct elementtype
{
    short int etype;
    union
    {
        double numbers;
        char operands;

    }info;
}ElementType;


typedef struct stack
{
    int top;
    StackEntry entry[MaxStack];
}Stack;



void creatStack(Stack *ps);
int Push(StackEntry e,Stack *ps);
int StackFull(Stack *ps);
int Pop(StackEntry *pe,Stack *ps);
int StackEmpty(Stack *ps);
int StackSize(Stack *ps);
void ClearStack(Stack *ps);
void StackTop(StackEntry *pe, Stack *ps);
void TraverseStack(Stack *ps ,void(*pe)(StackEntry));

#endif
