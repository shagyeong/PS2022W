// P5 6549: 히스토그램에서 가장 큰 직사각형(스택)
#include<stdio.h>
#include<stdlib.h>

int main(void){
    int j;
    int n;
    int i; // index of array
    int w;
    long long int m; // 면적 최대값
    int* a=(int*)malloc(sizeof(int)*1000001); // 원본 데이터
    int* s=(int*)malloc(sizeof(int)*1000001); // 스택
    int t; // top of stack

    while(1){
        scanf("%d",&n); 
        if(n==0){break;}
        for(j=0;j<n;j++){scanf("%d",&a[j]);}
        m=0;
        a[n]=0; t=-1;

        for(j=0;j<=n;j++){
            while((t>=0)&&(a[s[t]]>a[j])){
                i=s[t--]; // pop
                if(t==-1){w=j;}
                else     {w=j-s[t]-1;}
                m=(m>(long long int)a[i]*w)?m:(long long int)a[i]*w;
            }
            s[++t]=j; // push
        }
        printf("%lld\n",m);
    }
}
