#include<stdio.h>

int main() {
	int m,p,n;
	int A[5][5];
	int B[5][5];
	int C[5][5];
	int i,j,k;
	printf("Please input two 5*5  matrixes: ");
	printf("A[5][5]:\n");
	for(i = 0; i < 5; i++)
		for(j = 0; j < 5; j++)
			scanf("%d",&A[i][j]);

	printf("B[5][5]:\n");
	for(i = 0; i < 5; i++) 
		for(j = 0; j < 5; j++) 
			scanf("%d",&B[i][j]);

	for(i = 0; i < 5; i++) {
		for(j = 0; j < 5; j++) {		
			C[i][j] = 0;
			for(k = 0; k < 5; k++) {
				C[i][j] += A[i][k] * B[k][j]; 
			}
		}
	} 
	
	printf("Result:\n");
	for(i = 0; i < 5; i++) {
		for(j = 0; j < 5; j++) {
			printf("%d ",C[i][j]);
		}
		printf("\n");
	}
	return 0;
}
