// MATH

#include<stdio.h>
#include<math.h>

int main(){
	double i,k;   unsigned long j;
	while(scanf("%lf",&k)&&k){
		j=sqrt(k);  i=sqrt(k);
		if((i-j)||j==1) printf("no\n");
		else    printf("yes\n");
	}
	return 0;
}
