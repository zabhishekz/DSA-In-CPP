#include<iostream>
using namespace std;

void displayBoard(int board[][10], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == 1){
                cout<<"Q "; 
            }
            else{
                cout<<"_ ";
            }    
        }
        cout<<endl;
    }   
}

//helper function
bool isSafe(int board[][10], int i, int j, int n){
    //check for upper col
    for(int row = 0; row < i; row++){
        if(board[row][j] == 1){
            return false;
        }
    }
    //check for upper left diagonal
    int x = i;
    int y = j;
    while(x >= 0 && y >= 0){
        if(board[x][y] == 1){
            return false;
        }
        x--;
        y--;
    }
    //check for upper right diagonal
    x = i;
    y = j;
    while(x >= 0 && y < n){
        if(board[x][y] == 1){
            return false;
        }
        x--;
        y++;
    }
    //the position is safe if none of above are false
    return true;
}

bool solveNQueen(int board[][10], int i, int n){
    if(i == n){
        //You have Successfully placed queens in n rows
        //Print the board
        displayBoard(board,n);
        cout<<endl;
        return true;
    }
    //Recursive case
    //Try to place the queen in the current row and call on the remaining part which will be solved by recursion
    for(int j = 0; j < n; j++){
        //check if i,j position is safe to place the queen
        if(isSafe(board, i, j, n)){
            //place the queen- assuming i, j is the right position
            board[i][j] = 1;
            bool nextqueenRakhPaye = solveNQueen(board, i+1, n);
            if(nextqueenRakhPaye){
                return true;
            }
            //backtracking
            board[i][j] = 0;            
        }
    }
    // Toggle this true and false depending on if only one answer is required or all. 
    return false;   
}

int main(){
    int n, board[10][10] = {0};
    cin>>n; 
    solveNQueen(board, 0, n);
    return 0;
}