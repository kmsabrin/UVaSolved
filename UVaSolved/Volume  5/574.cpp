From apache@acm.uva.es Thu Dec 16 16:20:44 2004
Received: from acm.localnet (web.localnet [192.168.10.200])
	by acm.uva.es (8.11.6/8.11.6) with ESMTP id iBGFKi311400
	for <judge@juez.localnet>; Thu, 16 Dec 2004 16:20:44 +0100
Received: by acm.localnet (Postfix)
	id E7EBF1026F; Thu, 16 Dec 2004 16:20:43 +0100 (CET)
Delivered-To: judge@acm.uva.es
Received: by acm.localnet (Postfix, from userid 81)
	id E6856FF8E; Thu, 16 Dec 2004 16:20:43 +0100 (CET)
To: judge@acm.uva.es
Subject: Problem 574
From: nobody@nobody.acm.uva.es
Reply-To: nobody@nobody.acm.uva.es
Message-Id: <20041216152043.E6856FF8E@acm.localnet>
Date: Thu, 16 Dec 2004 16:20:43 +0100 (CET)

/* @JUDGE_ID: 34556CP 574 C++ "Submitted by Cd-Man's automatic submission tool ver 0.9" */
/** Submited via Valladolid ACM Online Judge Submit page v6.00 **/
/** IP: 202.22.204.108 - CRC: 664D846B **/
/** Date: 2004-12-16 16:20:43 +0100 **/

@BEGIN_OF_SOURCE_CODE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int total, num[15], store[15], max_ele, f;

int call( int sum, int index, int pos )
{
	int i;
	if( sum > total )
		return 0;
	if( sum == total )
	{
		printf( "%d", store[0] );
		for( i = 1; i < pos; ++i )
			printf( "+%d", store[i] );
		printf( "\n" );
		f  = 1;
		return 0;
	}
	if( index >= max_ele )
		return 0;

	store[pos] = num[index];
	call( sum + num[index], index + 1, pos + 1 );

	while( num[index] == num[index + 1] )
		++index;

	call( sum, index + 1, pos );

	return 0;
}

int main()
{
	int i;

while( 1 )
{
	scanf( "%d %d", &total, &max_ele );
	if( !total && !max_ele ) break;
	for( i = 0; i < max_ele; ++i )
		scanf( "%d", &num[i] );

	printf( "Sums of %d:\n", total );
	f = 0;
	call( 0, 0, 0 );

	if( !f ) printf( "NONE\n" );
}
	return 0;
}
@END_OF_SOURCE_CODE
