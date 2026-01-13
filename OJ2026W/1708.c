// P5 1708: 볼록 껍질(볼록 껍질)
#include<stdio.h>
#include<stdlib.h>

struct polygon{
    int d; // number of dot(polygon)
    int h; // number of dot(hull)
    struct dot* dots;
    struct dot* hull;
};
struct dot{
    int x;
    int y;
};

int compare(const void* u,const void* v);
int ccw(struct dot A,struct dot B,struct dot C); // counter-clockwise
void   mc(struct polygon* p); // monotone chain

int main(void){
    int j;
    int d=7; scanf("%d",&d); // number of dot
    struct dot dots[d]; for(j=0;j<d;j++){scanf("%d %d",&dots[j].x,&dots[j].y);}
    struct polygon p;
    p.d=d;
    p.h=0;
    p.dots=&dots[0];
    p.hull=NULL;
    mc(&p);
    // area(&p);
}

int compare(const void* u,const void* v){
    if((((struct dot*)u)->x)< (((struct dot*)v)->x)){return -1;}
    if((((struct dot*)u)->x)> (((struct dot*)v)->x)){return  1;}
    if((((struct dot*)u)->x)==(((struct dot*)v)->x)){
        if((((struct dot*)u)->y)< (((struct dot*)v)->y)){return -1;}
        if((((struct dot*)u)->y)> (((struct dot*)v)->y)){return  1;}
    }
    return 0;
}
int ccw(struct dot A,struct dot B,struct dot C){
    long long int op=0;
    op=op+(long long int)A.x*B.y-A.y*B.x;
    op=op+(long long int)B.x*C.y-B.y*C.x;
    op=op+(long long int)C.x*A.y-C.y*A.x;
    if(op>0)return 1;
    if(op<0)return -1;
    return 0;
}
void mc(struct polygon* p){
    int j; // loop variable
    int k; // loop variable
    p->h=0;
    p->hull=(struct dot*)malloc(sizeof(struct dot)*2*(p->d));
    qsort(p->dots,p->d,sizeof(struct dot),compare);    
    
    // lower hull
    for(j=0;j<p->d;j++){
        while(p->h>=2&&ccw(p->hull[p->h-2],p->hull[p->h-1],p->dots[j])<=0){p->h--;}
        p->hull[p->h++]=p->dots[j];
    }
    
    // upper hull
    k=p->h+1;
    for(j=p->d-2;j>=0;j--){
        while(p->h>=k&&ccw(p->hull[p->h-2],p->hull[p->h-1],p->dots[j])<=0){p->h--;}
        p->hull[p->h++]=p->dots[j];
    }
    p->h--;
    printf("%d",p->h);
}