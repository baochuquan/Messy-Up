void matrixmultip(int * A, int * B, int * C, int m, int p, int n) {
	int i, j, k;
	for(i = 0; i < m; i++) {
		for(j = 0; j < n; j++) {
			*C = 0;
			for(k = 0; k < p; k++) {
				*(C + i*m + j) += (*(A + i*m + k)) * (*(B + k * n + j));
			}
		}
	}		
}
