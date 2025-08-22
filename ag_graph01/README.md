# ag_graph01
## 프로젝트 요약
#### 프로젝트 개요
자료구조: 그래프  
구현한 알고리즘: DFS, BFS  
#### 프로젝트 명세
그래프
|속성|값|
|---|---|
|방향|undirected|
|가중치|unweighted|
|표현 기법|adjacency list|



## 프로젝트 테스트
#### make
```
$ make
gcc    -c -o main.o main.c
gcc    -c -o graphinit.o graphinit.c
gcc    -c -o visitinit.o visitinit.c
gcc    -c -o printgraph.o printgraph.c
gcc    -c -o insert.o insert.c
gcc    -c -o dfs.o dfs.c
gcc    -c -o bfs.o bfs.c
ar rs libgraph.a graphinit.o visitinit.o printgraph.o insert.o dfs.o bfs.o
ar: creating libgraph.a
gcc -o test main.o -L. -lgraph -static
```
#### execution
```
$ ./test
printgraph
node 0: 
node 1: 2 5 
node 2: 1 3 4 
node 3: 2 4 6 7 
node 4: 2 3 
node 5: 1 8 9 
node 6: 3 
node 7: 3 
node 8: 5 
node 9: 5 

dfs
1 2 3 4 6 7 5 8 9 

bfs
depth 0: 1
depth 1: 2 5 
depth 2: 3 4 8 9 
depth 3: 6 7 
depth 4: 
```
#### make clean
```
$ make clean
rm -f main.o graphinit.o visitinit.o printgraph.o insert.o dfs.o bfs.o libgraph.a test
```
