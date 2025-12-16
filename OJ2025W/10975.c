//10975: 데크 소트(구현, 그리디 알고리즘, 정렬)
//정렬된 상태에 원소와 인덱스 매핑
//원소로 인덱스를 찾는 이분 탐색 구현
//삽입하면 마크, 인접 인덱스에 마크가 되어있지 않다면 데크 개수 추가
#include<stdio.h>
void mergesort(short arr[], short l, short r);
void merge(short arr[], short l, short m, short r);
short search(short arr[], short len, short i);

int main(void){
    short ans;
    short i, j;
    short n; scanf("%hd", &n);
    
    short index[n];     //삽입 여부 마크
    short input[n];
    short sorted[n];

    for(i = 0; i < n; i++){
        scanf("%hd", &j);
        index[i] = 0;
        input[i] = j;
        sorted[i] = j;
    }
    mergesort(sorted, 0, n - 1);

    ans = 1;
    j = search(sorted, n, input[0]);
    index[j] = 1;
    for(i = 1; i < n; i++){
        j = search(sorted, n, input[i]);
        index[j] = 1;
        if(j == 0){if(index[1] == 0){ans++;}}
        else if(j == n - 1){if(index[n - 2] == 0){ans++;}}
        else{if(index[j - 1] == 0 && index[j + 1] == 0){ans++;}}
    }
    printf("%hd", ans);
}
void mergesort(short arr[], short l, short r){
    if(l < r){
        short m = (l + r) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }    
}
void merge(short arr[], short l, short m, short r){
    short i, j, k;
    short left = m - l + 1;
    short right = r - m;
    short L[left];for(i = 0; i < left; i++){L[i] = arr[l + i];}
    short R[right]; for(i = 0; i < right; i++){R[i] = arr[m + 1 + i];}
    i = 0; j = 0; k = l;
    while(i < left && j < right){
        if(L[i] < R[j]){arr[k++] = L[i++];}
        else{arr[k++] = R[j++];}
    }
    while(i < left){arr[k++] = L[i++];}
    while(j < right){arr[k++] = R[j++];}
}

short search(short arr[], short len, short i){
    short l = 0; short r = len - 1;
    if(i > arr[r] || i < arr[l]){
        return -1;
    }
    short index = len / 2;
    while(index - l > 0 && r -index > 0){
        if(i == arr[index]){
            return index;
        }
        else if(i < arr[index]){
            r = index;
            index = (l + index) / 2;
        }
        else{
            l = index;
            index = (index + r) / 2;
        }
    }
    for(short j = l; j <= r; j++){
        if(i == arr[j]){
            return j;
        }
    }
    return -1;
}
