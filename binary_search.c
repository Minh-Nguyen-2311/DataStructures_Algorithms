#include <stdio.h>
#include <stdbool.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bbSort(int arr[], int n)
{
    bool swap_flag;
    for(int i=0; i<n-1; i++)
    {
        swap_flag = false;
        for(int j=0; j<n-i-1; j++)
        {
            if(arr[j] < arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
                swap_flag = true;
            }
        }
        if(swap_flag == false) break;
    }
}

//Can only be applied to sort array
int binary_search(int arr[], int n, int x)
{
    int low = 0;
    int high = n-1;
    while(low <= high)
    {
        int mid = low + (high-low)/2;
        if(arr[mid] == x){
            return mid;
        }
        //Ignore left half
        if(arr[mid] < x){
            // low = mid + 1;
            high = mid - 1;
        }
        //Ignore right half
        if(arr[mid] > x){
            // high = mid - 1;
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {10,1,12,3,14,5,16,7,18,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 10;
    bbSort(arr, n);
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    int idx = binary_search(arr, n, x);
    printf("\nValue %d is at index %d", x, idx);
    return 0;
}