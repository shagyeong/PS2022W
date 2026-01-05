// P5 3015 오아시스 재결합(스택)
#include <stdio.h>
#include <stdlib.h>

struct person{
    int h; // height
    int c; // "동일한 높이"의 연속된 사람 수
};

int main(void){
    unsigned long long int a=0; // answer: 정답
    int j;              // loop variable
    int n;
    int t=-1;           // top: 선형 스택 헤드
    int h;              // height dummy
    struct person* s;   // stack
    struct person  p;   // person dummy
    scanf("%d",&n);
    s=(struct person*)malloc(sizeof(struct person)*n);

    for(j=0;j<n;j++){
        scanf("%d",&h);
        p.h=h;
        p.c=1;
        while((t>=0)&&(h>s[t].h)){
            a+=s[t].c;
            t--;    // pop
        }
        if(t>=0){
            if(h==s[t].h){  // height가 동일한 person pop
                a+= s[t].c;
                p.c=s[t].c+1;
                if(t>0){a+=1;}
                t--;
            }
            else{a+=1;}     // h<s[t].h: p(person dummy)의 height < 스택 top의 hegith
        }
        s[++t]=p; // push
    }
    printf("%llu",a);
}


// push - pop 개념도
//                              o
//         o                    o
// o       o                    o
// o       o                    o
// o   o   o   o   o   o        o
// o   o   o   o   o   o        o
//         pop         pop      push
//         c=1         c=3      c=1, a+=4