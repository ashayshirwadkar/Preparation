#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>

void bubble(int *a,int n)
{
	int i,j,k=n,temp;
	int flag = 0;

	for(i=0;i<n-1;i++) {
		flag = 0;
		for(j=0;j<n-i;j++) 
			if(*(a+j)>a[j+1]) {
				flag = 1;
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		if(flag == 0)
			break;
		k--;
	}
	for(i=0;i<n;i++)
		printf("%d\n",a[i]);
}

int main()
{
	int arr[10],n,i;
	struct timeval before, after;

	gettimeofday(&before, NULL);
	/* arr=(int *)malloc(10*(sizeof(int))); */
	n = 10;
	for( i=0;i<n;i++)
		arr[i] = n - i;
	bubble(arr,n);
	gettimeofday(&after, NULL);
	
	printf("Time in us: %ld\n", (after.tv_sec * 1000000)+after.tv_usec - (before.tv_sec * 1000000 + before.tv_usec));

	// getch();
	return 0;
}

