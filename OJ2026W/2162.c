// P5 2162: 선분 그룹(선분교차,분리집합)
#include<stdio.h>
#include<stdlib.h>

struct dot{
    int x;
    int y;
};
struct line{
    struct dot A;
    struct dot B;
};
int ccw(struct dot A,struct dot B,struct dot C);
int intersect(struct dot A,struct dot B,struct dot C,struct dot D);

int* p; // 전역 분리집합
int getroot(int q);
void  unify(int u,int v);

struct line* a; // 전역 선분집합

int main(void){
    int j;
    int k;
    int n; scanf("%d",&n);
    int* c; // count: 분리집합 루트별 원소 개수 카운트
    int g=0; // number of group
    int m=0; // 최대 원소 개수
    c=(int*)malloc(sizeof(int)*n);
    p=(int*)malloc(sizeof(int)*n);
    a=(struct line*)malloc(sizeof(struct line)*n);
    for(j=0;j<n;j++){
        c[j]=0;
        p[j]=j;
        scanf(
            "%d %d %d %d",
            &a[j].A.x,
            &a[j].A.y,
            &a[j].B.x,
            &a[j].B.y
        );
    }
    for(j=0;j<n;j++){
        for(k=j+1;k<n;k++){
            if(intersect(a[j].A,a[j].B,a[k].A,a[k].B)==1){
                unify(j,k);
            }
        }
    }

    // 정답 추출: 그룹 개수, 최대 원소 개수
    for(j=0;j<n;j++){c[getroot(p[j])]+=1;}
    for(j=0;j<n;j++){if(c[j]!=0){g+=1; if(c[j]>m){m=c[j];}}}
    printf("%d\n",g);
    printf("%d\n",m);
}

int getroot(int q){
    if(p[q]==q){return q;}
    else       {return p[q]=getroot(p[q]);}
}
void unify(int u,int v){
    p[getroot(u)]=getroot(v);
}
int ccw(struct dot A,struct dot B,struct dot C){
    long long int op=0; // outer product: 외적
    op=op+(long long int)A.x*B.y-(long long int)A.y*B.x;
    op=op+(long long int)B.x*C.y-(long long int)B.y*C.x;
    op=op+(long long int)C.x*A.y-(long long int)C.y*A.x;
    if(op>0){return 1;}  // counter-clockwise
    if(op<0){return -1;} // clockwise
             return 0;   // 일직선
}
int intersect(struct dot A,struct dot B,struct dot C,struct dot D){
    int ABC=ccw(A,B,C);
    int ABD=ccw(A,B,D);
    int CDA=ccw(C,D,A);
    int CDB=ccw(C,D,B);

    if((ABC*ABD>0)||(CDA*CDB>0)){
        return 0;
    }
    else{
        if((ABC*ABD!=0)||(CDA*CDB!=0)){
            return 1;
        }
        else{
            int ABX_MIN=(A.x<B.x)?A.x:B.x;
            int ABX_MAX=(A.x>B.x)?A.x:B.x;
            int CDX_MIN=(C.x<D.x)?C.x:D.x;
            int CDX_MAX=(C.x>D.x)?C.x:D.x;
            int ABY_MIN=(A.y<B.y)?A.y:B.y;
            int ABY_MAX=(A.y>B.y)?A.y:B.y;
            int CDY_MIN=(C.y<D.y)?C.y:D.y;
            int CDY_MAX=(C.y>D.y)?C.y:D.y;
            return (ABX_MIN<=CDX_MAX)&&(CDX_MIN<=ABX_MAX)&&(ABY_MIN<=CDY_MAX)&&(CDY_MIN<=ABY_MAX);
        }
    }
}