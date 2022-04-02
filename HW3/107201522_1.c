#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include <stdbool.h>

#define MAX_TREE_HT 100

struct MinHeapNode {
	char data;
	unsigned freq;
	struct MinHeapNode *left, *right;
};
struct MinHeap {
	unsigned size;
	unsigned capacity;
	struct MinHeapNode** array;
};
struct MinHeapNode* newNode(char data, unsigned freq)
{
	struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));

	temp->left = temp->right = NULL;
	temp->data = data;
	temp->freq = freq;
	return temp;
}
struct MinHeap* createMinHeap(unsigned capacity)
{
	struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
	minHeap->size = 0;
	minHeap->capacity = capacity;
	minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));
	return minHeap;
}

void swapMinHeapNode(struct MinHeapNode** a,struct MinHeapNode** b)
{
	struct MinHeapNode* t = *a;
	*a = *b;
	*b = t;
}

void minHeapify(struct MinHeap* minHeap, int idx)
{
	int smallest = idx;
	int left = 2 * idx + 1;
	int right = 2 * idx + 2;
	if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
		smallest = left;
	if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
		smallest = right;
	if (smallest != idx) {
		swapMinHeapNode(&minHeap->array[smallest],&minHeap->array[idx]);
		minHeapify(minHeap, smallest);
	}
}

int isSizeOne(struct MinHeap* minHeap)
{
	return (minHeap->size == 1);
}

struct MinHeapNode* extractMin(struct MinHeap* minHeap)
{
	struct MinHeapNode* temp = minHeap->array[0];
	minHeap->array[0] = minHeap->array[minHeap->size - 1];
	--minHeap->size;
	minHeapify(minHeap, 0);
	return temp;
}

void insertMinHeap(struct MinHeap* minHeap,struct MinHeapNode* minHeapNode)
{
	++minHeap->size;
	int i = minHeap->size - 1;
	while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
		minHeap->array[i] = minHeap->array[(i - 1) / 2];
		i = (i - 1) / 2;
	}
	minHeap->array[i] = minHeapNode;
}

void buildMinHeap(struct MinHeap* minHeap)
{
	int n = minHeap->size - 1;
	int i;
	for (i = (n - 1) / 2; i >= 0; --i)
		minHeapify(minHeap, i);
}

#define MAX_QUEUE_SIZE 2
int code_a[MAX_QUEUE_SIZE];
int reara=0;
int fronta=0;
int code_b[MAX_QUEUE_SIZE];
int rearb=0;
int frontb=0;
int code_c[MAX_QUEUE_SIZE];
int rearc=0;
int frontc=0;

void adda(int arr)
{
    code_a[reara++]=arr;
}
void addb(int arr)
{
    code_b[rearb++]=arr;
}
void addc(int arr)
{
    code_c[rearc++]=arr;
}

void printa()
{
    for(int i=0;i<reara;i++){
    printf("%d",code_a[i]);}
}
void printb()
{
    for(int i=0;i<rearb;i++){
    printf("%d",code_b[i]);}
}
void printc()
{
    for(int i=0;i<rearc;i++){
    printf("%d",code_c[i]);}
}

void printArr(char root,int arr[], int n)
{
	int i;
	for(i=0;i<n;i++){
        if(root=='a'){
        adda(arr[i]);}
        if(root=='b'){
        addb(arr[i]);}
        if(root=='c'){
        addc(arr[i]);}
	}
}

// Utility function to check if this node is leaf
int isLeaf(struct MinHeapNode* root)
{
	return !(root->left) && !(root->right);
}

struct MinHeap* createAndBuildMinHeap(char data[],int freq[], int size)
{
	struct MinHeap* minHeap = createMinHeap(size);
	for (int i = 0; i < size; ++i)
		minHeap->array[i] = newNode(data[i], freq[i]);
	minHeap->size = size;
	buildMinHeap(minHeap);
	return minHeap;
}

struct MinHeapNode* buildHuffmanTree(char data[],int freq[], int size)
{
	struct MinHeapNode *left, *right, *top;
	struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);
	while (!isSizeOne(minHeap)) {
		left = extractMin(minHeap);
		right = extractMin(minHeap);

		top = newNode('$', left->freq + right->freq);
		top->left = left;
		top->right = right;
		insertMinHeap(minHeap, top);
	}
	return extractMin(minHeap);
}

void printCodes(struct MinHeapNode* root, int arr[],int top)
{
	if (root->left) {
		arr[top] = 0;
		printCodes(root->left, arr, top + 1);
	}
	if (root->right) {
		arr[top] = 1;
		printCodes(root->right, arr, top + 1);
	}
	if (isLeaf(root)) {
        printArr(root->data,arr,top);}
}

void HuffmanCodes(char data[], int freq[], int size)
{
	struct MinHeapNode* root = buildHuffmanTree(data, freq, size);
	int arr[MAX_TREE_HT], top = 0;
	printCodes(root,arr,top);
}

int main()
{
    char input;
    int i=0;
    char plaintext[100];
    int counta=0,countb=0,countc=0;
    while(scanf("%c",&input)!=EOF){
        if(input=='a'){
            plaintext[i]='a';
            counta++;}
        if(input=='b'){
            plaintext[i]='b';
            countb++;}
        if(input=='c'){
            plaintext[i]='c';
            countc++;}
        if(input==' '){
            plaintext[i]=' ';}
            i++;}

	char arr[] = {'a','b','c'};
	int freq[] = {counta,countb,countc};

	int size = sizeof(arr) / sizeof(arr[0]);
	HuffmanCodes(arr,freq,size);

	int total=counta+countb+countc;
	printf("> ");
    for(int i=0;i<total;i++){
        if(plaintext[i]=='a'){
            printa();}
        if(plaintext[i]=='b'){
            printb();}
        if(plaintext[i]=='c'){
            printc();}
        if(plaintext[i]==' '){
            printf(" ");}
    }
    printf("\n");

	int counting[3];
	counting[0]=counta;
	counting[1]=countb;
	counting[2]=countc;
    if(counting[0]<counting[1]){
        int temp=counting[0];
        counting[0]=counting[1];
        counting[1]=temp;}
    if(counting[2]>counting[0]){
            counting[0]=counting[2];}
    int sum=counting[0]*1+counting[1]*2+counting[2]*2;
    printf("> %d",sum);

	return 0;
}
