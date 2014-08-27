

/* @JUDGE_ID: 34556CP 469 C++ "" */
/** Submited via Valladolid ACM Online Judge Submit page v6.00 **/
/** IP: 202.22.204.70 - CRC: 47CE51F2 **/
/** Date: 2004-04-16 19:38:39 +0200 **/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int r, c, count;
char input[101][101];
char hold[101][101];

void rec(int x, int y)
{
	if(x>=0 && x<r && y>=0 && y<c && input[x][y] == 'W')
	{
		input[x][y] = 'L';
		count++;
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
	int i, j, k, x, y, f, n;
	char *p, str[105];
	//	clrscr();
	//	freopen("always.in","r",stdin);
	
	scanf("%d", &n);
	getchar();
	getchar();
	while(n--)
	{
		i=0;
		while(gets(str) && *str)
		{
			if(str[0] == 'L' || str[0] == 'W')
			{
				strcpy(input[i], str);
				strcpy(hold[i], str);
				i++;
			}
			else
			{
				r = i;
				c = strlen(input[0]);
				p = strtok(str, " ");
				x = atoi(p);
				p = strtok(NULL, " ");
				y = atoi(p);
				count = 0;
				rec(x-1, y-1);
				printf("%d\n",count);
				for(j=0; j<r; j++)
					strcpy(input[j], hold[j]);
			}
		}
		
		if (n)
		{
			printf( "\n" );
		}
	}
	return 0;
}

