// LONGEST INCREASING SUBSEQUENCE

#include <stdio.h>
#include <stdlib.h>

int pred[1001], length[1001];

struct ele {
	int wt, iq, nm;
} e[1001];

int comp( const void *i, const void *j )
{
	struct ele *p = ( struct ele * ) i;
	struct ele *q = ( struct ele * ) j;
	
	if ( p->wt != q->wt )
	{
		return p->wt - q->wt;
	}
	else
	{
		return p->iq - q->iq;
	}
}

void print_lis( int index )
{
	if ( index != -1 )
	{
		print_lis( pred[index] );
		printf( "%d\n", e[index].nm );
	}
}

int main()
{
	int i, j, k;
	int max = -1, index;
	
	//freopen( "a.in", "r", stdin );
	
	i = 0;
	while ( scanf( "%d %d", &j, &k ) != EOF )
	{
		e[i].wt = j;
		e[i].iq = k;
		e[i].nm = ++i;
	}
	
	k = i;
	
	qsort( e, k, sizeof( e[0] ), comp );
	
	for( i = 0; i < k; ++i )
	{
		length[i] = 1;
		pred[i] = -1;
	}
	
	for ( i = 0; i < k - 1; ++i )
	{
		for ( j = i + 1; j < k; ++j )
		{
			if (  e[j].iq < e[i].iq )
			{
				if ( length[i] + 1 > length[j] )
				{
					length[j] = length[i] + 1;
					pred[j] = i;
					
					if ( length[j] > max )
					{
						max = length[j];
						index = j;
					}
				}
			}
		}
	}
	
	printf( "%d\n", max );
	
	print_lis( index );
	
	return 0;
}




