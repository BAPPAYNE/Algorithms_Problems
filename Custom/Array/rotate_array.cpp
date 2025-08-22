#include <stdio.h>

void rotator(int arr[], int rotations,int size){
    while(rotations--){
        int saved_element = arr[0] ;
        for(int i = 1 ; i < size ; i++){
            arr[i-1] = arr[i];
        }
        arr[size-1] = saved_element;
    }
    for(int i = 0 ; i < size ; i++){
        printf("%d ", arr[i]) ;
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {1,2,3,4,5} ;
    int rotations = 2 ;
    int size = sizeof(arr)/sizeof(arr[0]) ;
    rotator(arr,rotations,size) ;
    return 0;
}
