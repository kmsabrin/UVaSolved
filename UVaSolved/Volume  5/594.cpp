From apache@acm.uva.es Thu Sep  2 16:44:49 2004
Received: from acm.localnet (web.localnet [192.168.10.200])
	by acm.uva.es (8.11.6/8.11.6) with ESMTP id i82EinW00564
	for <judge@juez.localnet>; Thu, 2 Sep 2004 16:44:49 +0200
Received: by acm.localnet (Postfix)
	id 57FD3FFDF; Thu,  2 Sep 2004 16:44:49 +0200 (CEST)
Delivered-To: judge@acm.uva.es
Received: by acm.localnet (Postfix, from userid 81)
	id 556AFFFDE; Thu,  2 Sep 2004 16:44:49 +0200 (CEST)
To: judge@acm.uva.es
Subject: Problem 594
From: nobody@nobody.acm.uva.es
Reply-To: nobody@nobody.acm.uva.es
Message-Id: <20040902144449.556AFFFDE@acm.localnet>
Date: Thu,  2 Sep 2004 16:44:49 +0200 (CEST)

/* @JUDGE_ID: 34556CP 594 C++ "" */
/** Submited via Valladolid ACM Online Judge Submit page v6.00 **/
/** IP: 202.22.204.88 - CRC: 4B759E37 **/
/** Date: 2004-09-02 16:44:49 +0200 **/

@BEGIN_OF_SOURCE_CODE
#include<stdio.h>

int main()
{
	long a, b, c;
	int bytes[32], res[32];
	int i, j;

	while(scanf("%ld", &a) != EOF)
	{
	c = a;
	for(i=0; i<32; ++i) bytes[i] = 0;


	if(a < 0)
	{
		b = -a;
		i = 0;
		while(a)
		{
			j = a % 2;
			bytes[i++] = j;
			a /= 2;
		}
		for(i=0; i<16; i++)
		{
			j = bytes[i];
			bytes[i] = bytes[31-i];
			bytes[31-i] = j;
		}

		for(i=0; i<32; i++)
		{
			if(bytes[i] == 0) bytes[i] = 1;
			else bytes[i] = 0;
		}
		j = 1;
		for(i=31; i>-1; i--)
		{
			if(bytes[i] == 0 && j == 1)  { bytes[i] = 1; j = 0; }
			if(bytes[i] == 1 && j == 0)  { bytes[i] = 1; j = 0; }
			if(bytes[i] == 0 && j == 0)  { bytes[i] = 0; j = 0; }
			if(bytes[i] == 1 && j == 1)  { bytes[i] = 0; j = 1; }
		}
	}

	else
	{
	i = 0;
	while(a)
	{
		j = a % 2;
		bytes[i++] = j;
		a /= 2;
	}

	for(i=0; i<16; i++)
	{
		j = bytes[i];
		bytes[i] = bytes[31-i];
		bytes[31-i] = j;
	}
	}

	for(i=0; i<32; ++i)
	{
	      if(i == 0) j = 24;
	      if(i == 8) j = 16;
	      if(i == 16) j = 8;
	      if(i == 24) j = 0;
	      res[j++] = bytes[i];
	}

//	for(i=0; i<32; i++) printf("%d",bytes[i]); printf("\n");
//	for(i=0; i<32; i++) printf("%d",res[i]); printf("\n");

	if(res[0] == 0)
	{
		for(i=1, b=0; i<32; ++i)
			b = b * 2 + res[i];
		printf("%ld converts to %ld\n", c, b);
	}
	else
	{
		for(i=0; i<32; i++)
		{
			if(res[i] == 0) res[i] = 1;
			else res[i] = 0;
		}
		j = 1;
		for(i=31; i>-1; i--)
		{
			if(res[i] == 0 && j == 1)  { res[i] = 1; j = 0; }
			if(res[i] == 1 && j == 0)  { res[i] = 1; j = 0; }
			if(res[i] == 0 && j == 0)  { res[i] = 0; j = 0; }
			if(res[i] == 1 && j == 1)  { res[i] = 0; j = 1; }
		}

		for(i=1, b=0; i<32; ++i)
			b = b * 2 + res[i];
		printf("%ld converts to -%ld\n", c, b);
	}
	}
	return 0;
}


@END_OF_SOURCE_CODE
