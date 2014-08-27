From apache@acm.uva.es Mon Mar  8 14:36:55 2004
Received: from acm.localnet (web.localnet [192.168.10.200])
	by acm.uva.es (8.11.6/8.11.6) with ESMTP id i28DatW24522
	for <judge@juez.localnet>; Mon, 8 Mar 2004 14:36:55 +0100
Received: by acm.localnet (Postfix)
	id E0120FFF7; Mon,  8 Mar 2004 14:36:55 +0100 (CET)
Delivered-To: judge@acm.uva.es
Received: by acm.localnet (Postfix, from userid 81)
	id DE0B8FF80; Mon,  8 Mar 2004 14:36:55 +0100 (CET)
To: judge@acm.uva.es
Subject: Problem 573
From: nobody@nobody.acm.uva.es
Reply-To: nobody@nobody.acm.uva.es
Message-Id: <20040308133655.DE0B8FF80@acm.localnet>
Date: Mon,  8 Mar 2004 14:36:55 +0100 (CET)

/* @JUDGE_ID: 34556CP 573 C++ "" */
/** Submited via Valladolid ACM Online Judge Submit page v6.00 **/
/** IP: 202.22.204.94 - CRC: 38EAB4B3 **/
/** Date: 2004-03-08 14:36:55 +0100 **/

@BEGIN_OF_SOURCE_CODE
#include<stdio.h>
int main()
{
	int h, u, d, f, day, fc;
	float fl, ch, tmp;
	while(scanf("%d %d %d %d" ,&h, &u, &d, &f) && h)
	{
		fl = (f * u) / 100.0;
		day = fc = ch = 0;
		while(1)
		{
			day++;
			tmp = u - fl*fc;
			if(tmp < 0) tmp = 0;
			ch += tmp;
			if(ch > h)
			{
				printf("success on day %d\n", day);
				break;
			}
			ch -= d;
			if(ch < 0)
			{
				printf("failure on day %d\n", day);
				break;
			}
			fc++;
		}
	}
	return 0;
}
@END_OF_SOURCE_CODE
