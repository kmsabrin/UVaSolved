From apache@acm.uva.es Wed Feb 23 16:41:15 2005
Received: from acm.localnet (web.localnet [192.168.10.200])
	by acm.uva.es (8.11.6/8.11.6) with ESMTP id j1NFfFl10664
	for <judge@juez.localnet>; Wed, 23 Feb 2005 16:41:15 +0100
Received: by acm.localnet (Postfix)
	id 0AAC7112EA; Wed, 23 Feb 2005 16:41:15 +0100 (CET)
Delivered-To: judge@acm.uva.es
Received: by acm.localnet (Postfix, from userid 81)
	id 07B9C112E9; Wed, 23 Feb 2005 16:41:15 +0100 (CET)
To: judge@acm.uva.es
Subject: Problem 10006
From: nobody@nobody.acm.uva.es
Reply-To: nobody@nobody.acm.uva.es
Message-Id: <20050223154115.07B9C112E9@acm.localnet>
Date: Wed, 23 Feb 2005 16:41:15 +0100 (CET)

/* @JUDGE_ID: 34556CP 10006 C++ "" */
/** Submited via Valladolid ACM Online Judge Submit page v6.00 **/
/** IP: 202.80.160.60 - CRC: 107BA414 **/
/** Date: 2005-02-23 16:41:14 +0100 **/

@BEGIN_OF_SOURCE_CODE
#include <stdio.h>
#include <string.h>

int main()
{
	long a[] = { 561, 1105, 1729, 2465, 2821, 6601, 8911,
		   10585, 15841, 29341, 41041, 46657, 52633,
		   62745, 63973 };

	long i, j;

	while ( scanf ( "%ld", &i ) && i )
	{
		for ( j = 0; j < 15; ++j )
			if ( a[j] == i )
			{
				printf( "The number %ld is a Carmichael number.\n", i );
				break;
			}
		if ( j == 15 )
			printf ( "%d is normal.\n", i );
	}

	return 0;
}
@END_OF_SOURCE_CODE
