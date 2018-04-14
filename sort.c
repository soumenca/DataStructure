#include<stdio.h>
void bubbleSort(int [], int);
void insertionSort(int [], int);
//void selectionSort(int [], int);

int main(){
	int a[10],n,i,j, temp;
	printf("Enter the value of n: ");
	scanf("%d",&n);
	printf("Enter the values of the array: ");
	for(i = 0; i < n; i++){
		scanf("%d",&a[i]);	
	}
	bubbleSort(a, n);
	insertionSort(a, n);

	printf("The list contain: ");
	for(i = 0; i < n; i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}
void insertionSort(int a[], int n){
	int i, j, temp;
	for(i = 1; i < n; i++){
		temp = a[i];
		for(j = i; j > 0; j--){
			if(temp < a[j-1]){
				a[j] = a[j-1];
			}
			else{
				a[j] = temp;
				break;
			}
		}
		
	}
	printf("The list contain after insertion sort: ");
	for(i = 0; i < n; i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}


void bubbleSort(int a[], int n){
	int i, j, temp;	
	for(i = 0; i < n-1; i++){
		for(j = 0; j < n-1-i; j++){
			if(a[j] > a[j+1]){
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
	printf("The list contain after bubble sort: ");
	for(i = 0; i < n; i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}
