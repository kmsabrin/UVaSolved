From apache@acm.uva.es Thu Aug 28 02:51:08 2003
Received: from acm.localnet (web.localnet [192.168.10.200])
	by acm.uva.es (8.11.6/8.11.6) with ESMTP id h7S0p8V12164
	for <judge@juez.localnet>; Thu, 28 Aug 2003 02:51:08 +0200
Received: by acm.localnet (Postfix)
	id 10DDE1008A; Thu, 28 Aug 2003 02:51:08 +0200 (CEST)
Delivered-To: judge@acm.uva.es
Received: by acm.localnet (Postfix, from userid 81)
	id 0EE971008F; Thu, 28 Aug 2003 02:51:08 +0200 (CEST)
To: judge@acm.uva.es
Subject: Problem 575
From: nobody@nobody.acm.uva.es
Reply-To: nobody@nobody.acm.uva.es
Message-Id: <20030828005108.0EE971008F@acm.localnet>
Date: Thu, 28 Aug 2003 02:51:08 +0200 (CEST)

/* @JUDGE_ID: 34556CP 575 C++ "" */
/** Submited via Valladolid ACM Online Judge Submit page v6.00 **/
/** IP: 202.22.204.73 - CRC: E0BFCE74 **/
/** Date: 2003-08-28 02:51:08 +0200 **/

@BEGIN_OF_SOURCE_CODE
/* @judge_id:34620CA 575 C++ */

#include<stdio.h>
#include<string.h>
#include<math.h>

int main(){
   char c[1000];  long i,j;  double a,k;
   while(gets(c)){
	if((c[0]-'0')==0) break;
	j=strlen(c);
	k=1.0; a=0.0;
	for(i=j-1;i>=0;i--){
		a+=(c[i]-48)*(pow(2.0,k)-1);
		k++;
		}
	printf("%.0lf\n",a);
	}
}
@END_OF_SOURCE_CODE
