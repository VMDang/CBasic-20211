#include<stdio.h>
int main()
{
    double width,height;
    scanf("%lf %lf",&height,&width);

    printf("The rectangle's area is %lf\n",width*height);
    printf("The reactangle's periment is %lf\n",2*(width+height));
    return 0;
}