/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

typedef struct rr 
{
    int pid,bt,wt,tat,bt_bal;
}RR;

main()
{
    RR p[10];
    int i,j,n,tq;
    int sum_bt=0,sum_wt=0,sum_tat=0,tq_used=0;
    printf("enter the no of process\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf(" enter the burst time for process %d\n",i+1);
        p[i].pid=i+1;
        scanf("%d",&p[i].bt);
        p[i].bt_bal=p[i].bt;
        
    }
    printf(" enter the time quantum number\n");
    scanf("%d",&tq);
    for(i=0;i<n;i++)
    sum_bt +=p[i].bt;
        printf(" sum of burst time is=%d\n",sum_bt);
    do
    {
        for(i=0;i<n;i++)
        {
            if(p[i].bt_bal > 0 && p[i].bt_bal <=tq)
            {
                tq_used +=p[i].bt_bal;
                p[i].tat=tq_used;
                p[i].wt=p[i].tat - p[i].bt;
                p[i].bt_bal=0;
            }
            else if( p[i].bt_bal >0)
            {
                tq_used +=tq;
                p[i].bt_bal -=tq;
            }
            else if(p[i].bt_bal < 0)
            {
                printf("\n error burst time cannot be negative \n");
            }
        }
    }
    while( tq_used !=sum_bt);
    for(i=0;i<n;i++)
        sum_wt +=p[i].wt;
    for(i=0;i<n;i++)
        sum_tat +=p[i].tat;
    printf("\n total burst time is :%d\n",sum_wt);
    printf("\n avg burst time is=%.2f\n",(float)sum_wt/n);
    
    printf("\n");
    
    printf("\n total turnaround time=%d\n",sum_tat);
    printf("\n avg turnaround time=%.2f\n",(float)sum_tat/n);
}
