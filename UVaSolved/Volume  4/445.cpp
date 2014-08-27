
/* @JUDGE_ID: 34556CP 445 C++ "" */
/** Submited via Valladolid ACM Online Judge Submit page v6.00 **/
/** IP: 202.22.204.100 - CRC: E376CDC3 **/
/** Date: 2004-04-20 12:48:57 +0200 **/


#include<stdio.h>
//#include<conio.h>

int main()
{
	char a[1000];
	int i, j, n, f=1, flg=0, nf;
	//	clrscr();
	//	freopen("always.in","r",stdin);
	while(f)
	{
		if(flg == 1) printf("\n");
		flg = 1;
		nf = 0;
		while(1)
		{
			if(!gets(a)) { f=0; break; }
			if(!(*a)) break;
			if(nf == 1) printf("\n");
			nf = 1;
			n = 0;
			for(i=0; a[i]; i++)
			{
				if(a[i] > 47 && a[i] < 58)
					n += a[i] - 48;
				else if(a[i] == '!')
					printf("\n");
				else if(a[i] == 'b')
				{
					while(n)
					{
						printf(" ");
						n--;
					}
				}
				else
				{
					while(n)
					{
						printf("%c",a[i]);
						n--;
					}
				}
			}
		}

		printf("\n");
	}
	return 0;
}

