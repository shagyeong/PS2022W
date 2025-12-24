// 10026: 적록색약(격자그래프, 그래프 탐색)
#include<stdio.h>

// 방문 상태
#define F 0
#define T 1

unsigned short bfs(unsigned char n,char a[n][n],char v[n][n]);

int main(void){
    char l; // new line dummy
    unsigned char j; // loop variable
    unsigned char k; // loop variable
    unsigned char n;
    
    scanf("%hhd",&n); scanf("%c",&l);
    char a[n][n];
    char v[n][n]; // 방문 상태

    for(j=0;j<n;j++){
        for(k=0;k<n;k++){
            scanf("%c",&a[j][k]);
            v[j][k]=F;
        }
        scanf("%c",&l);
    }

    printf("%u ",bfs(n,a,v));

    for(j=0;j<n;j++){
        for(k=0;k<n;k++){
            v[j][k]=F;
            if(a[j][k]=='R'){a[j][k]='G';}
        }
    }
    printf("%u",bfs(n,a,v));
}

unsigned short bfs(unsigned char n,char a[n][n],char v[n][n]){
    unsigned short ans=0;   // answer
    unsigned char  j;       // loop variable
    unsigned char  k;       // loop variable
    unsigned char  row[n*n];// 선형 큐: 행 인덱스
    unsigned char  col[n*n];// 선형 큐: 열 인덱스
    char           r;       // 행 인덱스 버퍼
    char           c;       // 열 인덱스 버퍼
    unsigned short f;       // 선형 큐: front
    unsigned short e;       // 선형 큐: rear -> end
    char h;                 // hue: 색상 버퍼

    for(j=0;j<n;j++){
        for(k=0;k<n;k++){
            if(v[j][k]==F){
                v[j][k]=T;
                ans+=1;
                h=a[j][k];
                f=0;
                e=0;
                row[e]=  j; // enqueue
                col[e++]=k; // enqueue
                while(f<e){
                    r=row[f];   // dequeue
                    c=col[f++]; // dequeue
                    // 상하좌우 인덱스 범위 확인
                    // 방문되지 않았고 색이 같은 경우 enqueue
                    if(r-1>=0){
                        if((v[r-1][c]==F)&&(a[r-1][c]==h)){
                            v[r-1][c]=T;
                            row[e]=r-1;
                            col[e++]=c;
                        }
                    }
                    if(r+1<n){
                       if((v[r+1][c]==F)&&(a[r+1][c]==h)){
                            v[r+1][c]=T;
                            row[e]=r+1;
                            col[e++]=c;
                        }
                    }
                    if(c-1>=0){
                       if((v[r][c-1]==F)&&(a[r][c-1]==h)){
                            v[r][c-1]=T;
                            row[e]=  r;
                            col[e++]=c-1;
                        }
                    }
                    if(c+1<n){
                       if((v[r][c+1]==F)&&(a[r][c+1]==h)){
                            v[r][c+1]=T;
                            row[e]=  r;
                            col[e++]=c+1;
                        }
                    }
                }

            }
        }
    }
    return ans;
}