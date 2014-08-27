

/* @JUDGE_ID: 34556CP 483 C "" */
/** Submited via Valladolid ACM Online Judge Submit page v6.00 **/
/** IP: 202.22.204.85 - CRC: BC1B81FC **/
/** Date: 2003-10-17 16:09:46 +0200 **/


#include<stdio.h>
#include<string.h>

void rev(char a[]){
	int i,j;
	char b;
	j=strlen(a);
	for(i=0;i<j/2;i++){
		b=a[i];
		a[i]=a[j-i-1];
		a[j-i-1]=b;
	}
}

int main(){
	char a[1000],b[30];
	int i,j,k, f;
	while(gets(a)){
		f = 1;
		for(k=0;k<30;k++) b[k]='\0';
		for(i=j=0;a[i];i++){
			if(a[i]!=' ')
				b[j++]=a[i];
			if(a[i]==' '){
				rev(b);
				if ( f )
				{
					printf("%s",b);
					f = 0;
				}
				else
				{
					printf(" %s",b);
				}
				for(k=0;k<30;k++) b[k]='\0';
				j=0;
			}
		}
		rev(b);
		if ( j )
		{
			if ( f )
			{
				printf("%s",b);
				f = 0;
			}
			else
			{
				printf(" %s",b);
			}
		}
		printf( "\n" );
	}
	return 0;
}

