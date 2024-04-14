#include<stdio.h>
#include<math.h>
float giaithua(int n){
    double t=1;
    int i;
    for (i=n;i>1;i--)
    t=t*i;
    return t;
}
float somu(int m,int n){
    int i;
    double t=1;
    for (i=0;i<n;i++)
    t=t*m;
    return t;
}
void tinhSIN(){
	int i,y;
	float t1,t2,e,x,t,h;
	scanf("%f%f",&x,&e);
	i=1,y=3;
	t2=x;
	h=x-(x*x*x)/(2*3);
	if (h<0) h=-h;
    while (h>e){
		t=somu(-1,i)*somu(x,y)/giaithua(y);
		t2=t2+t;
		y=y+2;
		i++;
		if (t>0) h=t; else h=-t; 
	}	
	printf("%f\n",t2);
	printf("%d %d",y,i);
}	
int main(){
	tinhSIN();
}	
