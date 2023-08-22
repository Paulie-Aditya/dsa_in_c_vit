#include <stdio.h>


void bubbleSort(int arr[], int n){
    for(int i = 0; i<n-1;i++){
        for(int j = 0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
}

int main(void){
    int arr[] = {12,11,13,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,n);

    for(int j = 0; j<n ;j++){
        printf("%d ",*(arr+j));
    }
    return 0;
}
