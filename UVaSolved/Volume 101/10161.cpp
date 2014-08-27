// AD HOC


#include<stdio.h>
#include<math.h>

int main()
{
	unsigned long x, n, y;
	
	while(scanf("%lu", &x) && x)
	{
		
		n = ceil( sqrt( (double) x ) );
		y = n * n - (n - 1);
		if(x == y)
			printf("%lu %lu", n, n);
		else
		{
			if(n % 2)
			{
				if(x > y)
					printf("%lu %lu", n - (x - y), n);
				else
					printf("%lu %lu", n, n - (y - x));
			}
			else
			{
				if(x > y)
					printf("%lu %lu", n, n - (x - y));
				else
					printf("%lu %lu", n - (y - x), n);
			}
		}
		printf("\n");
		
	}
	
	return 0;
}

