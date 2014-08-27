// nlogn LIS
// problem 497

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 20000

int a[MAX], b[MAX], p[MAX];

void print_lis( int n )
{
	if ( n != -1 )
	{
		print_lis( p[n] );
		printf( "%d\n", a[n] );
	}	
}

void main()
{	
	int i, j, k, m, n;
	int len, tc;
	char str[20];
	
	//freopen( "a.in", "r", stdin );
	
	scanf( "%d\n", &tc );
	
	while ( tc-- )
	{
		
		i = 0;
		
		while ( gets( str ) && *str )
		{
			a[i++] = atoi( str );
		}
		
		n = i;
		
		
		memset( p, -1, sizeof( p ) );
		
		len = 0;
		b[0] = 0;
		
		for ( i = 1; i < n; ++i )
		{
			if ( a[i] > a[b[len]] )
			{
				p[i] = b[len];
				b[++len] = i;
				continue;
			}
			
			j = 0;
			k = len;
			
			while ( j < k ) 
			{
				m = ( j + k ) / 2;
				
				if ( a[b[m]] < a[i] ) 
				{
					j = m + 1; 
				}
				else 
				{
					k = m;
				}
			}
			
			if ( j > 0 ) 
			{
				p[i] = b[j - 1];
			}
			
			b[j] = i;			
		}
						
		printf( "Max hits: %d\n", len + 1 );
		
		print_lis( b[len] );
		
		if ( tc )
		{
			printf( "\n" );
		}
	}
}
