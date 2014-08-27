From apache@acm.uva.es Thu Nov  4 19:28:07 2004
Received: from acm.localnet (web.localnet [192.168.10.200])
	by acm.uva.es (8.11.6/8.11.6) with ESMTP id iA4IS6d12138
	for <judge@juez.localnet>; Thu, 4 Nov 2004 19:28:06 +0100
Received: by acm.localnet (Postfix)
	id 19AFA10433; Thu,  4 Nov 2004 19:28:06 +0100 (CET)
Delivered-To: judge@acm.uva.es
Received: by acm.localnet (Postfix, from userid 81)
	id 1794FFF2B; Thu,  4 Nov 2004 19:28:06 +0100 (CET)
To: judge@acm.uva.es
Subject: Problem 10101
From: nobody@nobody.acm.uva.es
Reply-To: nobody@nobody.acm.uva.es
Message-Id: <20041104182806.1794FFF2B@acm.localnet>
Date: Thu,  4 Nov 2004 19:28:06 +0100 (CET)

/* @JUDGE_ID: 34556CP 10101 C++ "Submitted by Cd-Man's automatic submission tool ver 0.9" */
/** Submited via Valladolid ACM Online Judge Submit page v6.00 **/
/** IP: 202.80.160.48 - CRC: 1A7FE4DE **/
/** Date: 2004-11-04 19:28:06 +0100 **/

@BEGIN_OF_SOURCE_CODE
#include<stdio.h>
//#include<conio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	char str[200], tmp[200], c;
	char name[][6] = { "", "shata", "hajar", "lakh",
			   "kuti", "shata", "hajar", "lakh", "kuti" };
	int d[] = { 2, 1, 2, 2, 2, 1, 2, 2, 1 };
	int n, num[10], i, j, k, t, f;
//	freopen("a.in","r", stdin);
//	clrscr();

	t = 1;
	while ( gets( str ) )
	{
	n = strlen(str) - 1;

	j = 0;
	while( 1 )
	{
		if ( n < 0 || j > 8 ) break;
		for ( i = d[j], k = 0; i && n >= 0; --i )
			tmp[k++] = str[n--];
		if ( k == 2 )
		{ c = tmp[0], tmp[0] = tmp[1], tmp[1] = c; }
		tmp[k] = 0;
		num[j] = atoi ( tmp );
		++j;
	}
	printf( "%4d.", t++ );

	if ( j == 1 && num[0] == 0 )
	{
		printf( " %d\n", num[0] );
		continue;
	}


	for ( i = j - 1, f = 0; i > 0; --i )
	{
		if ( num[i] )
		{
			printf( " %d %s", num[i], name[i] );
			f = 1;
		}
		else if ( i == 4 && f )
			printf( " %s", name[4] );
	}
	if ( num[i] )
		printf( " %d", num[0] );
	printf("\n");
	}
	return 0;
}
@END_OF_SOURCE_CODE
