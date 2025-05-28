#include <iostream>
#include <vector>
using namespace std;



 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 

// Function to perform selection sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for(int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for(int j = i + 1; j < n; ++j) {
            if(arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements:\n";
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    selectionSort(arr);

    cout << "Sorted array:\n";
    for(int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}