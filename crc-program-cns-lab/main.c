/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<string.h>
char data[100],concatdata[117],src_crc[17],dest_crc[17],frame[18],divident[18];
char divisor[18]="100010000001000001",res[17]="0000000000000000";
void crc_cal(int node)
{
    int i,j;
    for(j=17;j<=strlen(concatdata);j++)
    {
        if(divident[0]=='1')
        {
        for(i=1;i<=16;i++)
            if(divident[i]!=divisor[i])
                divident[i-1] = '1';
            else
                divident[i-1] = '0';
            
        }
        
            
        else
        {
            for(i=1;i<=16;i++)
            divident[i-1]=divident[i];
        }
        if(node==0)
        
            divident[i-1]=concatdata[j];
        
        else
        
            divident[i-1]=frame[j];
        }
    divident[i]="\0";
    printf("\n crc is %s\n",divident);
    if(node==0)
    {
        strcpy(src_crc,divident);
    }
    else
    
        strcpy(dest_crc,divident);
}
int main()
{
    int i;
    printf("\nAT SOURCE NODE\n Enter the message to be sent\n");
    gets(data);
    strcpy(concatdata,data);
    strcat(concatdata,"0000000000000000");
    for(i=0;i<=16;i++)
    divident[i]=concatdata[i];
    divident[i]='\0';
    crc_cal(0);
    printf("\n data is:\t");
    puts(data);
    printf("the frame transmitted is:\t");
    printf("\n%s%s",data,src_crc);
    printf("\n SOURCE NODE transmitted THE DATA\n ");
    printf("\n AT DESTINATION NODE:\n Enter the frame received:\t");
    gets(frame);
    for(i=0;i<=16;i++)
    divident[i]=frame[i];
    divident[i]='\0';
    crc_cal(1);
    if((strcmp(dest_crc,res))==0)
        printf("\n received frame is error free:\n");
    else
        printf("\n receivedframe contains one or more error\n");
    return 1;
    
    
}
