#include <stdio.h> 
int main() 
{ 
	int max, x, n; 
	scanf("%d", &n); 
	scanf("%d", &max); 
	for(int i=0;i<(n-1);i++) 
	{ 
		scanf("%d", &x); 
		if(x>=max){max=x;} 
	}; 
	printf ("%d\n", max); 
	return 0; 
}
