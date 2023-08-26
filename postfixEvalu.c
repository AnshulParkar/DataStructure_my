#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 50

int i;
int top = -1;
int stack[MAX_SIZE]; // Changed data type to int
char postfix[MAX_SIZE];

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

void push(int value) // Changed parameter type to int
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

int pop() // Changed return type to int
{
    if (isEmpty())
    {
        printf("Stack is underflow\n");
        return 0; // Return a default value
    }
    else
    {
        return stack[top--];
    }
}

int evaluatePostfix(char postfix[])
{
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        if (postfix[i] >= '0' && postfix[i] <= '9')
        {
            push(postfix[i] - '0');
        }
        else
        {
            int operand2 = pop();
            int operand1 = pop();

            switch (postfix[i])
            {
                case '+':
                    push(operand1 + operand2);
                    break;
                case '-':
                    push(operand1 - operand2);
                    break;
                case '*':
                    push(operand1 * operand2);
                    break;
                case '/':
                    push(operand1 / operand2);
                    break;
            }
        }
    }
    return stack[top]; // Return the final result
}

int main()
{
    int choice;
    while (1)
    {
        printf("Press 1 to Start or Press 2 to Exit: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the postfix expression: ");
            scanf("%s", postfix);
            int Answer = evaluatePostfix(postfix);
            printf("Result: %d\n", Answer);
            break;

        case 2:
            printf("Thank you!\n");
            exit(0);
        default:
            printf("Invalid choice!\n");
            break;
        }
    }
    return 0;
}
