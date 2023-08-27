#include <stdio.h>

int partition(int arr[], int low, int high){
    int i = low-1;
    int pivot = arr[high];

    for(int j = low; j<=high;j++){
        if(arr[j]<pivot){
            i++;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    i++;
    int temp = arr[i];
    arr[i] = pivot;
    arr[high] = temp;

    return i;
}

void quickSort(int arr[], int low, int high){

    if(low<high){
        int pidx = partition(arr, low,high);
        quickSort(arr, low, pidx-1);
        quickSort(arr, pidx+1, high);
    }
    return;
}


int main(void){
    int arr[] = {1,2,10,3,11,23,0};
    int n = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr,0,n-1);

    for(int i = 0; i<n; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}