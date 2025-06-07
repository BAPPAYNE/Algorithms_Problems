#include<iostream>

using namespace std ;

// I think this is the best possible solution. 
// Time complexity O(1)
// Space complexity (1)


int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
    int rook_I = a ;
    int rook_J = b ;
    int bishup_I = c ;
    int bishup_J = d ;
    int queen_I = e ;
    int queen_J = f ;
    
// Checking bishup's condition for 1 move capture
    // Cheking right-to-left(diagonal) bishup condition for 1 move capture
    if((queen_I + queen_J) == (bishup_I + bishup_J)){
        if((rook_I + rook_J) != (bishup_I + bishup_J)){
            return 1 ;
        }else{
            if((bishup_J < queen_J) && ((rook_J < bishup_J) || (rook_J > queen_J))){
                return 1 ;
            }
            if((bishup_J > queen_J) && ((rook_J > bishup_J) || (rook_J < queen_J))){
                return 1 ;
            }
        }
    }
    // Cheking left-to-right(diagonal)  bishup condition for 1 move capture
    if(queen_I - queen_J == bishup_I - bishup_J){
        if(rook_I - rook_J != bishup_I - bishup_J){
            return 1 ;
        }else{
            if((bishup_I > queen_I) && ((rook_I > bishup_I) || (rook_I < queen_I))){
                return 1 ;
            }
            if((bishup_I < queen_I) && ((rook_I < bishup_I) || (rook_I > queen_I))){
                return 1 ;
            }
        }
    }

// Checking rook's condition for 1 move capture
    // Cheking rook and queen same row for 1 move capture
    if(rook_I == queen_I){
        if(rook_I != bishup_I){
            return 1 ;
        }else{
            if((rook_J < queen_J) && ((bishup_J > queen_J) || (bishup_J < rook_J))){
                return 1 ;
            }
            if((rook_J > queen_J) && ((bishup_J > rook_J) || (bishup_J < queen_J))){
                return 1 ;
            }
        }
    }
    // Cheking rook and queen same column for 1 move capture
    if(rook_J == queen_J){
        if(rook_J != bishup_J){
            return 1 ;
        }else{
            if((rook_I < queen_I) && ((bishup_I > queen_I) || (bishup_I < rook_I))){
                return 1 ;
            }
            if((rook_I > queen_I) && ((bishup_I > rook_I) || (bishup_I < queen_I))){
                return 1 ;
            }
        }
    }
// If no 1 move condition satisfies then 2 move requires to capture the queen.
    return 2 ;
}

int main(int argc, char const *argv[])
{
    int rook_I = 7, rook_J = 5, bishup_I = 2, bishup_J = 5, queen_I = 6, queen_J = 3;
    cout << minMovesToCaptureTheQueen(rook_I, rook_J, bishup_I, bishup_J, queen_I, queen_J) ;
    return 0;
}
