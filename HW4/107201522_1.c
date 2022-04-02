#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include <stdbool.h>

void visit(int **grid, int i, int j, int gridSize, int gridColSize)
{
    if (i < 0 || j < 0 || i >= gridSize)
        return;
    if (j >= gridColSize)
        return;
    if (grid[i][j] == 0)
        return;
    grid[i][j] = 0;
    visit(grid, i-1, j, gridSize, gridColSize);
    visit(grid, i+1, j, gridSize, gridColSize);
    visit(grid, i, j-1, gridSize, gridColSize);
    visit(grid, i, j+1, gridSize, gridColSize);
}

int numIslands(int** grid, int gridSize, int gridColSize){
    int i, j;
    int res = 0;

    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridColSize; j++) {
            if (grid[i][j] == 1) {
                visit(grid, i, j, gridSize, gridColSize);
                res++;
            }
        }
    }
    return res;
}

int main()
{
    int i,j;
    int row,column;
    int **p=NULL;
    int island;
    int element;
    scanf("%d%d",&row,&column);

    p = (int**)malloc(sizeof(int*)*row);
    for(i=0;i<row;i++){
        p[i]=(int*)malloc(sizeof(int)*column);}

    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
            scanf("%d",&element);
            p[i][j]=element;}
        }

    island = numIslands(p,row,column);
    printf("> %d",island);

    for(i=0;i<row;i++){
        free(p[i]);}
    free(p);

    return 0;
}
