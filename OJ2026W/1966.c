// S3 1966: 프린터 큐(구현,시뮬레이션,큐)
#include<stdio.h>
#include<stdlib.h>

int main(void){
    int j;
    int t; scanf("%d",&t);
    int n; int m;
    int c; // 출력 순서 카운터
    int* prq=(int*)malloc(sizeof(int)*100); // queue of priority
    int* idq=(int*)malloc(sizeof(int)*100); // queue of id
    int prf; int prr;
    int idf; int idr;
    int flag;

    while(t-->0){
        scanf("%d %d",&n,&m);
        for(j=0;j<n;j++){
            scanf("%d",&prq[j]);
            idq[j]=j;
        }
        prf=0; prr=n-1;
        idf=0; idr=n-1;
        c=0;
        while(1){
            flag=0;
            for(j=1;j<n;j++){if(prq[prf]<prq[(prf+j)%100]){flag=1; break;}}
            if(flag==1){
                prr+=1; prr%=100; prq[prr]=prq[prf];
                idr+=1; idr%=100; idq[idr]=idq[idf];
                prf+=1; prf%=100;
                idf+=1; idf%=100;
            }
            else{
                c+=1;
                if(idq[idf]==m){break;}
                else{
                    prf+=1; prf%=100;
                    idf+=1; idf%=100;
                    n--;
                }
            }
        }
        printf("%d\n",c);
    }
    free(prq);
    free(idq);
}