#include<stdio.h>
void sortPancakes(int [], int);
void listReverse(int [], int, int);

int main(){
	int a[10], i, k, n;
	printf("How many Pancakes: ");
	scanf("%d",&n);
	printf("Enter the size of the Pancakes: ");
	for(i = 0; i < n; i++){
		scanf("%d",&a[i]);
	}
	sortPancakes(a, n);
	printf("After sorting the Pancakes: ");
	for(i = 0; i < n; i++){
		printf("%d ",a[i]);
	}
	return 0;
}


void sortPancakes(int a[], int n){
	int i, k, l = 0, r=n-1, max;
	while(r > 0){
		k = 0;
		for(i = 0; i <= r; i++){
			if(a[k] < a[i]){
				k = i;
			}
		}
		if(k == r){
			r--;
			continue;		
		}
		listReverse(a, l, k);
		listReverse(a, l, r);
		r--;
	}

}

void listReverse(int b[], int l, int r){
	int temp;
    	while (l < r)
    	{
        	temp = b[l];   
        	b[l] = b[r];
        	b[r] = temp;
        	l++;
        	r--;
    	}  

}
