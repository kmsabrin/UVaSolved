From apache@acm.uva.es Tue Apr  6 20:02:46 2004
Received: from acm.localnet (web.localnet [192.168.10.200])
	by acm.uva.es (8.11.6/8.11.6) with ESMTP id i36I2kW21484
	for <judge@juez.localnet>; Tue, 6 Apr 2004 20:02:46 +0200
Received: by acm.localnet (Postfix)
	id EC92510129; Tue,  6 Apr 2004 20:02:46 +0200 (CEST)
Delivered-To: judge@acm.uva.es
Received: by acm.localnet (Postfix, from userid 81)
	id EAF49100FD; Tue,  6 Apr 2004 20:02:46 +0200 (CEST)
To: judge@acm.uva.es
Subject: Problem 10189
From: nobody@nobody.acm.uva.es
Reply-To: nobody@nobody.acm.uva.es
Message-Id: <20040406180246.EAF49100FD@acm.localnet>
Date: Tue,  6 Apr 2004 20:02:46 +0200 (CEST)

/* @JUDGE_ID: 34556CP 10189 C++ "" */
/** Submited via Valladolid ACM Online Judge Submit page v6.00 **/
/** IP: 202.22.204.35 - CRC: F93A547 **/
/** Date: 2004-04-06 20:02:46 +0200 **/

@BEGIN_OF_SOURCE_CODE
#include<stdio.h>

char a[1001][111];
int n, m;

int check( int i, int j)
{
	if( i >= 0 && i < n && j >= 0 && j < m )
		return 1;
	return 0;
}

int mine( int i, int j)
{
	int mines;

	mines = 0;

	if( check( i, j + 1 ) )
		if( a[i][j + 1] == '*')
			mines++;
	if( check( i, j - 1) )
		if( a[i][j - 1] == '*')
			mines++;
	if( check( i - 1, j) )
		if( a[i - 1][j] == '*')
			mines++;
	if( check( i - 1, j - 1 ) )
		if( a[i - 1][j - 1] == '*')
			mines++;
	if( check( i - 1, j + 1) )
		if( a[i - 1][j + 1] == '*')
			mines++;
	if( check( i + 1, j) )
		if( a[i + 1][j] == '*')
			mines++;
	if( check( i + 1, j + 1 ) )
		if( a[i + 1][j + 1] == '*')
			mines++;
	if( check( i + 1, j - 1 ) )
		if( a[i + 1][j - 1] == '*')
			mines++;
	return mines;
}

int main()
{
	int i, j, k, num, f;

	num = 1, f = 0;
	//freopen("always.in", "r", stdin);
	while( scanf( "%d %d", &n, &m) && n && m )
	{
		getchar();
		if( f == 1 )	printf("\n\n");
		f = 1;

		for( i = 0; i < n; i++ )
			gets( a[i] );

		/* i IS ROW VALUE, j IS COLUMN VALUE */

		for( i = 0; i < n; i++)
			for( j = 0; j < m; j++)
				if( a[i][j] == '.')
				{
					k = mine( i, j );
					a[i][j] = k + 48;
					//printf("%d %d\n",i,j);
				}
		printf( "Field #%d:\n", num );
		num++;
		printf( "%s", a[0] );
		for( i = 1; i < n; i++)
			printf( "\n%s", a[i] );
	}
	return 0;
}
@END_OF_SOURCE_CODE
