

/* @JUDGE_ID: 34556CP 739 C "" */
/** Submited via Valladolid ACM Online Judge Submit page v6.00 **/
/** IP: 172.16.29.251 - CRC: CADE53BA **/
/** Date: 2003-12-01 05:34:18 +0100 **/


#include<stdio.h>

int main()
{
	int b[]={0,1,2,3,0,1,2,0,0,2,2,4,5,5,0,1,2,6,2,3,0,1,0,2,0,2};
	int i,j;
	char a[25];
	
	printf("         NAME                     SOUNDEX CODE\n");
	while(gets(a))
	{
		j=0;
		printf("         ");
		printf("%-25s",a);
		printf("%c",a[0]);
		for(i=1;a[i]&&j!=3;i++)
		{
			if(!(b[a[i]-65]))
				continue;
			if(b[a[i]-65]!=b[a[i-1]-65])
			{
				j++;
				printf("%d",b[a[i]-65]);
			}
		}
		if(j!=3)
		{
			while(j!=3)
			{
				printf("0");
				j++;
			}
		}
		printf("\n");
	}
	printf("                   END OF OUTPUT\n");
	return 0;
}


