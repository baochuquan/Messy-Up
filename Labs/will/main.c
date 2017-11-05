#include <stdio.h>
#include <sys/time.h>
int cal_matrix(int *m1,int m1_h, int m1_w,
			   int *m2,int m2_h, int m2_w, int *m3);
int main(int argc, char const *argv[])
{
	struct timeval start,end; 
	int a[255][200];
	int b[200][255];
	int c[255][255]={0};
	int d;
	d=100;
	int i,j,count;
	for(i=0;i<255;i++)
		for(j=0;j<200;j++)
			a[i][j] = j+1;
	for(i=0;i<200;i++)
		for(j=0;j<255;j++)
			b[i][j]=j+1;
	gettimeofday(&start, NULL);
	cal_matrix((int*)a,255,200,(int*)b,200,255,(int*)c);
	gettimeofday(&end, NULL);
	long timeuse =1000000 * ( end.tv_sec - start.tv_sec )
				 + end.tv_usec - start.tv_usec;
	// for(i = 0;i<255;i++)
	// {
	// 	printf("%d",c[i][0]);
	// 	for(j = 1;j<255;j++)
	// 		printf(" %d",c[i][j]);
	// 	printf("\n");
	// }
	printf("%ld\n", timeuse);
	return 0;
}

