#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct 
{	
	int x, y;
} matrix[100];

struct 
{
	int x, y;
} stackmatrix[1000];

char paren[1000];

int s1len, s2len, mulcount;


int main()
{
	char tmp[1000], *ptr;
	int i, flg, p, q, r, n;

	//freopen( "a.in", "r", stdin );
	//freopen( "a.out", "w", stdout );

	scanf( "%d", &n );
	getchar();

	for ( i = 0; i < n; ++i )
	{
		gets( tmp );
		p = tmp[0]; 		
		ptr = strtok( tmp, " " );
		ptr = strtok( NULL, " " );
		q = atoi( ptr );
		ptr = strtok( NULL, " " );
		r = atoi( ptr );

		//printf( "%d %d %d\n", p, q, r );
	
		matrix[p].x = q; matrix[p].y = r;
	}
	
	while ( gets( tmp ) )
	{
		//printf( "expr = %s\n",tmp );

		mulcount = s1len = s2len = flg = 0;

		for ( i = 0; i < ( int )strlen( tmp ); ++i )
		{

			if ( tmp[i] == '(' )
			{
				++s1len;
			}
			else if ( tmp[i] == ')' )
			{			
				if ( stackmatrix[s2len - 1].x != stackmatrix[s2len - 2].y )
				{
					//printf( "%d %d\n", stackmatrix[s2len - 1].x, stackmatrix[s2len - 2].y );
					flg = 1;
					break;
				}

				mulcount += stackmatrix[s2len - 2].x * stackmatrix[s2len - 1].x * stackmatrix[s2len - 1].y;
														
				stackmatrix[s2len - 2].y = stackmatrix[s2len - 1].y;
				--s2len;

				--s1len;
			}
			else
			{
				stackmatrix[s2len].x = matrix[tmp[i]].x;
				stackmatrix[s2len].y = matrix[tmp[i]].y;
				//printf( "%d %d %d\n", s2len, stackmatrix[s2len].x, stackmatrix[s2len].y );
				++s2len;
			}

		}

		if ( flg )
		{
			printf( "error\n" );
		}
		else
		{ 
			printf( "%d\n", mulcount );
		}
	}

	return 0;

}


