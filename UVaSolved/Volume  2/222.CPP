#include <math.h>
#include <stdio.h>

#define INF 10e10
#define EPS 0.001

int main()
{
	double en;	// end distance
	double cp;	// capacity
	double ml;	// mile per gallon
	double cs;	// initial filling cost
	int nm;		// number of gas stations
	double ds[55];	// gas station's distance from start
	double pr[55];	// cost per gallon in a gas station
	double md;	// max travellable distance once filled
	double tmp1; 	// temporary holder variable
	double mc[55];	// minimum cost to reach and fill in a gas station
	int i;		// counter
	int j;		// counter
	int tc = 0;	// data set counter
	double hf;	// half capacity
	double tmp2;	// temporary variable
	double af[55];  // amount of fuel

	//freopen( "a.in", "r", stdin );

	while ( 1 )
	{
		scanf( "%lf", &en );

		if ( fabs( en + 1 ) < EPS )
		{
			break;
		}

		scanf( "%lf %lf %lf %d", &cp, &ml, &cs, &nm );

		for ( i = 1; i <= nm; ++i )
		{
			scanf( "%lf %lf", &ds[i], &pr[i] );
		}

		md = cp * ml;

		mc[0] = cs * 100.00;

		ds[0] = 0;

		ds[nm + 1] = en;

		hf = cp / 2;

		for ( i = 1; i <= nm + 1; ++i )
		{
			mc[i] = INF;

			for ( j = i; j >= 0; --j )
			{
				tmp1 = ds[i] - ds[j];

				if ( tmp1 > md )
				{
					break;
				}

				if ( j && af[j] > hf )
				{
					if ( af[j] * ml < ds[j + 1] - ds[j] )
					{
						;
					}
					else
					{
						continue;
					}
				}

				if ( i > nm )
				{
					tmp2 = mc[j];
				}
				else
				{
					tmp2 = mc[j] + ( ( tmp1 / ml ) * pr[i] )
					       + 200.00;
				}

				if ( tmp2 < mc[i] )
				{
					mc[i] = tmp2;
					af[i] = cp - tmp1 / ml;
				}
			}
		}

		printf( "Data Set #%d\n", ++tc );
		printf( "minimum cost = $%.2lf\n", mc[nm + 1] / 100.00 );
	}

	return 0;
}

