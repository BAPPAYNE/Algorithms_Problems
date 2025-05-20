#include<iostream>

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
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

int main(int argc, char const *argv[])
{
    double arr[] = {-1,5,3,4,0};
    int size = sizeof(arr)/sizeof(arr[0]);
    insertion_Sort(arr,size);
    for(int i = 0 ; i < size ; i++){
        cout << arr[i] << " " ;
    }
    ListNode *head = new ListNode(42);
    cout << head->val << " ";
    ListNode *temp = head;
    cout << temp;
    return 0;
}
