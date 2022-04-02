#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include <limits.h>
#include <stdbool.h>

int minKey(int key[], bool mstSet[],int V)
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}

int printMST(int parent[], int** graph,int V)
{
	int minimumcost=0;
	for (int i = 1; i < V; i++){
		minimumcost=minimumcost+graph[i][parent[i]];}
    printf("> %d",minimumcost);
}

void primMST(int** graph,int V)
{
	int parent[V];
	int key[V];
	bool mstSet[V];

	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	key[0] = 0;
	parent[0] = -1;

	for (int count = 0; count < V - 1; count++) {

		int u = minKey(key, mstSet,V);
		mstSet[u] = true;

		for (int v = 0; v < V; v++)

			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}
	printMST(parent, graph,V);
}

int main()
{
	int i,j;
    int V;
    int **graph=NULL;
    int element;
    int count=0;
    bool p=true;
    scanf("%d",&V);

    graph = (int**)malloc(sizeof(int*)*V);
    for(i=0;i<V;i++){
        graph[i]=(int*)malloc(sizeof(int)*V);}

    for(i=0;i<V;i++){
        for(j=0;j<V;j++){
            scanf("%d",&element);
            graph[i][j]=element;}
        }

     for(i=0;i<V;i++){
        for(j=0;j<V;j++){
            if(graph[i][j]==0){
                count++;};}
        if(count>V-2){p=false;}
        count=0;
        }
    if(p==false){printf("> NO connected");}
    if(p==true){primMST(graph,V);}

    for(i=0;i<V;i++){
        free(graph[i]);}
    free(graph);

	return 0;
}

