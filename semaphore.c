#include<stdio.h>
int mutex=1,empty=3,full=0,x=0;
int wait(int *s)
{
    return --(*s);
}
int signal(int *s)
{
    return ++(*s);
}
void producer()
{
    mutex=wait(&mutex);
    full=signal(&full);
    empty=wait(&empty);
    x++;
    printf("Producer produces item : %d",x);
    mutex=signal(&mutex);
}
void consumer()
{
    mutex=wait(&mutex);
    full=wait(&full);
    empty=signal(&empty);
    printf("Consumer consumes item : %d",x);
    x--;
    mutex=signal(&mutex);

}
void main()
{
    int ch;
    while(1)
    {
    printf("\nSelect 1)PRODUCER\t2)CONSUMER\t3)EXIT\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            if(mutex==1 &&empty!=0)
            {
                producer();
            }
            else{
                printf("BUFFER is full ");
            }
            break;
        case 2:
            if(mutex==1 && full!=0)
            {
                consumer();
            }  
            else{
                printf("BUFFER is empty ");
            } 
            break; 
        case 3 :
            printf("Exiting program !!!!!");
            return ;
        default :
            printf("INVALID choise !!! select again !");    

    } 
    }
}