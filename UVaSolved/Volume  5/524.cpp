Date: Tue,  6 Apr 2004 16:07:20 +0200 (CEST)

/* @JUDGE_ID: 34556CP 524 C++ "" */

#include<stdio.h>

// numbers are denoted as vertices

int  called[17];    // all vertices included in a path are 1, otherwise 0
int  path[16];	  // path traversed consisting of vertices
int  pos[17][17];   // 1 if sum is prime between vertices, 0 otherwise
int  count, n, f2;
int  prime[] = { 0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0 };

void init()
{
	int i;
	f2 = 1;
	prime[1] = 1;
	count = 0;
	for(i = 0; i < 17; i++)
		called[i] = 0;
}

int recursion(int from, int to)
{
	int i, f = 0, flg;

	// checking whether to + from = prime, if not go back
	if(prime[from + to] == 0)   return 0;

	// for the first call from main
	if(f2) { prime[1] = 0; f2 = 0; }

	// checking whether a vertex is included, if is go back
	if(called[to] == 1) return 0;

	// including a vertex and keeping track of the path
	called[to] = 1;
	f = 1;
	path[count++] = to;

	// checking whether all vertices are included
	for(i = flg = 1; i <= n; i++)
		if(called[i] == 0)
			flg = 0;
	// check for the last and first element
	if(flg)
		if(prime[path[0] + path[n-1]] == 0)
			flg = 0;
	if(flg)
	{
		// printing the path
		printf("%d", path[0]);
		for(i = 1; i < n; i++)
			printf(" %d",path[i]);
		printf("\n");

		// wiping the last vertex to track back
		path[--count] = '\0';
		called[to] = 0;
		return 0;
	}

	// calling all existing vertex
	// the current 'to' is the next 'from'
	for(i = 1; i <= n; i++)
		recursion(to, i);

	// wiping traversed path and included vertices to track back
	if(f == 1)
	{
		called[to] = 0;
		path[--count] = '\0';
	}

	return 0;
}

int main()
{
	int ca = 1, f = 0;
	while(scanf("%d", &n) != EOF)
	{
		if(f == 1) printf("\n");
		f = 1;
		printf("Case %d:\n",ca),
		init();
		recursion(0, 1);
		ca++;
	}
	return 0;
}


@END_OF_SOURCE_CODE
