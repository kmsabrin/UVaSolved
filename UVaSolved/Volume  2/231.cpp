

/* @JUDGE_ID: 34556CP 231 C++ "" */
/** Submited via Valladolid ACM Online Judge Submit page v6.00 **/
/** IP: 202.22.204.106 - CRC: 2802ADCC **/
/** Date: 2004-09-19 03:41:04 +0200 **/


#include<stdio.h>

#define limit 100000

int main()
{
	int height[limit], length[limit];
	int m, n, max, i, j, c = 1, B = 0;
//	freopen("a.in","r",stdin);
	while(scanf("%d", &m) && m != -1)
	{
		if ( B )
		{
			printf( "\n" );
		}

		B = 1;

		n = 0;
		height[n] = m; length[n] = 1; ++n;
		while(scanf("%d", &m) && m != -1)
		{
			height[n] = m;
			length[n] = 1;
			++n;
		}

		for(i = 0; i < n - 1; ++i)
			for(j = i + 1; j < n; ++j)
				if(height[i] > height[j])
					if(length[i] + 1 > length[j])
						length[j] = length[i] + 1;

		for(i = max = 0; i < n; i++)
			if(length[i] > max) max = length[i];

		printf("Test #%d:\n", c++);
		printf("  maximum possible interceptions: %d\n", max);
	}
	return 0;
}

