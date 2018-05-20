#include <stdio.h>
#include <math.h>

int main (){
	int n;
	float a=0, sum=0;
	scanf("%d",&n);
	for (int i=1; i<=n; i++){
		scanf("%f",&a);
		sum+=((i+1)%2)*powf(a,3);
	}
	printf("%f\n", sum);
	return 0;
}
