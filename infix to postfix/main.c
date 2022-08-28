#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Stack.h"
#define StackEntry char



Stack Infix , Postfix ,stack;
char infix[100];
char postfix[100];

int Power(char symbol)
{
    switch (symbol)
    {
    case '^':
        return 3;
        break;

    case '/':
    case '*':
        return 2;
        break;

    case '+':
    case '-':
        return 1;
        break;
    default:
        return 0;
        break;
    }
}

void IntoPostfix()
{
    char popped ,Top,check;
    for (int i = 0; i < strlen(infix); i++)
    {
        check = infix[i];
        switch (check)
        {
        case '(':
            Push(check,&Infix);
            break;

        case ')':
            Pop(&popped,&Infix);
            while (popped != '(')
            {
                Push(popped,&Postfix);
                Pop(&popped,&Infix);
            }
            break;

        case '^':
        case '*':
        case '/':
        case '+':
        case '-':
            StackTop(&Top,&Infix);
            while (!StackEmpty(&Infix) && Power(Top) >= Power(check))
            {
                Pop(&popped,&Infix);
                Push(popped,&postfix);
                StackTop(&Top,&Infix);
            }
            Push(check,&Infix);
            break;

        default:
            Push(check,&Postfix);
            break;
        }


    }

    while (!StackEmpty(&Infix))
    {
        Pop(&popped,&Infix);
        Push(popped,&Postfix);
    }

    for (int i = StackSize(&Postfix)-1 ; i >=0; i--)
    {
        Pop(&popped,&Postfix);
        postfix[i]=popped;
    }
    printf("The PostFix expression is :: ");
     for (int i = 0; i < strlen(postfix); i++)
    {
        printf("%c",postfix[i]);
    }
    printf("\n");
}


long int Calculate()
{
    char a,b;
    char Popped;
    for (int i = 0; i < strlen(postfix); i++)
    {
        if(postfix[i] >= '0' && postfix[i] <= '9')
        {
            Push(postfix[i],&stack);
        }
        else
        {
           Pop(&a,&stack);
           Pop(&b,&stack);
           a = a - '0';
           b = b - '0';
           switch (postfix[i])
           {
              case '+':
                 Push((b+a),&stack);
                 break;

              case '-':
                 Push((b-a),&stack);
                 break;

              case '*':
                 Push((b*a),&stack);
                 break;

              case '/':
                 Push((b/a),&stack);
                 break;

              case '^':
                 Push(pow(b,a),&stack);
                 break;
           }
        }
    }

    Pop(&Popped,&stack);
    return Popped;

}

int main()
{
    long int result;
     printf("Enter the expression\n");
     gets(infix);

     IntoPostfix();
     result = Calculate();
     printf("the evaluation of postfix is :: %ld",result);


    return 0;
}


