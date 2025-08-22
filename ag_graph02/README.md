# ag_graph02
## 프로젝트 요약
#### 프로젝트 개요
자료구조: 그래프  
구현한 알고리즘: Dijkstra
#### 프로젝트 명세
그래프
|속성|값|
|---|---|
|방향|undirected|
|가중치|weighted|
|표현 기법|adjacency list|



## 프로젝트 테스트
#### make
```
$ make
gcc    -c -o main.o main.c
gcc    -c -o graphinit.o graphinit.c
gcc    -c -o visitinit.o visitinit.c
gcc    -c -o dijkstra.o dijkstra.c
gcc    -c -o insert.o insert.c
gcc    -c -o distanceinit.o distanceinit.c
gcc    -c -o printgraph.o printgraph.c
ar rs libgraph.a graphinit.o visitinit.o dijkstra.o insert.o distanceinit.o printgraph.o
ar: creating libgraph.a
gcc -o test main.o -L. -lgraph -static
```
#### execution
```
$ ./test
node 0's adjs: 

node 1's adjs: 
node 3: weight 2
node 2: weight 4
node 4: weight 7

node 2's adjs: 
node 1: weight 1
node 3: weight 5

node 3's adjs: 
node 1: weight 2
node 4: weight 4

node 4's adjs: 
node 2: weight 3

node 5's adjs: 

node 6's adjs: 

node 7's adjs: 

node 8's adjs: 

node 9's adjs: 

0 distance: 32767
1 distance: 0
2 distance: 4
3 distance: 2
4 distance: 6
5 distance: 32767
6 distance: 32767
7 distance: 32767
8 distance: 32767
9 distance: 32767
```
#### make clean
```
$ make clean
rm -f main.o graphinit.o visitinit.o dijkstra.o insert.o distanceinit.o printgraph.o libgraph.a test
```
