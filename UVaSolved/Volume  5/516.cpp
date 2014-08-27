

/* @JUDGE_ID: 34556CP 516 C++ "" */
/** Submited via Valladolid ACM Online Judge Submit page v6.00 **/
/** IP: 202.22.204.119 - CRC: 529D43D8 **/
/** Date: 2004-09-30 15:37:51 +0200 **/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#include<conio.h>

#define limit  40000

int main()
{


	char str[1000], *q;
	int  p[limit];
	int r[limit];
	int i, j, k, a, x, y;
	double z;

	for(i = 0; i < limit; ++i) p[i] = 0;
	for(i = 2; i * i < limit; ++i)
		if(p[i] == 0)
			for( j = i * i; j < limit; j += i)
				p[j] = 1;


//	freopen("a.in", "r", stdin); clrscr();

	while(gets(str) && str[0] != 48)
	{
	memset(p, 0, limit);
	q = strtok(str, " ");
	x = atoi(q);
	q = strtok(NULL, " ");
	y = atoi(q);
	z = pow((double)x, double(y));
	while(q = strtok(NULL, " "))
	{
		x = atoi(q);
		q = strtok(NULL, " ");
		y = atoi(q);
		z *= pow((double)x, (double)y);
	}
	a = z - 1;
	for(i = 0; i < limit; ++i) r[i] = 0;

	for( i = 2; a != 1 && i < limit; ++i)
	{
		if(p[i] == 0)
		{
			while(a % i == 0)
			{
				r[i]++;
				a /= i;
			}
		}
	}

	for( i = limit - 1; i > 1; --i)
	{
		if(r[i])
		{
			printf("%d %d", i, r[i]);
			break;
		}
	}

	for ( --i; i > 1; --i )
	{
		if ( r[i] )
		{
			printf(" %d %d", i, r[i]);
		}
	}

	printf("\n");
	}
	return 0;
}





