// P2 25008: 문자열 찾기(KMP)
// 언어 제한, 함수 구현
// 부분 성공
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int findP(char T[],char P[],int N,int M){
    int j;
    int k;
    int c=0;
    int* f=     (int*)malloc(sizeof(int)*M);
    int* back_a=(int*)malloc(sizeof(int)*N);
    int* back_q=(int*)malloc(sizeof(int)*M);
    int locs[26];
    
    // back()
    for(j=0;j<26;j++){locs[j]=-1;} for(j=0;j<N;j++){back_a[j]=locs[T[j]-'a'];locs[T[j]-'a']=j;}
    for(j=0;j<26;j++){locs[j]=-1;} for(j=0;j<M;j++){back_q[j]=locs[P[j]-'a'];locs[P[j]-'a']=j;}

    // fail()
    k=0;
    for(j=1;j<M;j++){
        while(k>0){
            if(back_q[k]==-1){
                if(back_q[j]<j-k){break;}
                else{k=f[k-1]; continue;}
            }
            else{
                if(k-back_q[k]==j-back_q[j]){break;}
                else{k=f[k-1]; continue;}
            }
        }

        if(back_q[k]==-1){if(back_q[j]<j-k){f[j]=++k;}}
        else{if((j-back_q[j])==(k-back_q[k])){f[j]=++k;}}
    }

    // kmp()
    k=0;
    for(j=0;j<N;j++){
        while(k>0){
            if(back_q[k]==-1){
                if(back_a[j]<j-k){break;}
                else{k=f[k-1]; continue;}
            }
            else{
                if(k-back_q[k]==j-back_a[j]){break;}
                else{k=f[k-1]; continue;}
            }
        }

        if(back_q[k]==-1){
            if(back_a[j]<j-k){
                if(k==M-1){c++; k=f[k];}
                else{k++;}
            }
        }
        else{
            if((j-back_a[j])==(k-back_q[k])){
                if(k==M-1){c++; k=f[k];}
                else{k++;}
            }
        }
    }

    free(f);
    free(back_a);
    free(back_q);
    return c;
}


int main(void){
    char* a=(char*)malloc(sizeof(char)*1000001); scanf("%s",a);
    char* q=(char*)malloc(sizeof(char)*1000001); scanf("%s",q);
    printf("%d",findP(a,q,strlen(a),strlen(q)));
    free(a);
    free(q);
}

// 원본
// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>

// #define L 1000001

// char* a;
// char* q;
// int n;
// int m;
// int* f;
// int* back_a;
// int* back_q;

// void back(void);
// void fail(void);
// void  kmp(void);

// int main(void){
//     a=(char*)malloc(sizeof(char)*L); scanf("%s",a);
//     q=(char*)malloc(sizeof(char)*L); scanf("%s",q);
//     n=strlen(a); a[n]='\0';
//     m=strlen(q); q[m]='\0';
//     back();
//     fail();
//     kmp();
//     free(a);
//     free(q);
//     free(f);
//     free(back_a);
//     free(back_q);
// }

// void back(void){
//     int j;
//     int locs[26];
//     back_a=(int*)malloc(sizeof(int)*n);
//     back_q=(int*)malloc(sizeof(int)*m);
//     for(j=0;j<26;j++){locs[j]=-1;} for(j=0;j<n;j++){back_a[j]=locs[a[j]-'a'];locs[a[j]-'a']=j;}
//     for(j=0;j<26;j++){locs[j]=-1;} for(j=0;j<m;j++){back_q[j]=locs[q[j]-'a'];locs[q[j]-'a']=j;}
//     return;
// }
// void fail(void){
//     int j;
//     int k;
//     f=(int*)calloc(m,sizeof(int));
//     k=0;
//     for(j=1;j<m;j++){
//         while(k>0){
//             if(back_q[k]==-1){
//                 if(back_q[j]<j-k){break;}
//                 else{k=f[k-1]; continue;}
//             }
//             else{
//                 if(k-back_q[k]==j-back_q[j]){break;}
//                 else{k=f[k-1]; continue;}
//             }
//         }

//         if(back_q[k]==-1){if(back_q[j]<j-k){f[j]=++k;}}
//         else{if((j-back_q[j])==(k-back_q[k])){f[j]=++k;}}
//     }
// }
// void  kmp(void){
//     int j;
//     int k;
//     int c=0; // 매칭 횟수

//     k=0;
//     for(j=0;j<n;j++){

//         while(k>0){
//             if(back_q[k]==-1){
//                 if(back_a[j]<j-k){break;}
//                 else{k=f[k-1]; continue;}
//             }
//             else{
//                 if(k-back_q[k]==j-back_a[j]){break;}
//                 else{k=f[k-1]; continue;}
//             }
//         }

//         if(back_q[k]==-1){
//             if(back_a[j]<j-k){
//                 if(k==m-1){c++; k=f[k];}
//                 else{k++;}
//             }
//         }
//         else{
//             if((j-back_a[j])==(k-back_q[k])){
//                 if(k==m-1){c++; k=f[k];}
//                 else{k++;}
//             }
//         }
//     }
//     printf("%d",c);
// }