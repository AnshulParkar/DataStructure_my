#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_SIZE 50

int i;
int top = -1;
char stack[MAX_SIZE];
char result[MAX_SIZE];
char infix[MAX_SIZE];

bool isEmpty()
{
    return top == -1;
}

bool isFull()
{
    return top == MAX_SIZE - 1;
}

int precedence(char operator)
{
    if (operator == '+' || operator == '-')
        return 1;
    if (operator == '*' || operator == '/')
        return 2;
    return 0;
}

void push(char value)
{
    if (isFull())
    {
        printf("Stack is overflow\n");
        return;
    }
    else
    {
        stack[++top] = value;
    }
}

char pop()
{
    if (isEmpty())
    {
        printf("Stack is underflow\n");
        return '\0';
    }
    else
    {
        return stack[top--];
    }
}

void infixToPostfix()
{
    int j = 0;
    char c;
    for (i = 0; infix[i] != '\0'; i++)
    {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
        {
            result[j++] = infix[i];
        }
        else if (infix[i] == '(')
        {
            push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (!isEmpty() && stack[top] != '(')
            {
                result[j++] = pop();
            }
            pop(); // Pop the '('
        }
        else // Operator
        {
            while (!isEmpty() && stack[top] != '(' && precedence(stack[top]) >= precedence(infix[i]))
            {
                result[j++] = pop();
            }
            push(infix[i]);
        }
    }
    while (!isEmpty())
    {
        result[j++] = pop();
    }
    result[j] = '\0';
}

int main()
{
    int choice;
    printf("Press 1 to Start or Press 2 to Exit: ");
    scanf("%d",&choice);
    while(1)
    {
        printf("Press 1 to Start or Press 2 to Exit: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the infix expression: ");
            scanf("%s", infix);

            infixToPostfix();

            printf("Postfix expression: %s\n", result);
            break;

        case 2:
            printf("Thank you!");
            exit(0);
        }
    }
    return 0;
}
