// G5 2166: 다각형의 면적(면적)
#include<stdio.h>
#include<stdlib.h>

struct polygon{
    int d; // number of dot(polygon)
    struct dot* dots;
};
struct dot{
    int x;
    int y;
};

void area(struct  polygon*p); // area of polygon

int main(void){
    int j;
    int d=7; scanf("%d",&d); // number of dot
    struct dot dots[d]; for(j=0;j<d;j++){scanf("%d %d",&dots[j].x,&dots[j].y);}
    struct polygon p;
    p.d=d;
    p.dots=&dots[0];
    area(&p);
}
void area(struct  polygon* p){
    long long int a=0; // area
    int j;
    for(j=0;j<p->d-1;j++){
        a+=((long long int)p->dots[j].x*(long long int)p->dots[j+1].y);
        a-=((long long int)p->dots[j].y*(long long int)p->dots[j+1].x);
    }
    a+=((long long int)p->dots[j].x*(long long int)p->dots[0].y);
    a-=((long long int)p->dots[j].y*(long long int)p->dots[0].x);
    a=(a>0)?a:-a;
    printf("%.1f",((double)a)/2);
}