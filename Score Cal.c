#include<stdio.h>

int *getData(){
	int i;
	static int a[10];
	for (i=0;i<5;i++)
	scanf("%d",&a[i]);
	return a;
}
float scoreCal( int a[]){
	int i,j,t;
	for (i=0;i<5;i++){
		for (j=0;j<4;j++){
			if (a[j]>a[i]){
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			} 
		}
	}
	float b=(a[1]+a[2]+a[3])/3;
	return b;
}
int main(){
	int *y=getData();
	float i=scoreCal(y);
	printf("%.2f",i);
}
