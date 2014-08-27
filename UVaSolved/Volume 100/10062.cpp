

/* @JUDGE_ID: 34556CP 10062 C++ "" */
/** Submited via Valladolid ACM Online Judge Submit page v6.00 **/
/** IP: 202.22.204.94 - CRC: 8FD62FD9 **/
/** Date: 2004-03-11 04:53:04 +0100 **/


#include<stdio.h>

int main()
{
	char a[2000];
	int i,j,k,min,c,d[150], B = 0;

	while(gets(a))
	{
		if ( B )
		{
			printf("\n");
		}

		B = 1;
		for(i=0; i<150; i++)
			d[i] = 0;

		for(i=0; a[i]; i++)
			d[a[i]]++;

		while(1)
		{
			min=1010;
			for(i=32; i<128; i++)
				if(d[i]<min && d[i]>0 )
					min=d[i];

			if(min == 1010)
				break;
			else
			{
				for(i=127; i>=32; i--)
					if(d[i] == min)
					{
						printf("%d %d\n",i,min);
						d[i]=1020;
					}
			}

		}

	}
	return 0;
}

