#include <stdio.h>
#include <stdbool.h>
void binarySearch(int arr[], int low, int high, int k){
    int mid;
    bool flag= false;

    while(low<high){
        mid = (low+high)/2;

        if(arr[mid] == k){
            printf("%d found at index %d",k,mid);
            flag = true;
            break;
        }
        else if(arr[mid]>k){
            high = mid;
        }
        else if(arr[mid] <k){
            low = mid;
        }
    }

    if(!flag){
        printf("%d not in arr",k);
    }


}

int main(void){
    int arr[] = {5,7,10,13,17,25};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 7;
    binarySearch(arr,0, n-1, k);

    return 0;
}