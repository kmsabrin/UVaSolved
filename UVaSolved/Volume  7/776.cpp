

/* @JUDGE_ID: 34556CP 776 C++ "" */
/** Submited via Valladolid ACM Online Judge Submit page v6.00 **/
/** IP: 202.22.204.116 - CRC: B9A50C13 **/
/** Date: 2004-04-20 14:17:09 +0200 **/


#include<stdio.h>
#include<string.h>
//#include<conio.h>

char str[200][200];
int res[200][200];
char current;
int put;
int r,col;

int call(int i, int j)
{
	if(str[i][j] != current) return 0;
	if(i<0 || i>=r || j>=col || j<0) return 0;
	str[i][j] = '*';
	res[i][j] = put;
	call(i, j+1);
	call(i, j-1);
	call(i+1, j);
	call(i-1, j);
	call(i-1, j+1);
	call(i-1, j-1);
	call(i+1, j+1);
	call(i+1, j-1);
	return 0;
}

int numOfDigit( int n )
{
	int m = 0;

	while ( n )
	{
		n /= 10;
		++m;
	}

	return m;
}

int main()
{
	char c[200], *p;
	int i,j, k, f,n,m;
	//	clrscr();
	//freopen("a.in","r",stdin);
	while(gets(c))
	{
		
		for(i=0; i<200; i++)
			for(j=0; j<200; j++)
				res[i][j] = str[i][j] = '\0';
			
			i=0;
			j=0;
			p = strtok(c,  " ");
			str[i][j++] = *p;
			while(p = strtok(NULL,  " "))
				str[i][j++] = *p;
			i++;
			while(gets(c))
			{
				if(c[0] == '%') break;
				j=0;
				p = strtok(c,  " ");
				str[i][j++] = *p;
				while(p = strtok(NULL,  " "))
					str[i][j++] = *p;
				i++;
			}
			col = j;
			r = i;
			m = 1;
			
			for(i=0; i<r; i++)
				for(j=0; j<col; j++)
				{
					if(str[i][j] == '*') continue;
					put = m++;
					current = str[i][j];
					call(i, j);
				}

				int space[200];

				for ( i = 0; i < col; ++i )
				{
					int max = 0;

					for ( j = 0; j < r; ++j )
					{
						k = numOfDigit( res[j][i] );

						if ( k > max )
						{
							max = k;
						}
					}

					space[i] = max;
				}

				for(i=0; i<r; i++)
				{
					k = space[0] - numOfDigit( res[i][0] );
					
					while ( k-- )
					{
						printf( " " );
					}

					printf("%d",res[i][0]);
					
					for(j=1; j<col; j++)
					{
						k = space[j] - numOfDigit( res[i][j] );
					
						while ( k-- )
						{
							printf( " " );
						}
							
						printf(" %d",res[i][j]);
					}

					printf("\n");
				}

				printf("%\n");
	}
	return 0;
}



