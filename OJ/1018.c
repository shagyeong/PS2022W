//1018: 체스판 다시 칠하기(브루트포스 알고리즘)
#include<stdio.h>

int main(void){
    int ans = 64;
    int count;
    char nl;
    int i, j, x, y;
    int n, m; scanf("%d %d", &n, &m);
    char plate[n][m];

    scanf("%c", &nl);
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            scanf("%c", &plate[i][j]);
        }scanf("%c", &nl);//개행 문자 입력 처리
    }
    
    for(i = 0; i <= n - 8; i++){
        for(j = 0; j <= m - 8; j++){
            count = 0;
            for(x = i; x < i + 8; x++){
                for(y = j; y < j + 8; y++){
                    if((x + y)%2 == 0){
                        count = (plate[x][y] == 'W')?(count + 1):count;
                    }
                    else{
                        count = (plate[x][y] == 'B')?(count + 1):count;
                    }
                }
            }
            count = (count < 64 - count)?count:(64-count);
            ans = (count < ans)?count:ans;
        }
    }
    printf("%d", ans);
}
