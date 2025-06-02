#include<iostream>
#include<chrono>

using namespace std;

void insertion_Sort(double arr[], int size) {
    for (int i = 1; i < size; i++) {
        double temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j +1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
} 

int main(int argc, char const *argv[])
{
    // Using array (faster than vector (Haah...))
    double arr[] = {-1,5,3,4,0};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    auto T1 = chrono::high_resolution_clock::now();
    insertion_Sort(arr,size);
    cout << chrono::duration_cast<chrono::duration<double, milli>> (chrono::high_resolution_clock::now() - T1).count() << " milliseconds" << endl;

    // auto diff_ = chrono::high_resolution_clock::now() - T1 ;
    for(int i = 0 ; i < size ; i++){
        cout << arr[i] << " " ;
    }
    return 0;
}
