//bubble sorting technique Ds lab 1
#include<stdio.h>

int main()
{
    int i,j,a[10],temp,n;
    printf("Enter the size of Array elements: ");
    scanf("%d",&n);
    printf("Enter the Array elements: ");
    for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                 temp=a[j];
                 a[j]=a[j+1];
                 a[j+1]=temp;
            }
        }
    }
    printf("So your array after sorting is:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}

