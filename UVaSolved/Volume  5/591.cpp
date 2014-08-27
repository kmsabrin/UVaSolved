

/* @JUDGE_ID: 34556CP 591 C++ "" */
/** Submited via Valladolid ACM Online Judge Submit page v6.00 **/
/** IP: 172.16.5.55 - CRC: 109BA2A1 **/
/** Date: 2003-08-24 07:49:57 +0200 **/



#include<stdio.h>
int main(){
	int a,b[120],c,d,e,f,g=0;
	while(scanf("%d",&a)&&a){
		d=0;
		for(c=1;c<=a;c++){
			scanf("%d",&b[c]);
			d+=b[c];
		}
		e=d/a;
		f=0;
		for(c=1;c<=a;c++){
			if(e>=b[c]) f+=(e-b[c]);
		}
		g++;
		printf("Set #%d\nThe minimum number of moves is %d.\n\n",g,f);
	}
	return 0;
}




