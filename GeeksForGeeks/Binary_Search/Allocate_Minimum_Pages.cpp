/*

You are given an array arr[] of integers, where each element arr[i] represents the number of pages in the ith book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:

    Each student receives atleast one book.
    Each student is assigned a contiguous sequence of books.
    No book is assigned to more than one student.

The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).

Examples:

Input: arr[] = [12, 34, 67, 90], k = 2
Output: 113
Explanation: Allocation can be done in following ways:
[12] and [34, 67, 90] Maximum Pages = 191
[12, 34] and [67, 90] Maximum Pages = 157
[12, 34, 67] and [90] Maximum Pages = 113.
Therefore, the minimum of these cases is 113, which is selected as the output.

*/






#include<iostream>
#include<chrono>
#include<vector>

using namespace std;

long long findPages(vector<long long> &arr, int k) {
    int size = arr.size();
    if(size < k)    return -1 ;
    int end = 0;
    int start = 0;
    for(int i = 0 ; i < size ; i++){
        start = (start > arr[i] ? start : arr[i]);
        end+=arr[i];
    }
    int ans;
    int mid;
    int count;
    int page;
    while(start <= end){
        mid = start + (end - start)/2 ;
        page = 0;count = 1 ;
        for(int i = 0 ; i < size ; i++){
            page+=arr[i] ;
            if(mid < page){
                count++;
                page=arr[i];
            }
        }
        if(count <= k){
            ans = mid;
            end = mid - 1;
        }else{
            start = mid + 1 ;
        }
    }
    
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<long long> vec = {12,34,67,90};
    int k = 2 ;
    auto _start = chrono::high_resolution_clock::now();
    cout << findPages(vec,k) << endl;
    auto _difference = chrono::high_resolution_clock::now() - _start;
    cout<< chrono::duration_cast<chrono::duration<double,milli>>(_difference).count() << " ms" <<endl;    

    return 0;
}
