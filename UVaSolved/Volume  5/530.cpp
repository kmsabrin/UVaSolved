From apache@acm.uva.es Sat Sep 27 19:34:15 2003
Received: from acm.localnet (web.localnet [192.168.10.200])
	by acm.uva.es (8.11.6/8.11.6) with ESMTP id h8RHYFV30047
	for <judge@juez.localnet>; Sat, 27 Sep 2003 19:34:15 +0200
Received: by acm.localnet (Postfix)
	id 9A1D7100D2; Sat, 27 Sep 2003 19:34:16 +0200 (CEST)
Delivered-To: judge@acm.uva.es
Received: by acm.localnet (Postfix, from userid 81)
	id 97EA3100D3; Sat, 27 Sep 2003 19:34:16 +0200 (CEST)
To: judge@acm.uva.es
Subject: Problem 530
From: nobody@nobody.acm.uva.es
Reply-To: nobody@nobody.acm.uva.es
Message-Id: <20030927173416.97EA3100D3@acm.localnet>
Date: Sat, 27 Sep 2003 19:34:16 +0200 (CEST)

/* @JUDGE_ID: 34556CP 530 C++ "" */
/** Submited via Valladolid ACM Online Judge Submit page v6.00 **/
/** IP: 202.22.204.112 - CRC: 13FE01E3 **/
/** Date: 2003-09-27 19:34:16 +0200 **/

@BEGIN_OF_SOURCE_CODE
#include<stdio.h>
int main(){
	double i,j,k,n,r,p;
	while(scanf("%lf %lf",&n,&r)&&n||r){
		j=1;  k=n-r;   p=r;
		if(r>=n-r){
			for(i=r+1;i<=n;i++){
				j*=i;
				if(k>1) {  j/=k; k--; }
				}
			}
		else{
			for(i=k+1;i<=n;i++){
				j*=i;
				if(r>1) {  j/=r; r--; }
				}
			}
		printf("%.0lf\n",j);
		}
	return 0;
}





@END_OF_SOURCE_CODE
