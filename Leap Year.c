#include<stdio.h>
short leapYear(int n){
	if (n%4==0) {
		if (n%100==0) {
			if (n%400==0) return 0;
			return 1;}
		}
		return 0;
	}
void main(){
	int n;
	scanf("%d",&n);
	if (leapYear(n)==0) printf("%d is a leap year",n);
	else printf("%d is not a leap year",n);
}
