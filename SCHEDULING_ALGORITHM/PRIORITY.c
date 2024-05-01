#include<stdio.h>
void swap(int *a,int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
void main()
{
    int i,j,n,tat[30],p[30],bt[30],wt[30],pr[30],tot_tat=0,tot_wt=0;
    float avg_tat=0,avg_wt=0;

    printf("Enter the number of processors : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the burst time and priority of process[%d]",i+1);
        scanf("%d%d",&bt[i],&pr[i]);
        p[i]=i;
    
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(pr[i]>pr[j])
            {
                swap(&bt[i],&bt[j]);
                swap(&pr[i],&pr[j]);
                swap(&p[i],&p[j]);

            }
        }
    }

    for(i=0;i<n;i++)
    {
        if(i==0)
        {
            tat[i]=bt[i];
        }
        else{
            tat[i]=tat[i-1]+bt[i];
            
        }
        tot_tat=tot_tat+tat[i];
    }
    wt[0]=0;
     for(i=1;i<n;i++)
     {
        wt[i]=wt[i-1]+bt[i-1];
        tot_wt=tot_wt+wt[i];
     }
     printf("\nPROCESSES \t\tBURST_TIME\t\tPRIORITY\t\tTURN_AROUND_TIME\t\tWAITING _TIME");
     for(i=0;i<n;i++)
     {
        printf("\nprocess[%d]\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d",p[i]+1,bt[i],pr[i],tat[i],wt[i]);
     }
    printf("\n\nTotal Turn around Time:%d",tot_tat);
    printf("\nAverage Turn around Time :%d ", tot_tat/n);
    printf("\nTotal Waiting Time:%d",tot_wt);
    printf("\nTotal avg. Waiting Time:%d",tot_wt/n);

}
