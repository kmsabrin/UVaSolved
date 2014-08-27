

/* @JUDGE_ID: 34556CP 572 C++ "" */
/** Submited via Valladolid ACM Online Judge Submit page v6.00 **/
/** IP: 202.22.204.90 - CRC: 4FFD2493 **/
/** Date: 2004-04-06 16:07:29 +0200 **/


#include<stdio.h>

int r,c;
char in[101][101];

void rec(int x, int y)
{
	if(x>=0 && x<r && y>=0 && y<c && in[x][y] == '@')
	{
		in[x][y] = '*';
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
	int i,j,k,x,y,f;
	//freopen("always.in","r",stdin);
	
	while(scanf("%d %d\n", &r, &c) && r)
	{
		
		for(i=0; i<r; i++)
			gets(in[i]);

		for(i=k=0; i<r; i++)
			for(j=0; j<r; j++)
				if(in[i][j] == '@')
				{
					rec(i, j);
					k++;
				}
		printf("%d\n",k);
	}
	return 0;
}

