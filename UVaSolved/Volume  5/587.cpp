From apache@acm.uva.es Wed Apr  7 05:31:46 2004
Received: from acm.localnet (web.localnet [192.168.10.200])
	by acm.uva.es (8.11.6/8.11.6) with ESMTP id i373VkW01344
	for <judge@juez.localnet>; Wed, 7 Apr 2004 05:31:46 +0200
Received: by acm.localnet (Postfix)
	id 1FCD610000; Wed,  7 Apr 2004 05:31:45 +0200 (CEST)
Delivered-To: judge@acm.uva.es
Received: by acm.localnet (Postfix, from userid 81)
	id 1D58AFFFC; Wed,  7 Apr 2004 05:31:45 +0200 (CEST)
To: judge@acm.uva.es
Subject: Problem 587
From: nobody@nobody.acm.uva.es
Reply-To: nobody@nobody.acm.uva.es
Message-Id: <20040407033145.1D58AFFFC@acm.localnet>
Date: Wed,  7 Apr 2004 05:31:45 +0200 (CEST)

/* @JUDGE_ID: 34556CP 587 C++ "" */
/** Submited via Valladolid ACM Online Judge Submit page v6.00 **/
/** IP: 202.22.204.100 - CRC: 55EEC949 **/
/** Date: 2004-04-07 05:31:45 +0200 **/

@BEGIN_OF_SOURCE_CODE
#include<math.h>
#include<stdio.h>
#include<string.h>

int main()
{
	char in[250], dir[5];
	double x, y, sq2;
	int i, j , k, map;
	sq2 = sqrt(2.00);
	map = 0;

	while(gets(in))
	{

	if(!strcmp(in,"END")) break;

	x = y = 0.000000000001;
	map++;
	for(i=0; in[i]; i++)
	{
		k = 0;
		while(in[i] > 47 && in[i] < 58)
		{
			k = (k * 10) + (in[i] - 48);
			i++;
		}

		j = 0;
		while(in[i] != ',' && in[i] != '.')
		{
			dir[j] = in[i];
			i++;
			j++;
		}
		dir[j] = '\0';

		if     (!strcmp(dir,"N"))
			y += k;
		else if(!strcmp(dir,"S"))
			y -= k;
		else if(!strcmp(dir,"E"))
			x += k;
		else if(!strcmp(dir,"W"))
			x -= k;
		else if(!strcmp(dir,"NE"))
		{
			x += k / sq2;
			y += k / sq2;
		}
		else if(!strcmp(dir,"NW"))
		{
			x -= k / sq2;
			y += k / sq2;
		}
		else if(!strcmp(dir,"SE"))
		{
			x += k / sq2;
			y -= k / sq2;
		}
		else if(!strcmp(dir,"SW"))
		{
			x -= k / sq2;
			y -= k / sq2;
		}
	}
	printf("Map #%d\n",map);
	printf("The treasure is located at (%.3lf,%.3lf).\n",x,y);
	printf("The distance to the treasure is %.3lf.\n\n",sqrt(x*x+y*y));
	}
	return 0;
}
@END_OF_SOURCE_CODE
