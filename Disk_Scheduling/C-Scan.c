 #include<stdio.h>

 int head,n,i,size,seektime=0,distance=0,a[100];
void sort(int arr[],int n)
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
    printf("Enter the no of disk req : ");
    scanf("%d",&n);
    printf("Enter the size of disk req : ");
    scanf("%d",&size);
    printf("Enter the disk req : ");
    for(i=0;i<n;i++)
    {
                scanf("%d",&a[i]);

    }
    a[n]=head;
    n++;
    sort(a,n);
    int pos;

    for(i=0;i<n;i++)
    {
        if(a[i]==head)
        {
            pos =i;
            break;
        }
    }
    printf("C-Scan");
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
    distance=size-1;
    printf("head movement from %d to 0: %d\n",size-1,distance);
        seektime+=distance;

     for(i=0;i<pos;i++)
     {
        if(i==0)
        {
            distance=a[i];
        }
        else{
            distance=a[i]-a[i-1];
        }
        printf("head movement from %d to %d: %d\n",(i==0)?size-1:a[i-1],a[i],distance);
        seektime+=distance;

     }   
printf("%d is total seektime",seektime);

 }