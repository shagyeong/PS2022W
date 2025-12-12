//1419: 등차수열의 합(수학, 애드 혹, 많은 조건 분기)
#include<stdio.h>

int main(void){
    int i, j;
    int count = 0;
    int l, r, k; scanf("%d %d %d", &l, &r, &k);
    switch(k){
        case 2:
            //k = 2: 2x d   //3 이상 자연수
            if(l >= 3){printf("%d", r - l + 1);}
            else if(r >= 3){printf("%d", r - 3 + 1);}
            else{printf("0");}
            break;
        case 3:
            //k = 3: 3x + 3d    //6 이상 3의 배수
            i = l;
            if(l >= 6){
                while(i%3 != 0){
                    i++;    //가장 가까운 6의 배수
                }
                while(i <= r){
                    count++;
                    i += 3;
                }
            }
            else if(r >= 6){
                i = 6;
                while(i <= r){
                    count++;
                    i += 3;
                }
            }
            printf("%d", count);
            break;
        case 4:
            //k = 4: 4x 6d  //10 이상, 12를 제외한 짝수
            i = l;
            if(l >= 10){
                while(i%2 != 0){
                    i++;    //가장 가까운 짝수
                }
                while(i <= r){
                    if(i == 12){
                        count--;
                    }
                    count++;
                    i += 2;
                }
            }
            else if(r >= 10){
                i = 10;
                while(i <= r){
                    if(i == 12){
                        count--;
                    }
                    count++;
                    i += 2;
                }
            }
            printf("%d", count);
            break;
        case 5:
            //k = 5: 5x 10d //5(x + 2d) 15이상 5의 배수
            i = l;
            if(l >= 15){
                while(i%5 != 0){
                    i++;    //가장 가까운 5의 배수
                }
                while(i <= r){
                    count++;
                    i += 5;
                }
            }
            else if(r >= 15){
                i = 15;
                while(i <= r){
                    count++;
                    i += 5;
                }
            }
            printf("%d", count);
            break;
    }
}
