
#include <stdio.h>
#define m 100
#include<string.h>
#include<stdlib.h>
void menu();		// Ham nay se xuat ra cac danh sach menu
int chonmenu();		// Ham nay dung de chon 1 menu tuong ung
void xulyMenu();	// Xu ly menu ung voi menu duoc chon
typedef struct pt{
    char ten[5];
    double dientich;
    int dieuhoa;
} phongtro;

void menu() {
	printf("1.Nhap thong tin phong tro\n");
	printf("2.In thong tin phong tro\n");
	printf("3.Tim kiem theo dien tich\n");
	printf("4.Sap xep\n");
	printf("5.Thong ke so luong dieu hoa can bo sung\n");
	printf("6.Thoat\n");
}
int chonmenu()
{
	int n = 0;
	printf("\n\nMoi chon menu:");
	scanf("%d",&n);
	if (n > 0 && n < 7) return n;
	else 
	{
	    while ( n<0 || n >6 ) 
	    {
	        printf("So khong thoa man, moi chon lai\n");
	        scanf("%d",&n);
	    }
	    return n;
	}
}
void xulymenu(int x){
    char s[5];
    phongtro a[m];
    static int d=0;
    int n,i,j,w;
    switch(x){
        case 1: printf("Nhap so phong tro:");
                scanf("%d",&n);
                while (n<0) 
                {
                    printf("So phong tro khong thoa man, nhap lai");
                    scanf("%d",&n);
                }
                for (i=d;i<n+d;i++)
                {   
                    re1:
                    printf("Nhap ten phong tro thu %d: ",i+1);
                    scanf("%s",s);strcpy(a[i].ten,s);
                    if (strlen(s)!=4) {printf("Ten khong thoa man\n");goto re1;}
                    for (w=0;w<strlen(s);w++)
                    if ((s[w]<65 || s[w] > 90) && (s[w]<97 || s[w] >122)) {printf("Ten khong thoa man\n");goto re1;}
                    re2:
                    printf("Nhap dien tich phong tro thu %d: ",i+1);
                    scanf("%lf",&a[i].dientich);
                    if (a[i].dientich<10 || a[i].dientich>40) {printf("Dien tich phai thuoc khoang 10 va 40\n");goto re2;}
                    re3:
                    printf("Phong tro thu %d co dieu hoa khong(1:co,0:khong): ",i+1);
                    scanf("%d",&a[i].dieuhoa);
                    if (a[i].dieuhoa<0 || a[i].dieuhoa>1) {printf("nhap lai\n");goto re3;}
                }
                d+=n;
                break;
        case 2: if (d==0) printf("Chua co thong tin gi ve phong tro\n"); 
                else 
                {
                printf("Ten phong    Dien tich    Dieu hoa\n");
                for (i=0;i<d;i++)
                {
                    if (a[i].dieuhoa==0) printf("%-13s%-13.2lf%-8s\n",a[i].ten,a[i].dientich,"Khong");
                    else printf("%-13s%-13.2lf%-8s\n",a[i].ten,a[i].dientich,"Co");
                }
                }
                break;
        case 3: if (d==0) printf("Chua co thong tin gi ve phong tro\n"); 
                else 
                {   
                    int y=0;
                    printf("Nhap dien tich: ");
                    double dt,t;
                    scanf("%lf",&dt);
                    for (i=0;i<d;i++)
                    {   
                        t=a[i].dientich-dt;
                        if (t>-5 && t<5) y++;
                    }
                    if (y<1) printf("Khong co phong tro thoa man\n");
                    else 
                    {
                        printf("Ten phong    Dien tich    Dieu hoa\n");
                        for (i=0;i<d;i++)
                        {   
                            t=a[i].dientich-dt;
                            if (t>-5 && t<5) 
                                if (a[i].dieuhoa==0) printf("%-13s%-13.2lf%-8s\n",a[i].ten,a[i].dientich,"Khong");
                                else printf("%-13s%-13.2lf%-8s\n",a[i].ten,a[i].dientich,"Co");
                        }}   
                }        
                break;
        case 4: if (d==0) printf("Chua co thong tin gi ve phong tro\n"); 
                else 
                { 
                phongtro temp;
                for (i=0;i<d-1;i++)
                    for (j=i+1;j<d;j++) 
                        if (a[i].dientich<a[j].dientich){
                            temp = a[i];
                            a[i] = a[j];
                            a[j] = temp;
                        }
                printf("Ten phong    Dien tich    Dieu hoa\n");
                for (i=0;i<d;i++)
                    if (a[i].dieuhoa==0) printf("%-13s%-13.2lf%-8s\n",a[i].ten,a[i].dientich,"Khong");
                        else printf("%-13s%-13.2lf%-8s\n",a[i].ten,a[i].dientich,"Co");
                }
                break;
        case 5: if (d==0) printf("Chua co thong tin gi ve phong tro\n"); 
                else 
                { 
                int dh1,dh2,dh3,dh4;
                dh1=0;dh2=0;dh3=0;dh4=0;
                for (i=0;i<d;i++)
                {   
                    if (a[i].dieuhoa==0 && a[i].dientich<=15) {dh1++;}
                    if (a[i].dieuhoa==0 && a[i].dientich>15 && a[i].dientich<=22) {dh2++;}
                    if (a[i].dieuhoa==0 && a[i].dientich>22 && a[i].dientich<=30) {dh3++;}
                    if (a[i].dieuhoa==0 && a[i].dientich>30) {dh4++;}
                }
                printf("Luong dieu hoa can lap la:\n");
                printf("%d dieu hoa 9000BTU\n",dh1);
                printf("%d dieu hoa 12000BTU\n",dh2);
                printf("%d dieu hoa 18000BTU\n",dh3);
                printf("%d dieu hoa 21000BTU\n",dh4);
                }
                break;
    }
}
int main(){
    int n=0;
    while(n!=6){
        menu();
        n=chonmenu();
        xulymenu(n);
        getchar();
        printf("\nNhan phim bat ky de tiep tuc!");
        getchar();
        system("cls");
    }
    return 0;
}
