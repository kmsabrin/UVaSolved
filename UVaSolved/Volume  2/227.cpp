

/* @JUDGE_ID: 34556CP 227 C++ "" */
/** Submited via Valladolid ACM Online Judge Submit page v6.00 **/
/** IP: 172.16.27.248 - CRC: AC19F9C2 **/
/** Date: 2004-03-23 04:47:57 +0100 **/


#include<stdio.h>
#include<string.h>

int main()
{
	char a[26], b[100], c, d;
	int i, j, k, e, f, off, p=1, r, B = 0;
	off = 1;
	while(1)
	{
	for(i=1; i<=25; i+=5)
	{
		gets(b);
		if(b[0] == 'Z') { off=0; break; }
		for(j=i,k=0; b[k]; j++,k++)
		{
			a[j] = b[k];
			if(a[j] == 32 || a[j] == ' ')
				e = j;
		}
	}
	if(off == 0) break;

	if ( B )
	{
		printf( "\n" );
	}

	B = 1;

	f = 1;
	while(1)
	{
		gets(b);
		r = strlen(b)-1;
		for(i=0; b[i]; i++)
		{
			c = b[i];
			if(c == 'A')
			{
				if(e>=1 && e<=5) { f = 0; break; }
				else { d = a[e-5]; a[e] = d; a[e-5] = ' '; e = e - 5; }
			}
			else if(c == 'B')
			{
				if(e>=21 && e<=25) { f = 0; break; }
				else { d = a[e+5]; a[e] = d; a[e+5] = ' '; e = e + 5; }
			}
			else if(c == 'R')
			{
				if(!(e%5)) { f = 0; break; }
				else { d = a[e+1]; a[e] = d; a[e+1] = ' '; e = e + 1; }
			}
			else if(c == 'L')
			{
				if(!((e-1)%5) || e==1) { f = 0; break; }
				else { d = a[e-1]; a[e] = d; a[e-1] = ' '; e = e - 1; }
			}
		}
		if(b[r] == '0') break;
	}
	printf("Puzzle #%d:\n",p);
	p++;
	if(f)
	{
		for(i=1; i<=25; i++)
		{
			printf("%c",a[i]);
			if(i % 5) printf(" ");
			if(!(i%5)) printf("\n");
		}
	}
	else
		printf("This puzzle has no final configuration.\n");
	}
	return 0;
}





