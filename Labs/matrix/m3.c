#include<stdio.h>
#include<time.h>
#define TIME 10000000

int main() {
	int m,p,n;
	int A[5][5] = {{3,4,5,4,6},{4,2,1,6,9},{6,5,4,2,5},{7,6,4,7,3},{4,6,8,9,4}};
	int B[5][5] = {{2,5,7,9,5},{4,6,7,9,5},{4,5,6,7,4},{3,6,9,6,3},{3,5,7,8,6}};
	int C[5][5];
	int i,j,k,l;
	printf("two 5*5 matrixes for 10000000\n");

	for(l = 0; l < TIME; l++) {
		for(i = 0; i < 5; i++) {
			for(j = 0; j < 5; j++) {		
				C[i][j] = 0;
				for(k = 0; k < 5; k++) {
					C[i][j] += A[i][k] * B[k][j]; 
				}
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
	printf("Time: %.21f\n", (double)clock()/CLOCKS_PER_SEC);
	return 0;
}
