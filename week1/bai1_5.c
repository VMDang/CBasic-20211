#include<stdio.h>
int tach_so(int tu, int mau){
    int nguyen=tu/mau;
    int ucln = rut_gon(tu,mau);
    printf("Phan nguyen: %d\n",nguyen);
    printf("Phan so: %d/%d",(tu-nguyen*mau)/ucln,mau/ucln);

}
int rut_gon(int tu ,int mau){
    int ucln=1;
    for(int i=1;i<=tu;i++){
        for(int j=1;j<=mau;j++){
            if( tu%i==0 && mau%j==0 & i==j){
                ucln = i;
            }
        }
    }
    return ucln;
}
int main(){
    int t,m;
    printf("Nhap phan so:");
    scanf("%d/%d",&t,&m);
    tach_so(t,m);
}