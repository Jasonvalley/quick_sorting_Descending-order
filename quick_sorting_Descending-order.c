#include<stdio.h>
#include<stdlib.h>
int t;
#define SWAP(a,b) t=a;a=b;b=t;
FILE *getfile(void);
void quicksort(int low, int high);
int partition(int low, int high);
int *list;
int main(void) {
	//get data
	FILE *fin = getfile();
	int n;
	fscanf(fin, "%d\n", &n);
	list = (int*)malloc(sizeof(int)*(n+1));
	int i;
	for (i = 1; i <= n; i++) {
		fscanf(fin, "%d ", &list[i]);
		printf("%d ", list[i]);
	}
	//sort
	quicksort(1, n);
	//print
	FILE *fout = fopen("Output.txt","w");
	for(i = 1; i <= n; i++) {
		fprintf(fout, "%d ", list[i]);
		//debug
		printf("%d ", list[i]);
	}
}
FILE *getfile(void) {
	char filename[30];
	printf("Input File Name?");
	scanf("%s", filename);
	FILE *f = fopen(filename, "r");
	return f;
}
void quicksort(int low, int high)
{
	int pivotpoint=high;
	if (high > low) {
		pivotpoint=partition(low, high);
		quicksort(low, pivotpoint-1);
		quicksort(pivotpoint+1, high);
	}
	else {
		return;
	}
}
int partition(int low, int high)
{
	int i = high - 1;
	int j = high;
	int pivotitem = list[high];
	for (; i>=low; i--) {
		if (list[i] < pivotitem) {
			j--; SWAP(list[j], list[i]);
		}
	}
	SWAP(list[j], list[high]);
	return j;
}
