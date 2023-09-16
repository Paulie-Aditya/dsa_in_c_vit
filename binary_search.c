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
            high = mid-1;
        }
        else if(arr[mid] <k){
            low = mid+1;
        }
    }

    if(!flag){
        printf("%d not in arr",k);
    }


}

int main(void){
    int arr[] = {5,7,10,13,17,25,-1,20,10,2020,2022,339};
    int n = sizeof(arr)/sizeof(arr[0]);

    int k;
    printf("Enter element to find: ");
    scanf("%d",&k);
    binarySearch(arr,0, n-1, k);

    return 0;
}