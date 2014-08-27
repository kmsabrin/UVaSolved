#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 25

int a[MAX], b[MAX], p[MAX];

int lis( int n ) // n is number of elements in array a
{
	int i, j, k;
	int m;
	int len;
	
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
	
	return len + 1;
}

int new_input( char s[] )
{
	char t[10000], *p;
	
	strcpy( t, s );
	
	p = strtok( t, " " );
	
	if ( p = strtok( NULL, " " ) )
	{
		return 0;
	}
	
	return 1;
}

void main()
{
	char str[10000], *p;
	
	int orig[25];
	
	int i, j, f, k, n;
	
	//freopen( "a.in", "r", stdin );
	
	gets( str );
	
	n = atoi( str );
	
	while ( 1 )
	{
		gets( str );
		
		i = 0;
		
		p = strtok( str, " " );
		
		k = atoi( p );
		
		orig[i++] = k - 1;
		
		while ( p = strtok( NULL, " " ) )
		{
			k = atoi( p );
			
			orig[i++] = k - 1;
		}	
		
		/*for ( j = 0; j < i; ++j )
		{
			printf( "%d ", or[j] );
		}
		
		printf( "\n" );*/
		
		f = 0;
		
		while ( gets( str ) )
		{
			if ( new_input( str ) )
			{
				n = atoi( str );
				f = 1;
				break;
			}
			
			i = 0;
			
			p = strtok( str, " " );
			
			k = atoi( p );
			
			a[k - 1] = orig[i++];
			
			while ( p = strtok( NULL, " " ) )
			{
				k = atoi( p );
				
				a[k - 1] = orig[i++];
			}
			
			//puts( str );
			
			//printf( "n = %d\n", i );
			
			/*for ( j = 0; j < i; ++j )
			{
				printf( "%d ", a[j] );
			}
			
			printf( "\n" );*/
			
			printf( "%d\n", lis( n ) );			
		}
		
		if ( !f )
		{
			break;
		}
		
	}
}

