// MATH

#include<stdio.h>
#include<stdlib.h>

int comp(const void *i, const void *j){
	return *(int *)i - *(int *)j;
}

int main(){
	long i,a[10000];
	a[0]=0;
	i=0;
	while(scanf("%ld",&a[i])!=EOF){
		i++;
		qsort(a, i, sizeof(long), comp);
		if(i%2)	printf("%d\n",a[(i-1)/2]);
		else	printf("%d\n",(a[i/2]+a[(i-2)/2])/2);
	}
	return 0;
}
