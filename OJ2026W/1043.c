// G4 1043: 거짓말(분리 집합)
#include<stdio.h>

#define N 55
unsigned char p[N];    // parent
unsigned char f[N][N]; // party

unsigned char getroot(unsigned char q);

int main(void){
    unsigned char c; // 정답
    unsigned char j; // loop variable
    unsigned char l; // loop variable
    unsigned char n; // 사람 수
    unsigned char m; // 파티 수
    unsigned char k; // "진실을 아는" 사람 수
    unsigned char a; // unify dummy
    unsigned char b; // unify dummy

    scanf("%hhu %hhu",&n,&m);
    scanf("%hhu",&k);

    for(j=1;j<=n;j++){p[j]=j;}

    // "진실을 아는" union: 루트 a
    scanf("%hhu",&a);
    for(j=1;j<k;j++){
        scanf("%hhu",&b);
        p[b]=a; // unify
    }

    // 입력
    for(j=0;j<m;j++){
        scanf("%hhu",&f[j][0]); // column 0: 개별 파티 참가 인원
        for(l=1;l<=f[j][0];l++){
            scanf("%hhu",&f[j][l]);
            if(l>1){p[getroot(f[j][l])]=getroot(f[j][l-1]);} // unify
        }
    }

    // 확산 완료 후 재순환
    c=m; // 정답: 전체 파티 수(m)에서 차감
    for(j=0;j<m;j++){
        for(l=1;l<=f[j][0];l++){
            if(getroot(f[j][l])==getroot(a)){
                c-=1;
                break;
            }
        }
    }
    if(k==0){printf("%hhu",m);}
    else    {printf("%hhu",c);}
}
unsigned char getroot(unsigned char q){
    if(p[q]==q){return q;}
    else       {return p[q]=getroot(p[q]);}
}
