#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int i;
int top=-1;
int stack[5];

bool isEmpty()
{
    if(top==-1)
    {
        printf("Stack is Empty\n");
        return 1;
    }
    else{
        printf("Stack is not Empty\n");
    }
    return 0;
}

bool isFull()
{
    if(top==5-1)
    {
        printf("Stack is Full\n");
    }
    else
    {
        printf("Stack is not Full\n");
    }
}
int peek()
{   int value;
    if(isEmpty())
    {
        printf("Stack is Empty\n");
    }
    else
        {
            value = stack[top];
        printf("peek value is %d",value);
        }
    return 0;
}
void display()
{
    if(isEmpty())
    {
        printf("Stack is Empty\n");
        return;
    }
    else
    {
        for(i=top;i>=0;i--)
        {
            printf("%d",stack[i]);
        }
    }
}
void size()
{
    if(isEmpty())
    {
        printf("Stack is Empty\n");
        return;
    }
    else
    {
        printf("Size of the stack is %d\n",top+1);
    }
}
void push(int value)
{
    if(top==5-1)
    {
        printf("Stack is overflow");
        return;
    }
    else
    {
        stack[++top]=value;
    }
}

void pop()
{
    int x;
    if(top == -1)
    {
        printf("Stack is underflow\n");
        return;
    }
    else
    {
        x=stack[top--];
        printf("Pop value is %d\n",x);
        return;
    }
}

int main()
{
    int choice,value;
    while(1)
    {
        printf("1.isEmpty\n 2.isFull\n 3.Peek\n 4.Display\n 5.CheckSize\n 6.Push\n 7.Pop\n 8.exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            isEmpty();
            break;
        case 2:
            isFull();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            size();
            break;
        case 6:
            printf("Enter the value to be pushed\n");
            scanf("%d",&value);
            push(value);
            break;
        case 7:
            pop();
            break;
        case 8:
            printf("Thank you!!");
            exit(0);
            default:
            printf("Invalid Choice");
        }
    }
    return 0;
}
