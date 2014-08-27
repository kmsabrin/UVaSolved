

/* @JUDGE_ID: 34556CP 401 C "" */
/** Submited via Valladolid ACM Online Judge Submit page v6.00 **/
/** IP: 172.16.29.251 - CRC: 2570A2E8 **/
/** Date: 2003-12-01 05:32:42 +0100 **/


#include<stdio.h>
#include<string.h>

int main(){
	char a[1000],b[1000],c[1000];
	int i,j,k,d,f1,f2,f3;
	
	//freopen( "a.in", "r", stdin );
	
	while(gets(a)){
				
		f1=f2=f3=0;
		d=strlen(a)-1;
		
		for(i=0;a[i];i++)
			if(a[i]=='C'||a[i]=='D'||a[i]=='B'||a[i]=='F'||a[i]=='G'||a[i]=='K'||a[i]=='N'||a[i]=='P'||a[i]=='Q'||a[i]=='R'||a[i]=='4'||a[i]=='7')
				f3=1;
			
			for(i=d,j=0;i>=0;i--,j++)
			{
				b[j]=a[i];
				
				if(!f3){
					if(a[i]=='E')
						c[j]='3';
					else if(a[i]=='3')
						c[j]='E';
					else if(a[i]=='J')
						c[j]='L';
					else if(a[i]=='L')
						c[j]='J';
					else if(a[i]=='S')
						c[j]='2';
					else if(a[i]=='2')
						c[j]='S';
					else if(a[i]=='Z')
						c[j]='5';
					else if(a[i]=='5')
						c[j]='Z';
					else
						c[j]=a[i];
				}
			}
			
			b[j]=c[j]=0;
			
			//printf( "%s %s\n", b, c );

			printf( "%s", a );

			if(!strcmp(a,b))
				f1=1;
			if(!f3 && !strcmp(a,c))
				f2=1;
			
			if(!f1&&!f2){
				printf(" -- is not a palindrome.\n\n");
				continue;
			}
			
			if(f1&&f2){
				printf(" -- is a mirrored palindrome.\n\n");
				continue;
			}
			
			if(!f1&&f2){
				printf(" -- is a mirrored string.\n\n");
				continue;
			}
			
			if(f1&&!f2){      
				printf(" -- is a regular palindrome.\n\n");
				continue;
			}
									
	}
	return 0;
}


