#include<stdio.h>

struct Block
{
    int id,size,allc;
}B[10];
struct Process
{
    int id,size,blkno;
}P[10];

void main()
{
    int m,n,i,j;
    printf("Enter the no of block : ");
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
       printf("Enter the id and size of block %d : ", i + 1);
        scanf("%d %d", &B[i].id, &B[i].size);
        B[i].allc=-1;
    }
    printf("Enter the no of process : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
         printf("Enter the id and size of process %d : ", i + 1);
        scanf("%d %d", &P[i].id, &P[i].size);
        P[i].blkno=-1;
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(B[j].allc==-1 && B[j].size>=P[i].size)
            {
                P[i].blkno=B[j].id;
                B[j].allc=1;
                break;
            }
        }
    }
    printf("process\tstate\tblock\n");
    for(i=0;i<n;i++)
    {
        if(P[i].blkno!=-1)
        {
            for(j=0;j<m;j++)
            {
                if(B[j].id==P[i].blkno)
                {
                    printf("%d\t\t%d\t\t%d\n",P[i].id,P[i].size,B[j].size);
                    break;
                }
            }


        }
        else{
            printf("%d\t waiting\t\tNA\n",P[i].id);
        }
    }
     
}
