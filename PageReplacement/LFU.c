 #include<stdio.h>
 void main()
 {
    int i,j=0,k=0,a[50],frame[50],freq[50],n,no,avail=0,least,count;

    printf("Enter the number of pages : ");
    scanf("%d",&n);

        printf("Enter the page numbers : ");
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }

        printf("Enter the number of frames : ");
    scanf("%d",&no);

        for(k=0;k<no;k++)
        {
            frame[k]=-1;
            freq[k]=0;
        }

        printf("\nREF_STRING\t\tframes\n");
        for(i=0;i<n;i++)
        {
            printf("%d\t\t",a[i]);
            avail=0;

            for(k=0;k<no;k++)
            {
                if(frame[k]==a[i])
                {
                    avail=1;
                    freq[k]++;
                    break;
                }
            }
            if(avail==0)
            {
                least=0;
                for(k=0;k<no;k++)
                {
                    if(freq[k]<freq[least])
                    {
                        least=k;
                    }
                }

                frame[least]=a[i];
                freq[least]=1;
                count++;


                for(k=0;k<no;k++)
                {
                    if(frame[k]!=-1)
                    {
                        printf("%d\t",frame[k]);
                    }else{
                        printf("-\t");
                    }
                }

            }
            else{
                printf("HIT\t");
            }
            printf("\n");
        }
        printf("page fault is %d",count);

 }