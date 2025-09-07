#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r)
{
	int i,j,k;
	int left = m - l + 1;
	int right = r - m;
	
	//Create temp array
	int L[left], R[right];
	
	//Copy data to temp arrays L[] and R[]
	for(i=0; i<left; i++)
	{
		L[i] = arr[l+i];
	}
	for(j=0; j<right; j++)
	{
		R[j] = arr[m+j+1];
	}
	
	//Merge the temp array back to arr[l..r], index start at k
	i=0;
	j=0;
	k=l;
	while(i<left && j<right)
	{
		//Put in smaller value into arr[]
		if(L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	
	//Copy the remaining elements of L[]
	while(i<left){
		arr[k] = L[i];
		i++;
		k++;
	}
	
	//Copy the remaining elements of R[]
	while(j<right){
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int r){
    
    if (l < r) {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main()
{
    int arr[] = {10,1,12,3,14,5,16,7,18,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr, 0, n-1);
    for(int i=0; i<n; i++){
        printf("%d\n", arr[i]);
    }
    return 0;
}