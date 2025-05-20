#include<iostream>
#include<chrono>
using namespace std;
using namespace chrono;

int partition(int arr[],int low,int high){
    int x = arr[high];
    int i = low - 1 ;
    for(int j = low ; j < high ; j++){
        if(arr[j] <= x){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i + 1 ;
}

void quick_Sort(int arr[],int low,int high){
    if(low < high){
        int p = partition(arr,low,high);
        quick_Sort(arr,low,p-1);
        quick_Sort(arr,p+1,high);
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    auto _start = chrono::high_resolution_clock::now();
    quick_Sort(arr, 0, n - 1);
    auto _difference = chrono::high_resolution_clock::now() - _start;
    cout<< chrono::duration_cast<chrono::duration<double,milli>>(_difference).count() << " ms" <<endl;  
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}

