#include <stdio.h> 
#include <string.h>

#define MAX 301
#define INF 0x7FFFFFFF

int N,T1,T2; 
int A[MAX]; 
int B[31][MAX];
int C[31][MAX]; 
int D[31][MAX]; 
int R[31][MAX]; 
int Res[31]; 

void Solve() 
{ 
	int s, k, p, i, j;
				
	s = 0;

	for ( i = 1; i <= N; ++i )  
	{ 			
		for( j = 0; j <= T1; ++j ) 
		{
			D[i][j] = INF; 
			
			if ( j <= A[i] )
			{
				k = j;
			}
			else
			{
				k = A[i];
			}

			for( ; j - k <= s && k > -1; --k ) 
			{
				if( D[i][j] > D[i - 1][j - k] + B[i][k] + C[i][A[i] - k] ) 
				{ 
					D[i][j] = D[i - 1][j - k] + B[i][k] + C[i][A[i] - k]; 
					R[i][j] = k;
				}
			}				
		} 
				
		s += A[i];
	} 
	
	printf( "%d\n", D[N][T1] );
	
	p = T1; 
	
	for ( i = N; i >= 1; --i ) 
	{ 
		Res[i] = R[i][p]; 
		p = p - R[i][p]; 
	} 
	
	printf( "%d", Res[1] );

	for( i = 2; i <= N; ++i ) 
	{
		printf( " %d", Res[i] ); 
	}
	
	printf( "\n\n" );
} 

void main() 
{ 
	int i, j; 	

	//freopen( "a.in", "r", stdin );		
	
	while( 1 )
	{	
		memset( D, 0, sizeof( D ) );
		memset( B, 0, sizeof( B ) );
		memset( C, 0, sizeof( C ) );

		scanf( "%d %d", &T1, &T2 );
		
		if( T1 == 0 && T2 == 0 )
		{
			break;
		}
		
		scanf( "%d", &N );
		
		for( i = 1; i <= N; ++i ) 
		{ 
			scanf( "%d", &A[i] );
			
			for ( j = 1; j <= A[i]; ++j ) 
			{
				scanf( "%d", &B[i][j] );
			}
			
			for ( j = 1; j <= A[i]; ++j ) 
			{
				scanf( "%d", &C[i][j] );
			}
		} 
		
		Solve(); 	
	}
} 
