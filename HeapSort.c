#include <stdio.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify(int arr[], int n, int r)
{
    //Initialize largest as root
    int largest = r;
    
    //Left index
    int left = 2*r+1;
    
    //Right index
    int right = 2*r+2;
    
    //If left child is larger than root
    if(left<n && arr[left]>arr[largest])
    {
        largest = left;
    }
    
    //If right child is larger than root
    if(right<n && arr[right]>arr[largest])
    {
        largest = right;
    }
    
    //If largest is not root
    if(largest != r)
    {
        swap(&arr[largest], &arr[r]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    // Build heap where root == largest value
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {

        // Move current root to end
        swap(&arr[0], &arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main()
{
    int arr[] = {10,1,12,3,14,5,16,7,18,9,20,11,22,13};
    int n = sizeof(arr)/sizeof(arr[0]);
    heapSort(arr, n);
    for(int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}