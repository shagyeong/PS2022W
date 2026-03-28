// G5 11758: CCW(기하학,CCW)
#include<stdio.h>

struct dot{
    int x;
    int y;
};

int ccw(struct dot A,struct dot B,struct dot C){
    int r=(B.x-A.x)*(C.y-A.y)-(C.x-A.x)*(B.y-A.y);
    if(r> 0){return  1;} // ccw
    if(r==0){return  0;} // collinear
    if(r< 0){return -1;} // cw
}

int main(void){
    struct dot A; scanf("%d %d",&A.x,&A.y);
    struct dot B; scanf("%d %d",&B.x,&B.y);
    struct dot C; scanf("%d %d",&C.x,&C.y);
    printf("%d",ccw(A,B,C));
}