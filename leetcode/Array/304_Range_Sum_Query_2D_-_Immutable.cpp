#include<vector>
#include<iostream>
using namespace std;

struct NumMatrix {
private:
    // Taken array instead of vector (because it is fast.(haah...) )
    int ans[200][200];
public:
    NumMatrix(vector<vector<int>>& matrix) {

        // Matrix size 
        int row = matrix.size();
        int col = matrix[0].size();

        int sum = 0 ;

        //Taking input and taking sum of previous all elements to current element (this sums columns)
        for(int i = 0 ; i < row ; i++){
            sum = 0;
            for(int j = 0 ; j < col ; j++){
                ans[i][j] = matrix[i][j];
                sum += ans[i][j] ;
                ans[i][j] = sum ;
            }
        }
        //Taking input and taking sum of previous all elements to current element (this sums rows)
        for(int i = 0 ; i < col ; i++){
            sum = 0;
            for(int j = 0 ; j < row ; j++){
                sum += ans[j][i] ;
                ans[j][i] = sum ;
            }
        }

        // Now the total sum of the sub-matrix from (0,0) is the last element of that matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {

        // Checking conditions and update total accordingly so index doesn't get out of bound.
        
        int total = ans[row2][col2];
        if(row1 > 0)   total -= ans[row1 - 1][col2]; // We have to substitue extra sum from (0,0) to (row1-1)(col2) 
        if(col1 > 0)    total -= ans[row2][col1 - 1]; // We have to substitue extra sum from (0,0) to (row2)(col1-1)
        if(row1 > 0 && col1 > 0)    total += ans[row1 - 1][col1 - 1]; // row1,col1 > 0 means we substitued (row1-1)(col1-1) twice so we have to add it once.
        return total ; // if sub matrix starts from (0,0)
    }
};


int main(int argc, char const *argv[])
{
    vector<vector<int>> matrix = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    };
    NumMatrix obj(matrix);
    cout << obj.sumRegion(2,1,4,3);
    getchar();
    return 0;
}
