#include<stdio.h>
//#include "func.c"
#define M 64
#define P 256
#define N 128

void matrixmultip(int * A, int * B, int * C, int m, int p, int n);

int main() {
	int A[M][P];
	int B[P][N];
	int C[M][N];
	int i, j ,k;

	// initialize A	
	for(i = 0; i < M; i++) {
		for(j = 0; j < P; j++) {
			A[i][j] = i + j;
		}
	}
	// initialize B
	for(i = 0; i < P; i++) {
		for(j = 0; j < N; j++) {
			B[i][j] = i + j;
		}
	}

		
	// calculate
	matrixmultip(A[0], B[0], C[0], M, P, N);

	// putout
	for(i = 0; i < M; i++) {
		for(j = 0; j < N; j++) {
			printf("%d ",C[i][j]);
		}
		printf("\n");
	}	

	return 0;
}
