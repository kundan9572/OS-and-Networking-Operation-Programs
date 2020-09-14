/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

typedef struct priority
{
    int pid,bt,tat,wt,prty;
}PRIORITY;

int main()
{
    PRIORITY p[10],temp;
    int i,j,n;
    int sum_bt=0,sum_wt=0,sum_tat=0;
    printf(" enter the number of process \n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter the burst time and priority for process %d \n",i+1);
        p[i].pid=i+1;
        scanf("%d%d",&p[i].bt,&p[i].prty);
        
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(p[i].prty>p[j].prty)
            {
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        sum_bt +=p[i].bt;
        p[i].tat=sum_bt;
        p[i].wt=p[i].tat-p[i].bt;
        sum_wt +=p[i].wt;
        sum_tat +=p[i].tat;
        
    }
    printf("\n total waiting time =%d\n",sum_wt);
    printf("\n average waiting time =%.2f\n",(float)sum_wt/n);
    
    printf("\n");
    printf("\n total turnaround time=%d\n",sum_tat);
    printf("\n average turnaround time=%.2f\n",(float)sum_tat/n);
}
