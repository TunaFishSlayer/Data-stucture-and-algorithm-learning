
#include <stdio.h>
#define m 100
#include<string.h>
#include<stdlib.h>
#include<math.h>
void menu();		// Ham nay se xuat ra cac danh sach menu
int chonmenu();		// Ham nay dung de chon 1 menu tuong ung
void xulyMenu();	// Xu ly menu ung voi menu duoc chon
typedef struct pt{
    char ten[21];
    int dai;
    int rong;
    int cao;
    double cannang;
    int vanch;
} kienhang;
double lamtron(double x){
    double i,p;
    p=modf(x,&i);
    if (p>0 && p<=0.5) i+=0.5; 
    if (p>0.5) i+=1;
    return i;
}
double tinhcannang(int x,int d){
    double kg;
    if (d==1) kg=x/6000;
    if (d==0) kg=x/4000;
    return kg;
}
double tinhphi(double kg,int d){
    double t;
    if (d==1) {
        if (kg<=3) t=22000;
        else t=22000+(kg-3)*5000;}
    if (d==0) {
        if (kg<=3) t=16500;
        else t=22000+(kg-3)*5000;}
    return t;    
    }    
void menu() {
    printf("Moi ban chon chuc nang\n");
    printf("========================\n");
	printf("   1.Nhap thong tin kien hang\n");
	printf("   2.Chi tiet kien hang bi tu choi\n");
	printf("   3.Chi tiet cac kien hang hop le\n");
	printf("   4.Tinh phi van chuyen\n");
	printf("   5.Thoat\n");
}
int chonmenu()
{
	int n = 0;
	printf("\n\nMoi chon menu :");
	scanf("%d",&n);
	if (n > 0 && n < 6) return n;
	else 
	{
	    while ( n<0 || n >5 ) 
	    {
	        printf("So khong thoa man, moi chon lai\n");
	        scanf("%d",&n);
	    }
	    return n;
	}
}

void xulymenu(int x){
    static int b[m];
    char s[21];
    kienhang a[m];
    int n,i,w,t,c,d;
    for (i=0;i<m;i++) b[i]=0;
    switch(x){
        case 1: 
                printf("Nhap so kien hang: ");
                scanf("%d",&n);
                while (n<0) 
                {
                    printf("So kien hang khong thoa man, nhap lai");
                    scanf("%d",&n);
                }
                for (i=0;i<n;i++)
                {   
                    // Nhap ten
                    re1:
                    printf("Nhap ten kien hang thu %d: ",i+1);
                    scanf("%s",s);strcpy(a[i].ten,s);
                    if (strlen(s)<8 || strlen(s)>20) {printf("Ten khong thoa man\n");goto re1;}
                    for (w=0;w<strlen(s);w++) {
                        if (s[w]>=97 && s[w]<=122) s[w]-=32;
                        if ((s[w]<65 || s[w] > 90) && (s[w]<48 || s[w]>57)) {printf("Ten khong thoa man\n");goto re1;}
                    }
                    strcpy(a[i].ten,s);
                    // Nhap chieu dai,rong,cao
                    printf("Nhap chieu dai cua kien hang thu %d: ",i+1);
                    scanf("%d",&a[i].dai);
                    printf("Nhap chieu rong cua kien hang thu %d: ",i+1);
                    scanf("%d",&a[i].rong);
                    printf("Nhap chieu cao cua kien hang thu %d: ",i+1);
                    scanf("%d",&a[i].cao);
                    // Nhap can nang
                    printf("Nhap can nang cua kien hang thu %d: ",i+1);
                    scanf("%lf",&a[i].cannang);
                    // Nhap loai van chuyen
                    printf("Chon phuong phap van chuyen(1.nhanh,0.thuong): ");
                    scanf("%d",&a[i].vanch);
                }
                break;
        case 2: //Chi tiet cac kien hang bi tu choi
                c=0;
                t=0;
                for (i=0;i<n;i++){
                    if (a[i].dai<10 || a[i].rong<10 || a[i].cao<10) {b[i]=1;t++;}
                    if (a[i].dai>150 || a[i].rong>150 || a[i].cao>150) {b[i]=2;t++;}
                    if (a[i].cannang>30) {b[i]=3;t++;}
                }
                if (t==0) printf("Khong co kien hang bi loi\n"); else {
                    printf("Chi tiet kien hang bi tu choi\n");
                    printf("====================================\n");
                    printf("%-20s%-20s\n","Ma kien","Ly do bi tu choi");
                    for (i=0;i<n;i++){
                        if (b[i]==1) {printf("%-20s%-20s\n",a[i].ten,"ER1");c++;}
                        if (b[i]==2) {printf("%-20s%-20s\n",a[i].ten,"ER2");c++;}
                        if (b[i]==3) {printf("%-20s%-20s\n",a[i].ten,"ER3");c++;}
                    }
                    printf("Tong so: %d",c);
                }
                break;
        case 3: //Chi tiet cac kien hang hop le
                for (i=0;i<n;i++){
                    if (a[i].dai<10 || a[i].rong<10 || a[i].cao<10) {b[i]=1;t++;}
                    if (a[i].dai>150 || a[i].rong>150 || a[i].cao>150) {b[i]=2;t++;}
                    if (a[i].cannang>30) {b[i]=3;t++;}
                }
                d=0;
                double kg;
                printf("Chi tiet cac kien hang hop le\n");
                printf("====================================\n");
                printf("%-20s%-30s%-20s%20s\n","Ma kien","Can nang tinh phi","Hinh thuc van chuyen","Cuoc phi");
                for (i=0;i<n;i++) {
                    if (b[i]==0) {
                        int x=a[i].dai*a[i].rong*a[i].cao;d++;
                        if (a[i].dai+a[i].rong+a[i].cao<80) kg=lamtron(a[i].cannang); else {
                            if (a[i].cannang>tinhcannang(x,a[i].vanch)) kg=lamtron(a[i].cannang); 
                            else kg=lamtron(tinhcannang(x,a[i].vanch));}
                        if (a[i].vanch==1) printf("%-25s%-25.2lf%-20s%20.0lf\n",a[i].ten,kg,"Chuyen nhanh",tinhphi(kg,1));
                        if (a[i].vanch==0) printf("%-25s%-25.2lf%-20s%20.0lf\n",a[i].ten,kg,"Chuyen thuong",tinhphi(kg,0));
                    }
                }
                printf("Tong so %d: ",d);
                break;
        case 4: //Tinh phi van chuyen
                for (i=0;i<n;i++){
                    if (a[i].dai<10 || a[i].rong<10 || a[i].cao<10) {b[i]=1;t++;}
                    if (a[i].dai>150 || a[i].rong>150 || a[i].cao>150) {b[i]=2;t++;}
                    if (a[i].cannang>30) {b[i]=3;t++;}
                }
                double k;
                double tien=0;
                printf("Chi phi van chuyen\n");
                printf("====================================\n");
                printf("So luong kien hang da nhan: %d \n",d);
                for (i=0;i<n;i++) {
                    if (b[i]==0) {
                        int x=a[i].dai*a[i].rong*a[i].cao;
                        if (a[i].dai+a[i].rong+a[i].cao<80) k=lamtron(a[i].cannang); else {
                            if (a[i].cannang>tinhcannang(x,a[i].vanch)) k=lamtron(a[i].cannang); 
                            else k=lamtron(tinhcannang(x,a[i].vanch));}
                        if (a[i].vanch==1) tien+=tinhphi(k,1); 
                        if (a[i].vanch==0) tien+=tinhphi(k,0);
                    }
                }    
                printf("Tong tien cuoc: %.0lf\n",tien);
                printf("VAT: %.0lf\n",tien*8/100);
                printf("Tong tien can tra %.0lf\n",tien*108/100);
                break;
    }    
}
int main(){
    int n=0;
    while(n!=5){
        menu();
        n=chonmenu();
        xulymenu(n);
        getchar();
        printf("\nNhan phim bat ky de tiep tuc!");
        getchar();
    }
    return 0;
}
