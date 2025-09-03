#include <stdio.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int arr[], int low, int high)
{
    //Select first idx value as pivot (Optional)
    int pivot = arr[low];
    swap(&arr[low], &arr[high]);
    
    //Select middle idx value as pivot (Optional)
    // int mid = (high-low)/2 + low;
    // int pivot = arr[mid];
    // swap(&arr[mid], &arr[high]);
    
    //Select last idx value as pivot (Default)
    //int pivot = arr[high];
    
    //Initialize index pointer to -1
    int i = low-1;
    //Scan from arr[0..n-1] for smaller value compared to pivot
    for(int j=low; j<high; j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    
    swap(&arr[i+1], &arr[high]);
    return i+1;
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int pivot_idx = partition(arr, low, high);
        quickSort(arr, low, pivot_idx-1);
        quickSort(arr, pivot_idx+1, high);
    }
}

int main()
{
    int arr[] = {10,1,12,3,14,5,16,7,18,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    for(int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}