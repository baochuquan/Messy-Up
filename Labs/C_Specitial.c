#include <stdio.h>
#include <time.h>


int main()
{
	time_t real_time;
	time(&real_time);
	printf("%ld\n", real_time);
	printf("%s \n", ctime(&real_time));
	printf("UTC\n");
	printf("%s \n", asctime(gmtime(&real_time)));
	return 0;
}
