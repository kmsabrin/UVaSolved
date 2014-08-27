

/* @JUDGE_ID: 34556CP 406 C++ "" */
/** Submited via Valladolid ACM Online Judge Submit page v6.00 **/
/** IP: 202.22.204.49 - CRC: A1D7F68B **/
/** Date: 2003-09-04 16:03:04 +0200 **/


#include<stdio.h>

int main(){
	int a,b,c[180],d,i,j,k,r,p;
	
	r=1;
	for(i=1;i<=1000;i++){
		k=1;
		for(j=2;j<=i/2;j++){
			if(!(i%j)) { k=0; break; }
		}
		if(k) { c[r]=i; r++; }
	}
	
	while(scanf("%d %d",&a,&b)!=EOF){
		for(i=1;i<=169;i++){
			if(c[i]>a) break;
		}
		p=i-1;
		
		
		if(p%2){
			if((2*b-1)>p){
				printf("%d %d:",a,b);
				for(k=1;k<=p;k++)
					printf(" %d",c[k]);
				printf("\n\n");
			}
			
			else{
				r=(b*2-2)/2;
				d=(p+2)/2;
				printf("%d %d:",a,b);
				for(i=d-r;i<=d+r;i++)
					printf(" %d",c[i]);
				printf("\n\n");
			}
		}
		else {
			if((2*b)>p){
				printf("%d %d:",a,b);
				for(k=1;k<=p;k++)
					printf(" %d",c[k]);
				printf("\n\n");
			}
			else{
				r=b*2;
				k=(p-(b*2))/2;
				printf("%d %d:",a,b);
				for(i=k+1;i<=k+r;i++)
					printf(" %d",c[i]);
				printf("\n\n");
			}
		}
	}
	return 0;
}

