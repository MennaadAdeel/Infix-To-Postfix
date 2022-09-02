#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Stack.h"
#define StackEntry ElementType



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
    ElementType e,popped,check,Top;
    popped.info.operands;
    for (int i = 0; i < strlen(infix); i++)
    {
        check.info.operands = infix[i];
        switch (infix[i])
        {
        case '(':
            Push(check,&Infix);
            break;

        case ')':
            Pop(&popped,&Infix);
            while ( popped.info.operands != '(')
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
            while (!StackEmpty(&Infix) && Power(Top.info.operands) >= Power(check.info.operands))
            {
                Pop(&popped,&Infix);
                Push(popped,&Postfix);
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
        postfix[i]=popped.info.operands;
    }
    printf("The PostFix expression is :: ");
     for (int i = 0; i < strlen(postfix); i++)
    {
        printf("%c",postfix[i]);
    }
    printf("\n");
}

double Calculate()
{
    
    ElementType Popped, toint,a,b,result;
    Popped.info.numbers;

    for (int i = 0; i < strlen(postfix); i++)
    {
        if(postfix[i] >= '0' && postfix[i] <= '9')
        {
            toint.info.numbers =(postfix[i] - '0');
            Push(toint,&stack);
        }
        else
        {
           Pop(&a,&stack);
           a.info.numbers;
           Pop(&b,&stack);
           // a = a - '0';
           // b = b - '0';
           b.info.numbers;
           switch (postfix[i])
           {
              case '+':
                result.info.numbers = (b.info.numbers + a.info.numbers);
                 Push(result,&stack);
                 break;

              case '-':
                 result.info.numbers  = (b.info.numbers - a.info.numbers);
                 Push(result,&stack);
                 break;

              case '*':
                 result.info.numbers  = (b.info.numbers * a.info.numbers);
                 Push(result,&stack);
                 break;

              case '/':
                 result.info.numbers  = (b.info.numbers + a.info.numbers);
                 Push(result,&stack);
                 break;

             case '^':
                 result.info.numbers  = pow(b.info.numbers,a.info.numbers);
                 Push(result,&stack);
                 break;
           }
        }
    }

    Pop(&Popped,&stack);
    return Popped.info.numbers;

}

int main()
{
    double result;
     printf("Enter the expression\n");
     gets(infix);

     IntoPostfix();
     result = Calculate();
     printf("the evaluation of postfix is :: %0.2f",result);


    return 0;
}


