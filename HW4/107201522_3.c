#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include <limits.h>
#include <stdbool.h>
// Kruskal's algorithm in C

#include <stdio.h>

#define MAX 30

typedef struct edge {
  int u, v, w;
} edge;

typedef struct edge_list {
  edge data[MAX];
  int n;
} edge_list;

edge_list elist;

int Graph[MAX][MAX], n;
edge_list spanlist;

void kruskalAlgo();
int find(int belongs[], int vertexno);
void applyUnion(int belongs[], int c1, int c2);
void sort();
void print();

// Applying Krushkal Algo
void kruskalAlgo() {
  int belongs[MAX], i, j, cno1, cno2;
  elist.n = 0;

  for (i = 1; i < n; i++)
    for (j = 0; j < i; j++) {
      if (Graph[i][j] != 0) {
        elist.data[elist.n].u = i;
        elist.data[elist.n].v = j;
        elist.data[elist.n].w = Graph[i][j];
        elist.n++;
      }
    }

  sort();

  for (i = 0; i < n; i++)
    belongs[i] = i;

  spanlist.n = 0;

  for (i = 0; i < elist.n; i++) {
    cno1 = find(belongs, elist.data[i].u);
    cno2 = find(belongs, elist.data[i].v);

    if (cno1 != cno2) {
      spanlist.data[spanlist.n] = elist.data[i];
      spanlist.n = spanlist.n + 1;
      applyUnion(belongs, cno1, cno2);
    }
  }
}

int find(int belongs[], int vertexno) {
  return (belongs[vertexno]);
}

void applyUnion(int belongs[], int c1, int c2) {
  int i;

  for (i = 0; i < n; i++)
    if (belongs[i] == c2)
      belongs[i] = c1;
}

// Sorting algo
void sort() {
  int i, j;
  edge temp;

  for (i = 1; i < elist.n; i++)
    for (j = 0; j < elist.n - 1; j++)
      if (elist.data[j].w > elist.data[j + 1].w) {
        temp = elist.data[j];
        elist.data[j] = elist.data[j + 1];
        elist.data[j + 1] = temp;
      }
}

// Printing the result
void print() {
  int i, cost = 0;

  for (i = 0; i < spanlist.n; i++) {
    cost = cost + spanlist.data[i].w;
  }

  printf("> %d", cost);
}

int main()
{
    int a,b;
    int i,j,total_cost;
    int input1,input2,edge;
    int V;
    int edgesCount;
    int count=0;
    bool k=true;

    scanf("%d%d",&V,&edgesCount);
    int graph[V][V];
    for(a=0;a<V;a++){
        for(b=0;b<V;b++){
           graph[a][b]=0;}
        }

    for(a=0;a<edgesCount;a++){
            scanf("%d",&input1);
            scanf("%d",&input2);
            scanf("%d",&edge);
            graph[input1][input2]=edge;
            graph[input2][input1]=edge;}

    for(a=0;a<V;a++){
        for(b=0;b<V;b++){
            if(graph[a][b]==0){
                count++;};}
        if(count>V-2){k=false;}
        count=0;
        }

    if(k==false){printf("> NO connected");}
    if(k==true){
             for(a=0;a<V;a++){
                for(b=0;b<V;b++){
                    Graph[a][b] = graph[a][b];}
                    }
            n=V;
            kruskalAlgo();
            print();}

    printf("\n");

    for(a=0;a<V;a++){
        printf("%d",graph[a][0]);
        for(b=1;b<V;b++){
            printf(" %d",graph[a][b]);}
            printf("\n");
        }

    return 0;
}
