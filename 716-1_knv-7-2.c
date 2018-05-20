#include <stdlib.h>
#include <stdio.h>

void shell(int n, int arr[]){
	int i, j, count;
	int tmp;
	for (count = n / 2; count > 0; count /= 2){
		for (i = count; i < n; i++){
			tmp = arr[i];
			for (j = i; j >= count; j -= count){
				if (tmp < arr[j - count])
					arr[j] = arr[j - count];
				else    break;
			}
			arr[j] = tmp;
		}
	}	
}

int main(){
	int n;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	shell(n, arr);
	for (int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
