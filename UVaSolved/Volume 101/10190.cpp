From apache@acm.uva.es Fri Mar 12 11:06:00 2004
Received: from acm.localnet (web.localnet [192.168.10.200])
	by acm.uva.es (8.11.6/8.11.6) with ESMTP id i2CA5xW09286
	for <judge@juez.localnet>; Fri, 12 Mar 2004 11:06:00 +0100
Received: by acm.localnet (Postfix)
	id DE9CE1015A; Fri, 12 Mar 2004 11:05:59 +0100 (CET)
Delivered-To: judge@acm.uva.es
Received: by acm.localnet (Postfix, from userid 81)
	id DD245FFEF; Fri, 12 Mar 2004 11:05:59 +0100 (CET)
To: judge@acm.uva.es
Subject: Problem 10190
From: nobody@nobody.acm.uva.es
Reply-To: nobody@nobody.acm.uva.es
Message-Id: <20040312100559.DD245FFEF@acm.localnet>
Date: Fri, 12 Mar 2004 11:05:59 +0100 (CET)

/* @JUDGE_ID: 34556CP 10190 C++ "" */
/** Submited via Valladolid ACM Online Judge Submit page v6.00 **/
/** IP: 202.22.204.66 - CRC: A8986AA0 **/
/** Date: 2004-03-12 11:05:59 +0100 **/

@BEGIN_OF_SOURCE_CODE
#include<stdio.h>

int main()
{
	long a, b, c, i, j, k, f, r[32];

	while(scanf("%ld %ld",&a, &b) != EOF){
	if(a==0 || b==0 || (a != 1 && b==1)) { printf("Boring!\n"); continue; }

	//if(a==1 && b==1)
	//	printf("1\n");

	if(((a%2) && (b%2)) || (!(a%2) && !(b%2)))
	{
		f = 1;

		j = 1;
		for(i=0; j<a; i++)
		{
			j *= b;
			r[i] = j;
			if(a % j)  { f=0; break; }
			if(a == j) { f=2; break; }

		}

		if(f==0 || f==1) { printf("Boring!\n"); continue; }

		for(  ; i>-1; i--)
			printf("%ld ",r[i]);
		printf("1\n");
	}

	else
		printf("Boring!\n");
	}
	return 0;
}

@END_OF_SOURCE_CODE
