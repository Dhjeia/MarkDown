#include<stdio.h>
#include<string.h>
 
#define N 100 
#define M 100
 
int D[M][N];
 
int min(int a,int b,int c){
	if(a<b && a<c) return a;
	if(b<a && b<c) return b;
	return c;
}
 
int ASM(char P[],int m,char T[],int n){
	int i,j;
	for(j=1;j<=n;j++){
		D[0][j]=j;
	}
	for(i=0;i<=m;i++){
		D[i][0]=i;
	}
 
	for(j=1;j<=n;j++){
		for(i=1;i<=m;i++){
			if(P[i-1]==T[j-1]){
				D[i][j]=min(D[i-1][j-1],D[i-1][j]+1,D[i][j-1]+1);
			}else{
				D[i][j]=min(D[i-1][j-1]+1,D[i-1][j]+1,D[i][j-1]+1);
			}
		}
	}
	return D[m][n];
}
 
int main(){
 
	char P[]="hsppay";
	char T[]="happy";
	printf("%d\n",ASM(P,strlen(P),T,strlen(T)));
	return 0;
}