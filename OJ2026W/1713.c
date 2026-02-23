// S1 1713: 후보 추천하기(구현,시뮬레이션)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int asc(const void* u,const void* v){return *((int*)u)-*((int*)v);}

int main(void){
    int j; int k;
    int n; scanf("%d",&n);
    int m; scanf("%d",&m);

    int i=0; // inedex of pics
    int stud[n]; // 사진틀: 학생 번호 저장
    int recs[n]; // 사진틀: 추천 수 저장
    int time[n]; // 사진틀: 저장 시점
    int v;
    int f; // flag: 사진틀에 이미 존재함
    int min_recs; // 삭제할 사진: 추천 최소값
    int min_time; // 삭제할 사진: 시점 최소값
    int d; // 삭제할 사진 인덱스

    for(j=0;j<m;j++){
        f=0;
        scanf("%d",&v);
        for(k=0;k<i;k++){if(v==stud[k]){recs[k]+=1;f=1;}}
        if(f==1){continue;}
        
        if(i<n){
            stud[i]=  v;
            recs[i]=  1;
            time[i++]=j;
        }
        else{
            min_recs=1001;
            min_time=1001;
            for(k=0;k<n;k++){
                if(recs[k]<min_recs){
                    min_recs=recs[k];
                    min_time=time[k];
                    d=k;
                }
                if(recs[k]==min_recs){
                    if(time[k]<min_time){
                        // min_recs=recs[k];
                        min_time=time[k];
                        d=k;
                    }
                }
            }
            stud[d]=v;
            recs[d]=1;
            time[d]=j;
        }
    }
   
    qsort(stud,i,sizeof(int),asc);
    for(j=0;j<i;j++){printf("%d ",stud[j]);}
}