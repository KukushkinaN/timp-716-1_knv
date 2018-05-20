#include <stdio.h>
#include <stdlib.h>

void combSort(int n, int arr[]){
	int count = n-1, c;
	while(count >= 1){
		for(int i=0; i < n-count; i++){
			if(arr[i] > arr[i+count]){
				c = arr[i];
				arr[i] = arr[i+count];
				arr[i+count] = c;
			}
		}		
		count--;
	}
}

int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	combSort(n,arr);
	for(int i=0;i<n;i++){
		printf("%d ", arr[i]);
	}
	printf ("\n");
	return 0;
}


