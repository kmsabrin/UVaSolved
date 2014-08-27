#include <stdio.h>
#include <stdlib.h>

int nTeam, max, nMan, cnt, val, kase, used[15], a[15];

int comp( const void *i, const void *j )
{
	return *(int *)i - *( int *)j;
}

int call( int s )
{
	if ( cnt == 3 )
	{
		if ( val >= 20 )
		{
			++nTeam;
			
			if ( nTeam >  max )
			{
				max = nTeam;
			}
			
			if ( nTeam + ( nMan - 3 * nTeam ) / 3 > max )
			{								
				int tmp = val;
				
				cnt = val = 0;
				
				call( -1 );
				
				cnt = 3;
				
				val = tmp;
			}
			
			--nTeam;
			
		}
		
		return 0;		
	}
	
	for ( int i = s + 1; i < nMan; ++i )
	{
		if ( !used[i] )
		{
			val += a[i];
			
			used[i] = 1;
			
			++cnt;
			
			call( i );
			
			val -= a[i];
			
			used[i] = 0;
			
			--cnt;
		}
	}
	
	return 0;
}

int main()
{
	//freopen( "a.in", "r", stdin );
	
	while ( scanf( "%d", &nMan ) && nMan )
	{		
		for ( int i = 0; i < nMan; ++i )
		{
			scanf( "%d", &a[i] );
			
			used[i] = 0;
		}
		
		qsort( a, nMan, sizeof( a[0] ), comp );
		
		cnt = val = nTeam = max = 0;
		
		call( -1 );
		
		printf( "Case %d: %d\n", ++kase, max );
	}
	
	return 0;
}

