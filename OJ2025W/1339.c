//1339: 단어 수학(그리디 알고리즘)
#include<stdio.h>
#include<stdlib.h>  //정렬 구현 생략
int compare(const void* a, const void* b){
    if(*(int*)a < *(int*)b){return 1;}
    else{return -1;}
}
int main(void){
    int ans = 0;

    int i, j, k;
    int len = 0;
    char nl;
    
    int max = 0; int ind = -1;    //각 자리에서 가장 많이 나온 횟수에 인덱스 저장
    int weight = 1; //가중치 9 ~ 0
    int flag[26];   //알파벳별 가중치
    for(i = 0; i < 26; i++){flag[i] = 0;}

    //문자별, 자릿수별 등장 횟수
    int arr[26][8];
    for(i = 0; i < 26; i++){for(j = 0; j < 8; j++){arr[i][j] = 0;}}
    char c; char word[8];

    int n; scanf("%d", &n); scanf("%c", &nl);    //개행 문자 처리
    for(i = 0; i < n; i++){
        len = 0;
        while((c = fgetc(stdin)) != '\n'){
            word[len++] = c;
        }
        for(j = 0; j < len; j++){
            arr[word[j] - 65][8 - len + j] += 1;    //ascii A: 65
        }
    }

    // for(i = 0; i < 26; i++){
    //     for(j = 0; j < 8; j++){
    //         printf("%d ", arr[i][j]);
    //     }printf("\n");
    // }

    for(i = 0; i < 26; i++){
        for(j = 0; j < 8; j++){
            weight = 1;
            for(k = 0; k < 7 - j; k++){
                weight *= 10;
            }
            flag[i] += (weight * arr[i][j]);
        }
    }

    qsort(flag, 26, sizeof(int), compare);
    for(i = 0; i < 10; i++){
        ans += (9 - i) * flag[i];
    }
    printf("%d", ans);


    // for(i = 0; i < 26; i++){
    //     printf("%c: %d\n", i + 65, flag[i]);
    // }
}
