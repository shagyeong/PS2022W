// G3 13904: 과제(정렬)
#include<stdio.h>
#include<stdlib.h> // qsort

struct hw{
    int d; // deadline: 마감일
    int p; // points: 배점
};

int compare(const void* u,const void* v);

int main(void){
    int j;
    int h[1001]; for(j=0;j<1001;j++){h[j]=0;} // 점수 저장
    int p=0; // 총점
    int n; scanf("%d",&n);
    int d;
    struct hw a[n]; for(j=0;j<n;j++){scanf("%d %d",&a[j].d,&a[j].p);}
    qsort(a,n,sizeof(struct hw),compare);

    for(j=0;j<n;j++){
        d=a[j].d;
        while(d>=1){
            if(h[d]==0){
                h[d]=a[j].p;
                break;
            }
            else{d--;}
        }
    }
    for(j=0;j<=1000;j++){p+=h[j];}
    printf("%d",p);
}

int compare(const void* u,const void* v){
    if((((struct hw*)u)->p)> (((struct hw*)v)->p)){return -1;}
    if((((struct hw*)u)->p)< (((struct hw*)v)->p)){return 1;}
    if((((struct hw*)u)->p)==(((struct hw*)v)->p)){
        if((((struct hw*)u)->d)>(((struct hw*)v)->d)){return -1;}
        if((((struct hw*)u)->d)<(((struct hw*)v)->d)){return 1;}
    }
    return 0;
}