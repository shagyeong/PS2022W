// G4 2239: 스도쿠(백트래킹)
#include<stdio.h>

int a[9][9];
int i;
int p; // 전역 플래그: 사전순 최선임 1회 출력 후 종료
int _r[81];
int _c[81];

void backtrack(int d,int c); //빈칸 개수, 빈칸 인덱스

int main(void){
    int j; int k;
    i=0; p=0;
    for(j=0;j<9;j++){for(k=0;k<9;k++){
        scanf("%1d",&a[j][k]);
        if(a[j][k]==0){
            _r[i  ]=j;
            _c[i++]=k;
        }
    }}
    backtrack(i,0);
}

void backtrack(int d,int c){
    int j; int k; int l;
    int f; // 플래그: 해당 자리에 j를 넣을 수 없음
    if(p==1){return;}
    if(d==0){
        p=1;
        for(j=0;j<9;j++){for(k=0;k<9;k++){printf("%d",a[j][k]);}printf("\n");}
        return;
    }
    for(j=1;j<=9;j++){
        f=1;
        for(k=0;k<9;k++){if(a[_r[c]][k]==j){f=0; goto escape;}}
        for(k=0;k<9;k++){if(a[k][_c[c]]==j){f=0; goto escape;}}
        for(k=(_r[c]/3)*3;k<(_r[c]/3)*3+3;k++){for(l=(_c[c]/3)*3;l<(_c[c]/3)*3+3;l++){
            if(a[k][l]==j){f=0; goto escape;}
        }}
        escape:
        if(f==0){continue;}
        a[_r[c]][_c[c]]=j; backtrack(d-1,c+1);
        a[_r[c]][_c[c]]=0;
    }
}