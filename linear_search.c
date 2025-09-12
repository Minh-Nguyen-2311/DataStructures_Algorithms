#include <stdio.h>

int linear_search(int arr[], int n, int x)
{
    for(int i=0; i<n-1; i++)
    {
        if(arr[i] == x)
        {
            return i;
        }
        else return -1;
    }
}

int main()
{
    int arr[] = {10,1,12,3,14,5,16,7,18,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 10;
    int idx = linear_search(arr, n, x);
    printf("\nValue %d is at index %d", x, idx);
    return 0;
}