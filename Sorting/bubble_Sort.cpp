// #include<stdio.h>
#include<chrono>
#include<iostream>
using namespace std;
using namespace chrono;


void bubble_Sort(double arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    // int arr_Size;
    // printf("Enter arr size : ") ;
    // // scanf("%d",&arr_Size);
    // std::cin >> arr_Size;
    // double arr[arr_Size];
    double arr[] = {10, 7, 8, 9, 1, 5};
    int arr_Size = sizeof(arr) / sizeof(arr[0]);
    // User Input
    // printf("Enter elements (Ex. 10 15 28 2 7 56 -89 12892 23.5 59.12356): ");
    // for(unsigned i = 0 ; i < arr_Size ; i++){
    //     cin >> arr[i] ;
    // }
    auto _start = chrono::high_resolution_clock::now();
    bubble_Sort(arr,arr_Size);
    auto _difference = chrono::high_resolution_clock::now() - _start;
    cout<< chrono::duration_cast<chrono::duration<double,milli>>(_difference).count() << " ms" <<endl;  
    for (size_t i = 0; i < arr_Size; i++)
    {
        cout << arr[i] << " " ;
    }
    
    return 0;
}
