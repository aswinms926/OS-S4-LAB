#include<stdio.h>
int main()
{
    int i,j,p[30],tat[30],bt[30],wt[30],n,tot_tat=0,tot_wt=0,SJF_tat=0,SJF_wt=0;
    float avg_tat,avg_wt;

    printf("Enter the number of processes : ");
    scanf("%d",&n);
    printf("Enter the burst time of each processes : \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
        p[i]=i;
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(bt[i]>bt[j])
            {
                swap(&bt[i],&bt[j]);
                swap(&p[i],&p[j]);
            }
        }
    }
    printf("SJF ALGORITHM : \n");
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
    printf("\n PROCESS\t\tBURST_TIME\tTURN_AROUND_TIME\tWAITING_TIME");
    for (i = 0; i < n; i++) {
    printf("\n process[%d]\t\t%d\t\t%d\t\t\t%d",p[i],bt[i],tat[i],wt[i]);
    }
    printf("\n Totl turn around time is : %d",tot_tat);
    printf("\n Totl waiting time is : %d",tot_wt);
    printf("\n avg turn around time is : %d",tot_tat/n);
    printf("\n avg waiting time is : %d",tot_wt/n);

    

}
void swap(int *a,int *b)
    {
        int t;
        t=*a;
        *a=*b;
        *b=t;
    }
