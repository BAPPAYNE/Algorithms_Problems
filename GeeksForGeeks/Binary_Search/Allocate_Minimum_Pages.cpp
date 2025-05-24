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
