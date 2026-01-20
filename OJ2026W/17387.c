// G2 17387: 선분 교차 2(기하학,선분교차)
#include <stdio.h>

struct dot{
    int x;
    int y;
};
int ccw(struct dot A,struct dot B,struct dot C);
int intersect(struct dot A,struct dot B,struct dot C,struct dot D);

int main(void){
    struct dot A; scanf("%d %d",&A.x,&A.y);
    struct dot B; scanf("%d %d",&B.x,&B.y);
    struct dot C; scanf("%d %d",&C.x,&C.y);
    struct dot D; scanf("%d %d",&D.x,&D.y);
    printf("%d",intersect(A,B,C,D));
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