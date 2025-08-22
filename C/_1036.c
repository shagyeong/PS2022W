//1036: 36진수(수학, 구현, 그리디 알고리즘, 문자열, 임의 정밀도 / 큰 수 연산)
#include<stdio.h>
unsigned char dtot(unsigned char d);
unsigned char ttod(unsigned char t);

int main(void){
    unsigned char i, j;
    unsigned char n = 5;
    unsigned char k = 7;
    
    unsigned char ans[51] = {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'};
    unsigned char t[][51] = {
        {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'G', 'O', 'O', 'D'},
        {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'L', 'U', 'C', 'K'},
        {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'A', 'N', 'D'},
        {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'H', 'A', 'V', 'E'},
        {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'F', 'U', 'N'}
    };


    //가중치별 등장 횟수 저장
    unsigned char arr[36][51];
    for(i = 0; i <= 35; i++){for(j = 1; j <= 50; j++){arr[i][j] = 0;}}

    for(i = 0; i < n; i++){
        j = 1;
        //무의미한 '0' 스킵
        while(t[i][j] == '0'){
                j++;
        }
        while(j <= 50){
            arr[ttod(t[i][j])][j] += 1;
            j++;
        }
    }
    for(i = 0; i < 36; i++){
        printf("%c: ", dtot(i));
        for(j = 1; j <= 50; j++){
            printf("%d ", arr[i][j]);
        }printf("\n");
    }
    //





    // unsigned char i;
    // unsigned char s; //carry, sum

    // unsigned char t1[3] = {'0', 'Z', 'Z'};
    // unsigned char t2[3] = {'0', 'Z', 'Z'};
    // unsigned char ans[3] = {'0', '0', '0'};

    // for(i = 2; i >= 1; i--){
    //     s = ttod(t1[i]) + ttod(t2[i]) + ttod(ans[i]);
    //     if(s>=36){  //올림수 발생
    //         ans[i - 1] = '1';
    //         s -= 36;
    //     } 
    //     ans[i] = dtot(s);
    // }
    // for(i = 0; i < 3; i++){
    //     printf("%c", ans[i]);
    // }printf("\n");
}

//35 이하 십진수 -> 한 자리 삼십육진수
unsigned char dtot(unsigned char d){
    switch(d){
        case 0: return '0';
        case 1: return '1';
        case 2: return '2';
        case 3: return '3';
        case 4: return '4';
        case 5: return '5';
        case 6: return '6';
        case 7: return '7';
        case 8: return '8';
        case 9: return '9';
        case 10: return 'A';
        case 11: return 'B';
        case 12: return 'C';
        case 13: return 'D';
        case 14: return 'E';
        case 15: return 'F';
        case 16: return 'G';
        case 17: return 'H';
        case 18: return 'I';
        case 19: return 'J';
        case 20: return 'K';
        case 21: return 'L';
        case 22: return 'M';
        case 23: return 'N';
        case 24: return 'O';
        case 25: return 'P';
        case 26: return 'Q';
        case 27: return 'R';
        case 28: return 'S';
        case 29: return 'T';
        case 30: return 'U';
        case 31: return 'V';
        case 32: return 'W';
        case 33: return 'X';
        case 34: return 'Y';
        case 35: return 'Z';
    }
}
//한 자리 삼십육진수 -> 35 이하 십진수
unsigned char ttod(unsigned char t){
    switch(t){
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        case 'A': return 10;
        case 'B': return 11;
        case 'C': return 12;
        case 'D': return 13;
        case 'E': return 14;
        case 'F': return 15;
        case 'G': return 16;
        case 'H': return 17;
        case 'I': return 18;
        case 'J': return 19;
        case 'K': return 20;
        case 'L': return 21;
        case 'M': return 22;
        case 'N': return 23;
        case 'O': return 24;
        case 'P': return 25;
        case 'Q': return 26;
        case 'R': return 27;
        case 'S': return 28;
        case 'T': return 29;
        case 'U': return 30;
        case 'V': return 31;
        case 'W': return 32;
        case 'X': return 33;
        case 'Y': return 34;
        case 'Z': return 35;
    }
}
