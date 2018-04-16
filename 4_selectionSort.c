#include<stdio.h>
void selectionSort(int [], int, int);
int findMin(int [], int, int);

int main(){
	int a[20], i, j, n, k;
	printf("Enter the size of the list: ");
	scanf("%d", &n);
	printf("Enter the value of k: ");
	scanf("%d", &k);
	printf("Enter the elements of the list: ");
	for(i = 0; i < n ; i++){
		scanf("%d", &a[i]);
	}
	selectionSort(a, n, k);
	printf("The sorted list is: ");
	for(i = 0; i < n; i++){
		printf("%d ",a[i]);
	}
	return 0;
}

void selectionSort(int a[], int n, int k){
	int i, j, mi, temp;
	for(i = 0; i < k; i++){
		mi = findMin(a, i, n-1);
		temp = a[i];
		a[i] = a[mi];
		a[mi] = temp;	
	}
}

int findMin(int a[], int l, int r){
	int i, minIndex = l;
	for(i = l+1; i <= r; i++){
		if(a[minIndex] > a[i]){
			minIndex = i;		
		}
	}
	return minIndex;
}
