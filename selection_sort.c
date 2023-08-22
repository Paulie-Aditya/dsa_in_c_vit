#include <stdio.h>

void selectionSort(int arr[], int n){
    for(int i = 0; i<n-1;i++){
        int min = arr[i];
        int min_index = i;
        for(int j = i;j<n;j++){
            if(min>arr[j]){
                min = arr[j];
                min_index = j;
            }
        }

        int temp = arr[i];
        arr[i] = min;
        arr[min_index] = temp;
    }
    return;
}


int main(void){
    int arr[] = {12,11,13,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr,n);

    for(int j = 0; j<n ;j++){
        printf("%d ",*(arr+j));
    }
    return 0;
}
