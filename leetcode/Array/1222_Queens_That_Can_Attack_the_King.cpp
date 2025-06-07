#include<iostream>
#include<vector>
using namespace std; 


vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
    vector<vector<int>> arr(8,vector<int>(8,0)) ;
    // vector<vector<int>> arr;
    int queenSize = queens.size() ;
    for(int i = 0 ; i < queenSize ; i++){
        arr[queens[i][0]][queens[i][1]] = 1 ;
    }
    arr[king[0]][king[1]] = 2 ;
    int kingRow = king[0];
    int kingCol = king[1] ;

    vector<vector<int>> result ;

    for(int i = kingRow - 1 ; i >=0  ; i--){
        if(arr[i][kingCol] == 1){
            result.push_back({i,kingCol});
            break;
        }
    }
    for(int i = kingRow + 1 ; i < 8 ; i++){
        if(arr[i][kingCol] == 1){
            result.push_back({i,kingCol});
            break;
        }
    }
    for(int i = kingCol - 1 ; i >=0  ; i--){
        if(arr[kingRow][i] == 1){
            result.push_back({kingRow,i});
            break;
        }
    }
    for(int i = kingCol + 1 ; i < 8 ; i++){
        if(arr[kingRow][i] == 1){
            result.push_back({kingRow,i});
            break;
        }
    }
    int tempRow = kingRow - 1 ;
    int tempCol = kingCol - 1 ;
    while(tempRow >= 0 && tempCol >= 0){
        if(arr[tempRow][tempCol] == 1){
            result.push_back({tempRow,tempCol});
            break;
        }
        tempRow--; tempCol--;
    }
    tempRow = kingRow + 1 ;
    tempCol = kingCol + 1 ;
    while(tempRow <= 7 && tempCol <= 7){
        if(arr[tempRow][tempCol] == 1){
            result.push_back({tempRow,tempCol});
            break;
        }
        tempRow++; tempCol++;
    }
    tempRow = kingRow - 1 ;
    tempCol = kingCol + 1 ;
    while(tempRow >=0 && tempCol <= 7){
        if(arr[tempRow][tempCol] == 1){
            result.push_back({tempRow,tempCol});
            break;
        }
        tempRow--; tempCol++;
    }
    tempRow = kingRow + 1 ;
    tempCol = kingCol - 1 ;
    while(tempRow <=7 && tempCol >= 0){
        if(arr[tempRow][tempCol] == 1){
            result.push_back({tempRow,tempCol});
            break;
        }
        tempRow++; tempCol--;
    }
    

    return result ;
}


int main(int argc, char const *argv[])
{
    vector<vector<int>> queens = {{0,1},{1,0},{4,0},{0,4},{3,3},{2,4}};
    vector<int> king = {0,0};
    vector<vector<int>> result = queensAttacktheKing(queens, king);
    for(int i = 0 ; i < result.size() ; i++){
        for(int j = 0 ; j < 2 ; j++){
            cout << result[i][j] << " " ;
        }
        cout << endl ;
    }

    return 0;
}
