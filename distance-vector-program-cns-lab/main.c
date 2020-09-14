/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<string.h>
struct rtable{
    int dist[20],next_node[20];
}table[20];
int cost[20][20],n;
int distvec()
{
    int i,j,k,count=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            table[i].dist[j]=cost[i][j];
            table[i].next_node[j]=j;
        }
    }
    do
    {
        count=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                for(k=0;k<n;k++)
                {
                    if(table[i].dist[j]>cost[i][k]+table[k].dist[j])
                    {
                        table[i].dist[j]=table[i].dist[k]+table[k].dist[j];
                        table[i].next_node[j]=k;
                    }
                }
            }
        }
    }
    while(count!=0);
}
int main()
{
    int i,j;
    printf("enter the no. of vertex:\n");
    scanf("%d",&n);
    printf("\nenter the cost adjacency matrix\n");
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    scanf("%d",&cost[i][j]);
    distvec();
    for(i=0;i<n;i++)
    {
        printf("\nstate value of router is:%c",i+65);
        printf("\ndestnode\tnextnode\tdistance \n");
        for(j=0;j<n;j++)
        {
            if(table[i].dist[j]==99)
                printf("\n%c\t\t-\t\tinfinite\n",j+65);
            else
                printf("\n%c\t\t%c\t\t%d\n",j+65,table[i].next_node[j]+65,table[i].dist[j]);
        }
    }
}