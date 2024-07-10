#include<stdio.h>
void main()
{
    int i,j=0,k=0,a[50],frame[50],time[50],avail=0,count=0,n,no,least=0;

    printf("Enter the number of pages: ");
    scanf("%d",&n);

        printf("Enter the  page numbers : ");
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }


         printf("Enter the  numer of frames : ");
         scanf("%d",&no);
        for(k=0;k<no;k++)
        {
            frame[k]=-1;
            time[k]=0;
        }


printf("\nRef_string\t\tFrames\n");
        for(i=0;i<n;i++)
        {
            printf("%d\t\t",a[i]);
            avail=0;

            for(k=0;k<no;k++)
            {
                if(frame[k]==a[i])
                {
                    avail=1;
                    time[k]=i+1;
                    break;
                }
            }
            if(avail==0)
            {
                    least=0;
                    for(k=0;k<no;k++)
                    {
                        if(time[k]<time[least])
                        {
                            least=k;
                        }
                    }

                    frame[least]=a[i];
                    time[least]=i+1;
                    count++;

                    for(k=0;k<no;k++)
                    {
                        if(frame[k]!=-1)
                        {
                            printf("%d\t",frame[k]);
                        }
                        else
                        {
                            printf("-\t");
                        }
                    }
            }
            else{
                printf("hit\t");

            } printf("\n");
            

        }
       

        printf("page fault is %d",count);




}