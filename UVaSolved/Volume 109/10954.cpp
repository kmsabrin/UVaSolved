#include<stdio.h>

int n, a[5002];

int InsertHeap( int item )
{
	int i = ++n;

	while ( i > 1 && a[i / 2] > item )
	{
		a[i] = a[i / 2];
		i = i / 2;
	}

	a[i] = item;

	return 0;
}

int ExtractMin()
{
	int i = 2, j = a[1], k = a[n];

	--n;

	while ( i <= n )
	{
		if ( i < n && a[i] > a[i + 1] )
			i = i + 1;

		if ( k <= a[i] )
			break;

		a[i / 2] = a[i];
		i = 2 * i;
	}

	a[i / 2] = k;

	return j;
}

int main()
{
	int i, j, N;	

	long long sum;

	while (scanf( "%d", &N ) && N )
	{

		n = 0;
		for ( i = 0; i < N; ++i )
		{
			scanf( "%d", &j );
			InsertHeap( j );
		}

		sum = 0;

		while( 1 )
		{
			j = ExtractMin() + ExtractMin();			
			sum += j;

			if ( n == 0 )
				break;

			InsertHeap( j );
		}
		
		printf( "%lld\n", sum );
	}

	return 0;
}