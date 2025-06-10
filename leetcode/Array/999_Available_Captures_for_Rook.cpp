#include<iostream>
#include<vector>
using namespace std;

int numRookCaptures(vector<vector<char>>& board) {
    short rook_I,rook_J ;
    short i;
    bool isOk = false ;
    for(int i = 0 ; i < 8 ; i++){
        for(int j = 0 ; j < 8 ; j++){
            if(board[i][j] == 'R'){
                rook_I = i;
                rook_J = j ;
                isOk = true ;
                break;
            }
        }
        if(isOk) break;
    }

    short count = 0 ;
    for(i = rook_I - 1 ; i >= 0 ; i--){
        if(board[i][rook_J] == 'B') break;
        if(board[i][rook_J] == 'p'){
            count++;
            break;
        }
    }
    for(i = rook_I + 1 ; i < 8 ; i++){
        if(board[i][rook_J] == 'B') break;
        if(board[i][rook_J] == 'p'){
            count++;
            break;
        }
    }
    for(i = rook_J - 1 ; i >=0 ; i--){
        if(board[rook_I][i] == 'B') break;
        if(board[rook_I][i] == 'p'){
            count++;
            break;
        }
    }
    for(int i = rook_J + 1 ; i < 8 ; i++){
        if(board[rook_I][i] == 'B') break;
        if(board[rook_I][i] == 'p'){
            count++;
            break;
        }
    }

    return count ;
}

int main(int argc, char const *argv[])
{
    vector<vector<char>> board = {
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','p','.','.','.','.'},
        {'.','.','.','R','.','.','.','p'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','p','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'}
    };
    cout << numRookCaptures(board) << endl;
    return 0;
}
