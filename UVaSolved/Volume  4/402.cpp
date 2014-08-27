
/* @JUDGE_ID: 34556CP 402 C++ "" */
/** Submited via Valladolid ACM Online Judge Submit page v6.00 **/
/** IP: 172.16.27.251 - CRC: E871A1E5 **/
/** Date: 2004-04-01 07:08:54 +0200 **/


#include<stdio.h>

int main()
{
	int a[55], b[21];
	int i, j, k, x, y, r, p, l;

	k = 1;
	while(scanf("%d", &p) != EOF)
	{
	scanf("%d", &l);
	for(i=0; i<20; i++)
		scanf("%d", &b[i]);

	for(i=1; i<=p; i++)
		a[i] = 1;
	y = p;
	for(i=0; i<20; i++)
	{
		x = b[i];
		r = 0;
		for(j=1; j<=p; j++)
		{
			if(y == l) break;
			if(a[j] == 1)
				r++;
			if(r == x)
			{
				y--;
				a[j] = 0;
				r = 0;
			}
		}
		if(y == l) break;
	}

	printf("Selection #%d\n", k);
	k++;

	i=1;
	while(a[i] != 1)
		i++;
	printf("%d",i);
	i++;

	for( ; i<=p; i++)
		if(a[i] == 1)
			printf(" %d", i);
	printf("\n\n");
	}
	return 0;
}



