#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct Point
{
	int x, y;
}	P[111], H[111];

int comp( const void *i, const void *j )
{
	struct Point* p1 = (struct Point*) i;
	
	struct Point* p2 = (struct Point*) j;
	
	if ( p1->x == p2->x )
	{
		return p1->y - p2->y;
	}
	else
	{
		return p1->x - p2->x;
	}
}

// isLeft(): tests if a point is Left|On|Right of an infinite line.
//    Input:  three points P0, P1, and P2
//    Return: >0 for P2 left of the line through P0 and P1
//            =0 for P2 on the line
//            <0 for P2 right of the line
//    See: the January 2001 Algorithm on Area of Triangles
inline int isLeft( Point P0, Point P1, Point P2 )
{
    return (P1.x - P0.x)*(P2.y - P0.y) - (P2.x - P0.x)*(P1.y - P0.y);
}

// chainHull_2D(): Andrew's monotone chain 2D convex hull algorithm
//     Input:  P[] = an array of 2D points 
//                   presorted by increasing x- and y-coordinates
//             n = the number of points in P[]
//     Output: H[] = an array of the convex hull vertices (max is n)
//     Return: the number of points in H[]
int chainHull_2D( Point* P, int n, Point* H )
{
    // the output array H[] will be used as the stack
    int    bot=0, top=(-1);  // indices for bottom and top of the stack
    int    i;                // array scan index
	
    // Get the indices of points with min x-coord and min|max y-coord
    int minmin = 0, minmax;
    int xmin = P[0].x;
    for (i=1; i<n; i++)
	{
        if (P[i].x != xmin) 
		{
			break;
		}
	}
	minmax = i-1;
	if (minmax == n-1)        // degenerate case: all x-coords == xmin
	{
		H[++top] = P[minmin];
		if (P[minmax].y != P[minmin].y) // a nontrivial segment
		{
			H[++top] = P[minmax];
		}
		H[++top] = P[minmin];           // add polygon endpoint
		return top+1;
	}
	
	// Get the indices of points with max x-coord and min|max y-coord
	int maxmin, maxmax = n-1;
	int xmax = P[n-1].x;
	for (i=n-2; i>=0; i--)
	{
		if (P[i].x != xmax) 
		{
			break;
		}
	}
	maxmin = i+1;
	
	// Compute the lower hull on the stack H
	H[++top] = P[minmin];      // push minmin point onto stack
	i = minmax;
	while (++i <= maxmin)
	{
		// the lower line joins P[minmin] with P[maxmin]
		if (isLeft( P[minmin], P[maxmin], P[i]) >= 0 && i < maxmin)
		{
			continue;          // ignore P[i] above or on the lower line
		}
		
		while (top > 0)        // there are at least 2 points on the stack
		{
			// test if P[i] is left of the line at the stack top
			if (isLeft( H[top-1], H[top], P[i]) > 0)
			{
				break;         // P[i] is a new hull vertex
			}
			else
			{
				top--;         // pop top point off stack
			}
		}
		H[++top] = P[i];       // push P[i] onto stack
	}
	
	// Next, compute the upper hull on the stack H above the bottom hull
	if (maxmax != maxmin)      // if distinct xmax points
	{
		H[++top] = P[maxmax];  // push maxmax point onto stack
	}
	bot = top;                 // the bottom point of the upper hull stack
	i = maxmin;
	while (--i >= minmax)
	{
		// the upper line joins P[maxmax] with P[minmax]
		if (isLeft( P[maxmax], P[minmax], P[i]) >= 0 && i > minmax)
		{
			continue;          // ignore P[i] below or on the upper line
		}
		
		while (top > bot)    // at least 2 points on the upper stack
		{
			// test if P[i] is left of the line at the stack top
			if (isLeft( H[top-1], H[top], P[i]) > 0)
			{
				break;         // P[i] is a new hull vertex
			}
			else
			{
				top--;         // pop top point off stack
			}
		}
		H[++top] = P[i];       // push P[i] onto stack
	}
	if (minmax != minmin)
	{
		H[++top] = P[minmin];  // push joining endpoint onto stack
	}
	
	return top+1;
}

// area2D_Polygon(): computes the area of a 2D polygon
//    Input:  int n = the number of vertices in the polygon
//            Point* V = an array of n+2 vertices 
//                       with V[n]=V[0] and V[n+1]=V[1]
//    Return: the (float) area of the polygon
double area2D_Polygon( int n, Point* V )
{
    double area = 0;
    int   i, j, k;     // indices

    for (i=1, j=2, k=0; i<=n; i++, j++, k++) {
        area += V[i].x * (V[j].y - V[k].y);
    }
    return area / 2.0;
}

double area( int n, Point* V )
{
    double area = 0;
    int i, j;     // indices

    for ( i = 0; i < n; ++i ) 
	{
		j = ( i + 1 ) % n;

        area += V[i].x * V[j].y - V[j].x * V[i].y;
    }
    return area / 2.0;
}

int main()
{
	int nPoints, top, i, kase = 0;
			
	//freopen( "c.in", "r", stdin );
		
	while ( scanf( "%d", &nPoints ) && nPoints )
	{						
		for ( i = 0; i < nPoints; ++i )
		{
			scanf( "%d %d", &P[i].x, &P[i].y );
		}

		P[nPoints] = P[0];

		P[nPoints + 1] = P[1];

		double A1 = area2D_Polygon( nPoints, P );
		
		qsort( P, nPoints, sizeof( P[0] ), comp );
		
		top = chainHull_2D( P, nPoints, H );

		H[top] = H[1];
		
		double A2 = area2D_Polygon( top - 1, H );
		
		printf( "Tile #%d\n", ++kase );
		
		printf( "Wasted Space = %.2lf %\n\n", ( ( A2 - fabs( A1 ) ) * 100.0 ) / A2 );		
	}
	
	return 0;
}
