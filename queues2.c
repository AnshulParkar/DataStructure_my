#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 5

int front = -1;
int rear = -1;
int q[MAX_SIZE];

int isEmpty()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue is empty/underflow\n");
        return 1;
    }
    return 0;
}

int isFull()
{
    if(rear == MAX_SIZE - 1)
    {
        printf("Queue is Full/overflow\n");
        return 1;
    }
    return 0;
}

void enqueue()
{
    int val;
    if(isFull())
    {
        return;
    }
    else if(isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear = rear + 1;
    }
    printf("Enter the Value to be Enqueued\n");
    scanf("%d", &val);
    q[rear] = val;
}

void dequeue()
{
    int val;
    if(isEmpty())
    {
        return;
    }
    else
    {
        val = q[front];
        if(front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = front + 1;
        }
        printf("So the dequeued value is %d\n", val);
    }
}

void front_element()
{
    if(isEmpty())
    {
        return;
    }
    else
    {
        printf("Front element is %d\n", q[front]);
    }
}

void display()
{
    int i;
    if(isEmpty())
    {
        return;
    }
    else
    {
        for(i = front; i <= rear; i++)
        {
            printf("So the queue contains %d\n", q[i]);
        }
    }
}

int main()
{
    int choice;
    while(1)
    {
        printf("Select one of the following\n 1.Enqueue\n 2.Dequeue\n 3.Front\n 4.Display\n 5.isEmpty\n 6.isFull\n 7.Exit\n");
        printf("Enter your Choice:\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                front_element();
                break;

            case 4:
                display();
                break;

            case 5:
                isEmpty();
                break;

            case 6:
                isFull();
                break;

            case 7:
                printf("Thank You!\n");
                exit(0);
                break;

            default:
                printf("Invalid Choice\n");
                break;
        }
    }
    return 0;
}
