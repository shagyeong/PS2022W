// S2 12891: DNA 비밀번호(문자열,슬라이딩윈도우)
#include<stdio.h>
#include<stdlib.h>

int main(void){
    int j;
    int n; int l; scanf("%d %d",&n,&l);
    int m=0; // answer
    char* s=(char*)malloc(sizeof(char)*(n+1)); scanf("%s",s); s[n]='\0';
    int a['T'+1]; scanf("%d %d %d %d",&a['A'],&a['C'],&a['G'],&a['T']);
    int b['T'+1]; for(j=0;j<=(int)'T';j++){b[j]=0;}

    // 윈도우 초기화
    for(j=0;j<l;j++){b[s[j]]++;}
    if((b['A']>=a['A'])&&(b['C']>=a['C'])&&(b['G']>=a['G'])&&(b['T']>=a['T'])){m++;}

    // 투포인터, 슬라이딩윈도우
    for(j=1;j<=(n-l);j++){
        b[s[j-1]]--;
        b[s[j+l-1]]++;
        if((b['A']>=a['A'])&&(b['C']>=a['C'])&&(b['G']>=a['G'])&&(b['T']>=a['T'])){m++;}
    }

    printf("%d",m);
    free(s);
}