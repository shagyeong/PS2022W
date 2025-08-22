//1822: 차집합(자료 구조, 정렬, 해시를 사용한 집합과 맵, 트리를 사용한 집합과 맵)
#include<stdio.h>
void mergesort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);

int main(void){
    int a; int b; scanf("%d %d", &a, &b);
    int A[a]; for(int i = 0; i < a; i++){scanf("%d", &A[i]);}
    int B[b]; for(int i = 0; i < b; i++){scanf("%d", &B[i]);}
    mergesort(A, 0, a - 1);
    mergesort(B, 0, b - 1);

    int counter = 0; int count[a];
    int i = 0; int j = 0;
    while(i < a && j < b){
        if(A[i] == B[j]){
            count[counter++] = A[i];
            i++; j++;
        }
        else if(A[i] > B[j]){
            j++;
        }
        else{   //A[i] < B[j]
            i++;
        }
    }

    //counter: 교집합 원소 개수
    printf("%d\n", a - counter);//차집합 원소 개수
    i = 0; j = 0;
    while(i < a && j < counter){
        if(A[i] == count[j]){
            i++; j++;
        }
        else if(A[i] < count[j]){
            printf("%d ", A[i]);
            i++;
        }
    }
    while(i < a){
        printf("%d ", A[i]);
        i++;
    }
}
void mergesort(int arr[], int l, int r){
    if(l < r){
        int m = (l + r) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int left = m - l + 1;   int L[left];
    int right = r - m;      int R[right];

    for(i = 0; i < left;  i++){L[i] = arr[l + i];}
    for(j = 0; j < right; j++){R[j] = arr[m + 1 + j];}

    i = 0; j = 0; k = l;

    while(i < left && j < right){
        if(L[i] <= R[j]){
            arr[k++] = L[i++];
        }
        else{
            arr[k++] = R[j++];
        }
    }
    while(i < left){
        arr[k++] = L[i++];
    }
    while(j < right){
        arr[k++] = R[j++];
    }
}
