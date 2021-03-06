#include<stdio.h>
#define MAXSIZE 1000	
static int C[MAXSIZE][MAXSIZE];
int i,j,k;

void matrixMultiplication(int * A, int * B, int m, int p, int n) {
	for(i = 0; i < m; i++) {
		for(j = 0; j < n; j++) {
			
			for(k = 0; k < p; k++) {
				C[i][j] += A[i * MAXSIZE + k] * B[k * MAXSIZE + j]; 
			}

		}
	} 	
}

int main() {
	int m,p,n;
	int A[MAXSIZE][MAXSIZE];
	int B[MAXSIZE][MAXSIZE];
	printf("Please input the scale of two matrixes: ");
	scanf("%d %d %d", &m, &p, &n);
	printf("A[%d][%d]:\n", m, p);
	for(i = 0; i < m; i++) {
		for(j = 0; j < p; j++) {
			scanf("%d",&A[i][j]);
		}
	}
	printf("B[%d][%d]:\n", p, n);
	for(i = 0; i < p; i++) {
		for(j = 0; j < n; j++) {
			scanf("%d",&B[i][j]);
		}
	}

	matrixMultiplication(A, B, m, p, n);
	
	printf("Result:\n");
	for(i = 0; i < m; i++) {
		for(j = 0; j < n; j++) {
			printf("%d ",C[i][j]);
		}
		printf("\n");
	}
	return 0;
}
