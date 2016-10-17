#include<stdio.h>

void merge(int[], int, int);
void combine(int[], int, int, int);

int main()
{
    int n, a[10], i;
    printf("Enter number of elements ");
    scanf("%d", &n);
    for (i = 0;i < n; i++)
        scanf("%d", &a[i]);
    merge(a, 0, n);
    printf("Sorted array");
    for (i = 0; i < n; i++)
        printf("%d\n", a[i]);
    return 0;
}

void merge(int a[], int low, int high)
{
    int mid;  
    if (low < high) {
        mid = (low + high) / 2;
        merge(a, low, mid);
        merge(a, mid + 1, high);
        combine(a, low, mid, high);
    }
}

void combine(int a[], int low, int mid, int high)
{
    int i, j, k;
    int temp[10];
    i = low;
    
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high) {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while (i <= mid)
        temp[k++] = a[i++];
    while (j <= high)
        temp[k++] = a[j++];
    for (k = low;k <= high; k++)
        a[k] = temp[k];
}


