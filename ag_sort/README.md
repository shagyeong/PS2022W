# ag_sort
## 프로젝트 요약
#### 프로젝트 개요
자료구조: array  
구현한 알고리즘: merge sort, quick sort  
#### 프로젝트 명세
merge sort
|속성|값|
|---|---|
|순서|오름차순|

quick sort
|속성|값|
|---|---|
|순서|오름차순|



## 프로젝트 테스트
#### make
```
$ make
gcc    -c -o main.o main.c
gcc    -c -o mergesort.o mergesort.c
gcc    -c -o quicksort.o quicksort.c
ar rs libsort.a mergesort.o quicksort.o
ar: creating libsort.a
gcc -o test main.o -L. -lsort -static
```
#### execution
```
$ ./test
mergesort
0 1 2 3 4 5 6 7 8 9 
quicksort
0 1 2 3 4 5 6 7 8 9 
```
#### make clean
```
$ make clean
rm -f main.o mergesort.o quicksort.o libsort.a test
```