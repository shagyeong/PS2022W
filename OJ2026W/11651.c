// S5 11651: 좌표 정렬하기 2(정렬)
#include<stdio.h>
#include<stdlib.h>

struct node{
    int x;
    int y;
};

int compare(const void* u,const void* v){
    if(((struct node*)u)->y<((struct node*)v)->y){return -1;}
    if(((struct node*)u)->y>((struct node*)v)->y){return  1;}
    if(((struct node*)u)->x<((struct node*)v)->x){return -1;}
    if(((struct node*)u)->x>((struct node*)v)->x){return  1;}
    return 0;
}

int main(void){
    int j;
    int n; scanf("%d",&n);
    struct node* a=(struct node*)malloc(sizeof(struct node)*n);
    for(j=0;j<n;j++){scanf("%d %d",&a[j].x,&a[j].y);} qsort(a,n,sizeof(struct node),compare);
    for(j=0;j<n;j++){printf("%d %d\n",a[j].x,a[j].y);}
    free(a);
}