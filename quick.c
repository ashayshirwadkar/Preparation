#include<stdio.h>

#define SIZE 10
void quick(int[],int,int);
int partition(int [],int,int);
void swap(int [],int,int);


int main()
{
  int i,n,a[SIZE];
  printf("Enter number of elements");
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  printf("Sorted Array \n");
  quick(a,0,n-1);
  for(i=0;i<n;i++)
    printf("%d\n",a[i]);
  return 0;
}

void quick(int a[SIZE],int low,int high)
{
  int mid;
  if(low<high) {
    mid=partition(a,low,high);
    quick(a,low,mid-1);
    quick(a,mid+1,high);
  }
}

int partition(int a[SIZE],int low,int high)
{
  int pivot,i=low,j=high;
  pivot=a[low];
  while(i<=j) {
    while(a[i]<=pivot)
      i++;
    while(a[j]>pivot)
      j--;
    if(i<j)
      swap(a,i,j);
  }
  swap(a,low,j);
  return j;
}

void swap(int a[SIZE],int i,int j)
{
  int temp;
  temp=a[i];
  a[i]=a[j];
  a[j]=temp;
}
