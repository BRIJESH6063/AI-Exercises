#include<bits/stdc++.h>
using namespace std ;
#define n 5

void printSolution(int board[n][n])
{
    for(int i=0; i<n; i++){
    	for(int j=0; j<n; j++) cout << board[i][j] << " " ;
    	cout << endl ;
    }
}

bool isSafe(int board[n][n], int row, int col)
{
     for(int i=0; i<col; i++){
     	if(board[row][i]) return false ;
     }
     for(int i=row, j=col; i>=0 and j>=0; i--, j--){
     	if(board[i][j]) return false ;
     }

     for(int i=row, j=col; j>=0 and i<n; i++, j--){
     	if(board[i][j]) return false ;
     }

     return true ;
}

bool SolveNQueen(int board[n][n], int col)
{
     if(col >= n) return true ;
     for(int i=0; i<n; i++){
     	if(isSafe(board,i,col)){
     		board[i][col] = 1 ;
     		if(SolveNQueen(board,col+1)) return true ;
     		board[i][col] = 0 ;
     	}
     }
     return false ;
}

bool SolveNQ()
{
	int board[n][n] ;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++) board[i][j] = 0 ;
	}

    if(SolveNQueen(board,0) == false){
    	cout << "Solution Does not exist !" << endl ;
    	return false ;
    }

    printSolution(board) ;
    return true ;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL) ;

	#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r",  stdin) ;
	freopen("output.txt", "w", stdout) ;
	#endif 
    
    SolveNQ() ;

	return 0 ;
}
