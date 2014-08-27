
/* @JUDGE_ID: 34556CP 352 C++ "" */
/** Submited via Valladolid ACM Online Judge Submit page v6.00 **/
/** IP: 202.22.204.90 - CRC: AB79289F **/
/** Date: 2004-04-06 16:06:59 +0200 **/

#include<stdio.h>

int r;
char in[31][31];

void rec(int x, int y)
{
	if(x>=0 && x<r && y>=0 && y<r && in[x][y] == '1')
	{
		in[x][y] = '0';
		rec(x, y+1);
		rec(x, y-1);
		rec(x+1, y-1);
		rec(x+1, y+1);
		rec(x+1, y);
		rec(x-1, y);
		rec(x-1, y+1);
		rec(x-1, y-1);
	}
}

int main()
{
	int i, j, k, x, y, c, f;
	//freopen("always.in","r",stdin);
	c = 1;
	f = 0;
	while(scanf("%d\n", &r) != EOF)
	{
		/*if(f) 
			printf("\n");
		f = 1;*/
		for(i=0; i<r; i++)
			gets(in[i]);
		for(i=k=0; i<r; i++)
			for(j=0; j<r; j++)
				if(in[i][j] == '1')
				{
					rec(i, j);
					k++;
				}
		printf("Image number %d contains %d war eagles.\n",c,k);
		c++;
	}
	return 0;
}

