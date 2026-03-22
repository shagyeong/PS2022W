// S3 1002: 터렛(기하학)
#include<stdio.h>

struct node{
    int x;
    int y;
    int r;
};

int main(void){
    int _; scanf("%d",&_);
    struct node a;
    struct node b;
    int d; // (a.x-b.x)^2+(a.y-b.y)^2
    int r; // (a.r+b.r)^2
    while(_-->0){
        scanf("%d %d %d",&a.x,&a.y,&a.r);
        scanf("%d %d %d",&b.x,&b.y,&b.r);
        // 포개짐
        if((a.x==b.x)&&(a.y==b.y)&&(a.r==b.r)){printf("-1\n"); continue;}

        // 접하지 않음, 외부에서 접함
        d=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
        r=(a.r+b.r)*(a.r+b.r);
        if(d> r){printf("0\n"); continue;}
        if(d==r){printf("1\n"); continue;}
        
        // 겹침, 내부에서 접함, 포함
        r=(a.r-b.r)*(a.r-b.r);
        if(d> r){printf("2\n"); continue;}
        if(d==r){printf("1\n"); continue;}
        if(d< r){printf("0\n"); continue;}
    }
}