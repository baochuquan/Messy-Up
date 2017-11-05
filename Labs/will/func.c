int cal_matrix(int *m1,int m1_h, int m1_w,
			   int *m2,int m2_h, int m2_w, int *m3)
{
	int i,j,k;
	for(i=0;i<m1_h;i++)
		for(j=0;j<m2_w;j++)
			for(k=0;k<m1_w;k++)
			{
				*(m3+i*m2_w+j)=(*(m3+i*m2_w+j))+(*(m1+i*m1_w+k))*(*(m2+k*m2_w+j));
			}
}