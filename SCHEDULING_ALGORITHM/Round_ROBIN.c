 #include<stdio.h>
 void main()
 {
    int i,limit,x,total=0,counter=0,t;
    int tot=0,wt=0,bt[10],temp[10];
    float avg_tot=0,avg_wt=0;

    printf("Enter the number of processors :");
    scanf("%d",&limit);
    x=limit;
    for(i=0;i<limit;i++)
    {
        printf("Enter the details of the processor :\n");
        printf("Burst time : ");
        scanf("%d",&bt[i]);
        temp[i]=bt[i];

    }
    printf("Enter the time quantum number : ");
    scanf("%d",&t);
     printf("\nPROCESSES\t\tBURST_TIME\t\tTURN_AROUND_TIME\t\tWAITING_TIME\n");
     for(i=0,total=0;x!=0;)
     {
        if(temp[i]<=t &&temp[i]>0)
        {
            total+=temp[i];
            temp[i]=0;
            counter=1;
        }
        else if(temp[i]>0)
        {
            temp[i]-=t;
            total+=t;
        }
        if(temp[i]==0 && counter ==1)
        
        {
            x--;
            printf("\nprocess[%d]\t\t%d\t\t\t%d\t\t\t\t%d",i+1,bt[i],total,total-bt[i]);
             wt=wt+total-bt[i];
            tot=tot+total;
           
            counter=0;
        }
        if(i==limit-1)
        {
            i=0;
        }else{
            i++;
        }
        



     }
     avg_tot=(float)tot/limit;
        avg_wt=(float)wt/limit;
        printf("\nAVGERAGE TURN AROUNF TIME IS %f",avg_tot);
         printf("\nAVGERAGE WAITITNG TIME IS %f",avg_wt);
 }