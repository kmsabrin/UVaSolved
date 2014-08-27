From apache@acm.uva.es Fri Dec 17 07:20:03 2004
Received: from acm.localnet (web.localnet [192.168.10.200])
	by acm.uva.es (8.11.6/8.11.6) with ESMTP id iBH6K2318551
	for <judge@juez.localnet>; Fri, 17 Dec 2004 07:20:02 +0100
Received: by acm.localnet (Postfix)
	id EBCAF110B3; Fri, 17 Dec 2004 07:20:02 +0100 (CET)
Delivered-To: judge@acm.uva.es
Received: by acm.localnet (Postfix, from userid 81)
	id E9C5B107C1; Fri, 17 Dec 2004 07:20:02 +0100 (CET)
To: judge@acm.uva.es
Subject: Problem 598
From: nobody@nobody.acm.uva.es
Reply-To: nobody@nobody.acm.uva.es
Message-Id: <20041217062002.E9C5B107C1@acm.localnet>
Date: Fri, 17 Dec 2004 07:20:02 +0100 (CET)

/* @JUDGE_ID: 34556CP 598 C++ "" */
/** Submited via Valladolid ACM Online Judge Submit page v6.00 **/
/** IP: 202.22.204.73 - CRC: F62FF6D0 **/
/** Date: 2004-12-17 07:20:02 +0100 **/

@BEGIN_OF_SOURCE_CODE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <conio.h>

#define max 1000

char str[max][50];
int  path[max];
int  n, r;

void call( int m, int p )
{
	int i;
	if ( p == r )
	{
		printf( "%s", str[path[0]] );
		for ( i = 1; i < p; ++i )
			printf( ", %s", str[path[i]] );
		printf( "\n" );
		return;
	}
	for ( i = m; i < n; ++i )
	{
		path[p] = i;
		call( i + 1, p + 1 );
	}

}

int main()
{
	int i, j, a, b, f, t;
	char s[50], *p;
//	clrscr();
//	freopen( "a.in", "r", stdin );
//	freopen( "a.out", "w", stdout );
	scanf( "%d", &t ); getchar(); getchar();
	while( t-- )
	{
	f = 0;
	gets( s );
	if( s[0] == '*' )
	{
		a = 1; f = 1;
	}
	else
	{
		p = strtok( s, " " );
		a = atoi( p );
		p = strtok( NULL, " " );
		if( p )
			b = atoi( p );
		else
			b = a;
	}


	i = 0;
	while( gets( s ) && *s )
		strcpy( str[i++], s );
	n = i;
	if( f ) b = n;

	for ( j = a; j <= b; ++j )
	{
		r = j;
		printf( "Size %d\n", r );
		call( 0, 0 );
		printf( "\n" );
	}
	if( t ) printf( "\n" );
	}
	return 0;
}

@END_OF_SOURCE_CODE
