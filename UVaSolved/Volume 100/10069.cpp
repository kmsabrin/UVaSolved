#include <stdio.h>
#include <string.h>

#define MAXDIGIT 100 + 2

struct
{
	char sum[MAXDIGIT + 2];
} seq[10000 + 2];


void add( char a[], char b[], char c[] ) // c = a + b
{
	char x[MAXDIGIT], y[MAXDIGIT], z[MAXDIGIT];
	int sum, carry;
	int i, j;
	
	memset( x, -1, sizeof( x ) );
	memset( y, -1, sizeof( y ) );
	memset( z, -1, sizeof( z ) );
	
	for ( i = strlen( a ) - 1, j = 0; i > -1; --i, ++j )
	{
		x[j] = a[i];
	}
	
	for ( i = strlen( b ) - 1, j = 0; i > -1; --i, ++j )
	{
		y[j] = b[i];
	}
	
	i = carry = 0;
	
	while ( 1 )
	{
		if ( x[i] == -1 && y[i] == -1 )
		{
			break;
		}
		
		sum = carry;
		
		if ( x[i] != -1 )
		{
			sum += x[i] - 48;
		}
		
		if ( y[i] != -1 )
		{
			sum += y[i] - 48;
		}
		
		z[i] = ( sum % 10 ) + 48;
		carry = sum / 10;
		
		++i;
	}
	
	if ( carry )
	{
		z[i] = carry + 48;
		++i;
	}
	
	for ( --i, j = 0; i > -1; --i, ++j )
	{
		c[j] = z[i];
	}
	
	c[j] = 0;
}

void main()
{
	char p[10000 + 2], q[100 + 2], pre[MAXDIGIT + 2], tmp[MAXDIGIT + 2];
	int len_p, len_q;
	int i, j;
	int tc;
	
	//freopen( "a.in", "r",stdin );
	
	scanf( "%d", &tc );
	
	while ( tc-- )
	{
		
		scanf( "%s %s", p, q );
		
		len_p = strlen( p );
		len_q = strlen( q );
												
		for ( i = 1; i <= len_q; ++i )
		{							
			strcpy( seq[0].sum, "0" );
			strcpy( pre, "0" );
			
			for ( j = 1; j <= len_p; ++j )
			{
				if ( q[i - 1] == p[j - 1] )
				{				
					if ( i == 1 )
					{
						strcpy( pre, seq[j].sum );						
						add( seq[j - 1].sum, "1", seq[j].sum );
					}
					else
					{
						strcpy( tmp, seq[j].sum );						
						add( pre, seq[j - 1].sum, seq[j].sum );
						strcpy( pre, tmp );						
					}
				}
				else
				{
					strcpy( pre, seq[j].sum );
					strcpy( seq[j].sum, seq[j - 1].sum );									
				}								
			}														
		}
		
		puts( seq[len_p].sum );
	}
}