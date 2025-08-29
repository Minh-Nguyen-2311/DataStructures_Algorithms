#include "stdio.h"
#include "stdint.h"

//Time complexity: O(n^2)
//Space complexity: O(1)

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void selectionSort(int a[], int n)
{
	for(int i=0; i<n-1; i++){
		//Swap the first scan smallest to a[0]
		int min_idx = i;
		//Compare a[0] to &a[1]->&a[n-1] to find the actual smallest
		for(int j=i+1; j<n; j++){
		    //Move smallest to the front
		    //Move biggest to the front: a[j] > a[min_idx]
			if(a[j] < a[min_idx]){
				min_idx = j;
			}
		}
		//Move smallest to correct pos
		swap(&a[i], &a[min_idx]);
	}
}

void ReverseSelectionSort(int a[], int n)
{
	for(int i=0; i<n-1; i++){
		//Swap the first scan smallest to a[0]
		int min_idx = i;
		//Compare a[0] to &a[1]->&a[n-1] to find the actual smallest
		for(int j=n-1; j>i; j--){
		    //Move smallest to the front
		    //Move biggest to the front: a[j] > a[min_idx]
			if(a[j] < a[min_idx]){
				min_idx = j;
			}
		}
		//Move smallest to correct pos
		swap(&a[i], &a[min_idx]);
	}
}

int main()
{
    int a[] = {10,1,12,3,14,5,16,7,18,9};
    int n = sizeof(a)/sizeof(a[0]);
    //selectionSort(a,n);
    ReverseSelectionSort(a,n);
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}