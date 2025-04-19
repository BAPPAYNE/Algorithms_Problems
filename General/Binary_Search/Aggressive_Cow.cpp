#include <iostream>
#include <vector>
#include <algorithm>
#include<chrono>

// Namespaces
using namespace std;

static int aggressive_cow(vector<int>& stalls, int cows){
    sort(stalls.begin(), stalls.end());                                  // Sorting, if required
    
    int _size_stalls = stalls.size();
    
    int start = 1, end = stalls[_size_stalls - 1] - stalls[0], mid; // Max distance between two cows
    int _cows_count = 0, ans;
    int pos = 0;
    
    while (start <= end){
        mid = start + (end - start) / 2; // sets distance between cows
        _cows_count = 1;
        pos = stalls[0];
        for (int i = 0; i < _size_stalls; i++){
            if ((pos + mid) <= stalls[i]){
                _cows_count++;
                pos = stalls[i];
            }
        }
        if (_cows_count < cows){
            end = mid - 1; // reduces distance between cows because all cows are not included
        }else{
            ans = mid;
            start = mid + 1; // increases distance between cows because distance can be more that what is at mid
        }
    }
    return ans;
}

int main(int argc, char const *argv[]){
    vector<int> stalls = {
        6,4,3,16,20,7,18,10
    };
    auto _start = chrono::high_resolution_clock::now();
    cout <<  aggressive_cow(stalls, 5) << endl;
    auto _difference = chrono::high_resolution_clock::now() - _start;
    cout<< chrono::duration_cast<chrono::duration<double,milli>>(_difference).count() << " ms" <<endl;    

    // getchar();
    return 0;
}
