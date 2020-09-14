/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<unistd.h>
int main()
{
    int pid,ch;
    char cmd[20];
    pid=fork();
    if(pid==0)
    {
        printf("\n child process \n");
        do
        {
            printf(" enter the command\n");
            scanf("%s",&cmd);
            system(cmd);
            printf(" do you want to continue\n");
            scanf("%d",&ch);
        }
        while(ch!=0);
    }
    else
        wait();
}
