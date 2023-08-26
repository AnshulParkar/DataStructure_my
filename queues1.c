#include<stdio.h>
int max=5;
int front=-1;
int rear=-1;
int a[5];

int i;

int isFull()
{
    if(rear==max-1)
    {

    }
        printf("Overflow");
    return 0;

}
int isEmpty()
{
if(front==-1 && rear==-1)
printf("Underflow");
return 0;
}
void enqueue()
{ int val;
if(isFull())
{
printf("Overflow");
return;
}
else
{
scanf("%d",&val);
rear++;
}
a[rear]=val;
}
void dequeue()
{ int val;
if(isEmpty())
{
    printf("Underflow");
}
else
{
val=a[front];
if(front==rear)
front=rear=-1;
else
front=front+1;
printf("%d",val);
}
}
void fron()
{
if(isEmpty())
printf("Underflow");
else
printf("%d",a[front]);
}
void display()
{
if(isEmpty())
{
printf("Underflow");
}
else
for(i=front;i<=rear;i++)
printf("%d",a[i]);
}
int main()
{
int ch;
while(1)
{
printf("\nEnter your choice\n");
      printf("\n1.isFull 2.isEmpty 3.Enqueue 4.Dequeue 5.Front 6.Display \n");
      scanf("%d",&ch);
      switch(ch)
      {
 case 1:
 isFull();
 break;
 case 2:
 isEmpty();
 break;
 case 3:
 enqueue();
 break;
 case 4:
 dequeue();
 break;
 case 5:
 fron();
 break;
 case 6:
 display();
 break;
 }
}
}

