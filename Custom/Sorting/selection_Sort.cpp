#include <iostream>
// #include <vector>
#include<chrono>
using namespace std;


// Function to perform selection sort
// void selectionSort(vector<int>& arr) {
//     int size = arr.size();
//     for(int i = 0; i < size - 1; ++i) {
//         int minIdx = i;
//         for(int j = i + 1; j < size; ++j) {
//             if(arr[j] < arr[minIdx]) {
//                 minIdx = j;
//             }
//         }
//         swap(arr[i], arr[minIdx]);
//     }
// }
void selectionSort(int arr[],int size) {
    for(int i = 0; i < size - 1; ++i) {
        int minIdx = i;
        for(int j = i + 1; j < size; ++j) {
            if(arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

int main() {
    // int size;
    // cout << "Enter sizeumber of elements: ";
    // cin >> size;
    int arr[] = {10, 7, 8, 9, 1, 5};
    // cout << "Enter elements:\n";
    // for(int i = 0; i < size; ++i) {
    //     cin >> arr[i];
    // }
    int size = sizeof(arr)/sizeof(arr[0]) ;
    auto T1 = chrono::high_resolution_clock::now();
    selectionSort(arr,size);

    auto diff_ = chrono::high_resolution_clock::now() - T1 ;
    cout << chrono::duration_cast<chrono::duration<double,milli>> (diff_).count() << " milliseconds" ;

    // cout << "Sorted array:\n";
    for(int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}