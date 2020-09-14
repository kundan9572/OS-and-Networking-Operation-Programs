#include<stdio.h>
#include<string.h>
char data[100],condata[117],src_crc[17],dest_crc[17],frame[120],div[18];
char divisor[18]="10001000000100001",res[17]="0000000000000000";
void crc_cal(int node)
{
	int i,j;
	for(j=17;j<=strlen(condata);j++)
	{
		if(div[0]=='1')
		{
			for(i=1;i<=16;i++)
			{
				if(div[i]!=divisor[i])
					div[i-1]='1';
				else
					div[i-1]='0';
			}
		}
		else
		{
			for(i=1;i<16;i++)
				div[i-1]=div[i];
		}
		if(node==0)
			div[i-1]=condata[j];
		else
			div[i-1]=frame[j];
	}
	div[i]='\0';
	printf("\nCRC is %s",div);
	if(node==0)
		strcpy(src_crc,div);
	else
		strcpy(dest_crc,div);
}
main()
{
	int i;
	printf("At source node \n Enter the msg to be sent:\t");
	gets(data);
	strcpy(condata,data);
	strcat(condata,"00000000000000000");
	for(i=0;i<16;i++)
		div[i]=condata[i];
	div[i]='\0';
	crc_cal(0);
	printf("\ndata is");
	puts(data);
	printf("The frame transmitted is");
	printf("\n%s%s",data,src_crc);
	printf("\ndestination node\nEnter recieved frame");
	gets(frame);
	for(i=0;i<=16;i++)
		div[i]=frame[i];
	div[i]='\0';
	crc_cal(1);
	if(strcmp(dest_crc,res)==0)
		printf("Recieved freame is error free");
	else
		printf("Recieved frame has one or more errors");
	return 1;

}

