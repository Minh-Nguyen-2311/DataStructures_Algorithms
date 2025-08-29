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

void bbSort(int arr[], int n)
{
	int i,j;
	bool swap_flg;
	for(int i=0; i<n-1; i++){
		swap_flg = false;
		for(int j=0; j<n-i-1; j++){
			//Move the smallest element each scan to the back
			//Smallest to front: arr[j] > arr[j+1]
			if(arr[j] < arr[j+1]){
				swap(&arr[j], &arr[j+1]);
				swap_flg = true;
			}
		}
		//Break if no element is swapped by inner loop
		if(swap_flg == false){
			break;
		}
	}
}

void reversebbSort(int arr[], int n)
{
    int i,j;
    bool swap_flag;
    for(int i=0; i<n-1; i++){
        swap_flag = false;
        for(int j=n-1; j>i; j--){
            //Move the smallest element each scan to the front
			//Smallest to back: arr[j-1] > arr[j]
            if(arr[j-1] < arr[j]){
                swap(&a[j-1], &a[j]);
                swap_flag = true;
            }
        }
        if(!swap_flag) break;
    }
}

int main()
{
	int arr[] = {10,1,12,3,14,5,16,7,18,9};
	int n = sizeof(arr)/sizeof(arr[0);
	bbSort(arr, n);
}