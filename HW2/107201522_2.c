#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 10
int  queue[MAX_QUEUE_SIZE];
int rear=0;
int front=0;
int isFull();
int isEmpty();
void addq();
void dequeue();
void printQueuefront();

int isFull(){
    return rear==MAX_QUEUE_SIZE-1;
}

int isEmpty(){
    return front==rear;
}

void addq(int item)
{
    if(rear==MAX_QUEUE_SIZE-1){
        isFull();}
    else{
    queue[rear++]=item;}
}

void printQueuefront()
{
    if(isEmpty()){
        printf(" -2");}
    else{
        printf(" %d",queue[front]);}
}

void dequeue()
{
    if(isEmpty()){
        printf(" -3");}
    else{
        queue[front++];}
}

int main()
{
    int num,read,count;
    int operation[100][2];
    for(int i=0;i<100;i++){
        int j=0;
        scanf("%d",&num);
        if(num==-1){
            count=i;
            break;}
        operation[i][j]=num;
        if(num==1){
        scanf("%d",&read);
        operation[i][j+1]=read;}
        }
    printf(">");
    for(int i=0;i<count;i++){
        int j=0;
        if(operation[i][j]==1){
            addq(operation[i][j+1]);}
        if(operation[i][j]==2){
            printQueuefront();}
        if(operation[i][j]==3){
            dequeue();}
        if(operation[i][j]==-1){
            break;}
        }
    return 0;
}
