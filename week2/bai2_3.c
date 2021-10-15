#include<stdio.h>
typedef struct point
{
    double x;
    double y;
}point_t;
typedef struct cricle
{
    point_t center;
    double radius;
}cricle_t;

int is_in_cricle(point_t *p,cricle_t *c){
    double x_dist, y_dist;
    x_dist = (p->x) - (c->center.x);
    y_dist = (p->y) - (c->center.y);
    return (x_dist*x_dist + y_dist*y_dist - (c->radius)*(c->radius));
}
int main(){
    point_t p;
    cricle_t c;
    printf("Toa do diem:\n");
    scanf("%ld %ld",&p.x,&p.y);
    printf("Toa do tam hinh tron:\n");
    scanf("%lf%lf",&c.center.x,&c.center.y);
    printf("Ban kinh:\n");
    scanf("%lf",&c.radius);
    if(is_in_cricle(&p,&c) >= 0  )
        printf("Diem trong hinh tron.");
    else printf("Diem nam ngoai hinh tron");    
    return 0;
}