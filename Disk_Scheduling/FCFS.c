#include<stdio.h>
void main()
{
    int head,i,a[100],distance,seektime=0,n;
    printf("Enter the head position : ");
    scanf("%d",&head);

    printf("Enter the number of disk request  : ");
    scanf("%d",&n);


        printf("Enter the   disk request  : ");
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }

       
        printf("fcfs");
        for(i=0;i<n;i++)
        {
            distance=(head>a[i])?head-a[i]:a[i]-head;
            printf("head movement from %d to %d: %d\n",head,a[i],distance);
            seektime=seektime+distance;
            head=a[i];
        }
        printf("total seektime is : %d",seektime);

}