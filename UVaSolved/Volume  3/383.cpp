

/* @JUDGE_ID: 34556CP 383 C++ "" */
/** Submited via Valladolid ACM Online Judge Submit page v6.00 **/
/** IP: 202.22.204.71 - CRC: 4DCA6229 **/
/** Date: 2004-05-05 12:01:37 +0200 **/

#include<stdio.h>
#include<string.h>
//#include<conio.h>

int route[31][31];
int dest, leg, warehouse, min;
int used[31];

int call(int x);

int main()
{
	int m, n, p, cost, ans, set, tcase;
	char house[31][31], a[3], b[3];
	int i, j, k, x, y;
//	clrscr();
//	freopen("always.in","r",stdin);
	printf("SHIPPING ROUTES OUTPUT\n");
	set = 1;
	scanf("%d", &tcase);
	while(tcase)
	{
	scanf("%d %d %d", &m, &n, &p);
	printf("\nDATA SET  %d\n\n",set++);
	warehouse = m;
	for(i=0; i<31; i++)
	{
		used[i] = 0;
		for(j=0; j<31; j++)
			route[i][j] = 0;
	}
	for(i=0; i<m; i++)
		scanf("%s", house[i]);
	for(i=0; i<n; i++)
	{
		scanf("%s %s", a, b);
		for(j=0; j<m; j++)
		{
			if( ! strcmp( house[j], a ) )
				x = j;

			if( ! strcmp( house[j], b ) )
				y = j;
		}
		route[x][y] = route[y][x] = 1;
	}
	for(i=0; i<p; i++)
	{
		scanf("%d %s %s", &cost, a, b);
		for(j=0; j<m; j++)
		{
			if( ! strcmp( house[j], a ) )
				x = j;

			if( ! strcmp( house[j], b ) )
				y = j;
		}
		dest = y;
		leg = 0;
		min = 1000000;
		call(x);
		if(min == 1000000)
			printf("NO SHIPMENT POSSIBLE\n");
		else
		{
			ans = cost * min * 100;
			printf("$%d\n",ans);
		}

	}
	tcase--;
	}
	printf("\nEND OF OUTPUT\n");
	return 0;
}

int call(int x)
{
	int i, j, k;
	if(x == dest) { if(leg < min) min = leg; return 0; }
	for(i=0; i<warehouse; i++)
	{
		if(route[x][i] && !used[i])
		{
			leg++;
			used[i] = 1;
			call(i);
			leg--;
			used[i] = 0;
		}
	}
	return 0;
}


