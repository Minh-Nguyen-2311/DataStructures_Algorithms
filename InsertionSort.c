#include "stdio.h"

void insertionSort(int arr[], int n)
{
	int i,j,key;
	for(int i=1; i<n; ++i)
	{
		//Considered arr[0] sorted
		//Started from arr[1]
		key = arr[i];
		//Move elements from arr[0..n-1] smaller than key
		j = i-1;
		while(j>=0 && arr[j]<key)
		{
			//Scan backward through the array
			arr[j+1] = arr[j];
			j--;
		}
		//Place new key value
		arr[j+1] = key;
	}
}

int main()
{
	int a[] = {10,1,12,3,14,5,16,7,18,9};
	int n = sizeof(a)/sizeof(a[]);
	insertionSort(a,n);
	for(int i=0; i<n; i++){
		printf("%d ", a[i]);
	}
	return 0;
}