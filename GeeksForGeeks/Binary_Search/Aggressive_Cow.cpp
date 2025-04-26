#include <iostream>
#include <vector>
#include <algorithm>
#include<chrono>

// Namespaces
using namespace std;

static int aggressive_cows_arr(int stalls[], int size_stalls, int cows) {
    // Edge case: not enough stalls or invalid number of cows
    if (size_stalls < cows || cows < 1) {
        return -1;
    }

    sort(stalls, stalls + size_stalls);

    int start = 1; // Minimum possible distance
    int end = stalls[size_stalls - 1] - stalls[0]; // Maximum possible distance
    int max_min_distance = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2; // Avoid overflow
        int cows_count = 1; // Place first cow at stalls[0]
        int last_position = stalls[0];

        // Greedy placement of cows
        for (int i = 1; i < size_stalls && cows_count < cows; ++i) {
            if (stalls[i] - last_position >= mid) {
                cows_count++;
                last_position = stalls[i];
            }
        }

        if (cows_count >= cows) {
            // Feasible distance, try larger
            max_min_distance = mid;
            start = mid + 1;
        } else {
            // Not feasible, try smaller
            end = mid - 1;
        }
    }

    return max_min_distance;
}

static int aggressive_cows_vector(vector<int>& stalls, int cows){
    int size_stalls = stalls.size();
    if(size_stalls < cows || cows < 1){
        return -1;
    }
    
    sort(stalls.begin(), stalls.end());                                  // Sorting, if required
    
    int start = 1, end = stalls[size_stalls - 1] - stalls[0], mid; // Max distance between two cows
    int cows_count = 0, max_min_distance=-1;
    int pos = 0;
    
    while (start <= end){
        mid = start + (end - start) / 2; // sets distance between cows
        cows_count = 1;
        pos = stalls[0];
        for (int i = 1; i < size_stalls && cows_count < cows; ++i){
            if ((pos + mid) <= stalls[i]){
                cows_count++;
                pos = stalls[i];
            }
        }
        if (cows_count < cows){
            end = mid - 1; // reduces distance between cows because all cows are not included
        }else{
            max_min_distance = mid;
            start = mid + 1; // increases distance between cows because distance can be more that what is at mid
        }
    }
    return max_min_distance;
}

int main(int argc, char const *argv[]){
    int stalls_arr[] = {
        1, 100, 200, 300, 400, 500, 600, 700, 800, 1000000
    };
    // vector<int> stalls_vector = {
    //     1, 100, 200, 300, 400, 500, 600, 700, 800, 1000000
    // };
    int iterations = 100000;
    auto _start = chrono::high_resolution_clock::now();

/*    Testing purpose :)
    for (int i = 0; i < iterations; ++i) {
        cout << aggressive_cows_vector(stalls_vector, 7) << " ";
    }
    // Array is always faster (40-50%) and will alway be.
    for (int i = 0; i < iterations; ++i) {
        cout << aggressive_cows_arr(stalls_arr,10, 7) << " ";
    }
*/
    cout <<  aggressive_cows_arr(stalls_arr, 10, 2) << endl;
    auto _difference = chrono::high_resolution_clock::now() - _start;
    cout<< chrono::duration_cast<chrono::duration<double,milli>>(_difference).count() << " ms" <<endl;    

    // getchar();
    return 0;
}
