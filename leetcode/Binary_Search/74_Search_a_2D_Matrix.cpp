#include<iostream>
#include<vector>
#include<chrono>
// Namespaces
using namespace std;

bool search_2D_Matrix(vector<vector<int>>& matrix, int target){
    // Checking if metrix is empty or not.
    if (matrix.empty() || matrix[0].empty()) return false;


    int size_rows = matrix.size();
    int size_cols = matrix[0].size();
    int row,col;
    int start = 0, end = size_cols*size_rows-1;
    int mid = 0;
    while(start <= end){
        mid = start + (end-start)/2;
        row = mid / size_cols;
        col = mid % size_cols;

        if(matrix[row][col] == target){
            return true;
        }else if(matrix[row][col] > target){
            end = mid -1;
        }else{
            start = mid + 1 ;
        }
    }

    return false;
}

int main(int argc, char const *argv[])
{
    // vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    vector<vector<int>> matrix = {{1,3}};
    // vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 3;
    auto _start = chrono::high_resolution_clock::now();
    cout << search_2D_Matrix(matrix,target) << endl;
    auto _difference = chrono::high_resolution_clock::now() - _start;

    cout << chrono::duration_cast<chrono::duration<double,milli>>(_difference).count() << endl;
    return 0;
}
