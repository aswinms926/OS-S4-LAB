
#include<stdio.h>
 int i,head,a[20],n,size,distance=0,seektime=0;
void  bubblesort(int arr[],int n)
{
    int t;
    for(i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
}
 void main()
 {
    printf("Enter the head position : ");
    scanf("%d",&head);
    printf("Enter the number of disk req : ");
    scanf("%d",&n);
    printf("Enter the size of disk : ");
    scanf("%d",&size);
    printf("Enter the disk req : ");
    for(i=0;i<n;i++)
    {
                scanf("%d",&a[i]);

    }
    a[n]=head;
    n++;
    bubblesort(a,n);
    int pos;
    for(i=0;i<n;i++)
    {
        if(a[i]==head)
        {
            pos =i;
            break;
        }
    }
    printf("scan");
    for(i=pos;i<n-1;i++)
    {
        distance=a[i+1]-a[i];
        printf("head movement from %d to %d: %d\n",a[i],a[i+1],distance);
        seektime+=distance;
    }
    if(a[n-1]!=size-1)
    {
        distance=size-1-a[n-1];
        printf("head movement from %d to %d: %d\n",a[n-1],size-1,distance);
        seektime+=distance;
    }
    if(pos>0)
    {
         distance=size-1-a[pos-1];
        printf("head movement from %d to %d: %d\n",size-1,a[pos-1],distance);
        seektime+=distance;
    }
    for(i=pos-1;i>0;i--)
    {
        distance=a[i]-a[i-1];
        printf("head movement from %d to %d: %d\n",a[i],a[i-1],distance);
        seektime+=distance;
    }
    printf("\n%d is the total seektime",seektime);
 }