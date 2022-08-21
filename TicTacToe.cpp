#include<bits/stdc++.h>
using namespace std ;

#define COMPUTER 1 //player 1 
#define HUMAN 2    //player 2
#define SIDE 3     //side of board.

#define COMPUTERMOVE 'O' 
#define HUMANMOVE 'X'

void showBoard(char board[][SIDE])
{
    cout << endl << endl ;
    cout << "   " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl ;
    cout << "   ------------ " << endl ;
    cout << "   " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl ;
    cout << "   ------------ " << endl ;
    cout << "   " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl ;

    return ;
}

void showInstructions()
{
    cout << "   " << "Tic-Tac-Toe " << endl << endl ;
    cout << "insert a cell number from 1 to 9 to play.. " << endl ;
    cout << "   1 | 2 | 3 " << endl ;
    cout << "-------------" << endl ;
    cout << "   4 | 5 | 6 " << endl ;
    cout << "-------------" << endl ;
    cout << "   7 | 8 | 9 " << endl ;
    cout << "-------------" << endl << endl ;
    cout << "- - - - - - - - - - " << endl << endl ;

    return ;
}

void initialise(char board[][SIDE], int moves[])
{
    srand(time(NULL))  ;
    for(int i=0; i<SIDE; i++){
        for(int j=0; j<SIDE; j++) board[i][j] = ' ' ;
    }

    for(int i=0; i<SIDE*SIDE; i++)  moves[i] = i ;
    random_shuffle(moves, moves + SIDE*SIDE) ;

    return ;
}

void declareWinner(int whoseTurn)
{
    if(whoseTurn == COMPUTER) cout << "COMPUTER has won." << endl ;
    else cout << "HUMAN has won." << endl ;
}

bool rowCrossed(char board[][SIDE])
{
    for(int i=0; i<SIDE; i++){ 
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') 
        return true ;
    }
    return false ;
}
bool columnCrossed(char board[][SIDE])
{
    for(int i=0; i<SIDE; i++){ 
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') 
        return true ;
    }
    return false ;
}
bool diagonalCrossed(char board[][SIDE])
{
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') 
    return true  ;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][2] && board[0][2] != ' ') 
    return true  ;

    return false ;
}
bool gameOver(char board[][SIDE])
{
    return (rowCrossed(board) || columnCrossed(board) || diagonalCrossed(board)) ;
}
void playTicTacToe(int whoseTurn)
{
    char board[SIDE][SIDE] ;
    int moves[SIDE*SIDE]   ;
    initialise(board, moves) ;
    showInstructions() ;
    int moveIndex = 0, x, y ;
    while(gameOver(board) == false && moveIndex != SIDE*SIDE) 
    {
        if(whoseTurn == COMPUTER)
        {
            x = moves[moveIndex]/SIDE ;
            y = moves[moveIndex]%SIDE ;
            board[x][y] = COMPUTERMOVE ;
            cout << "COMPUTER Moves " << COMPUTERMOVE << " in " << moves[moveIndex]+1 << endl ;
            showBoard(board) ;
            moveIndex ++ ;
            whoseTurn = HUMAN ;
        }
        else if(whoseTurn == HUMAN)
        {
            x = moves[moveIndex]/SIDE ;
            y = moves[moveIndex]%SIDE ;
            board[x][y] = HUMANMOVE ;
            cout << "HUMAN moves " << HUMANMOVE << " in " << moves[moveIndex]+1 << endl ;
            showBoard(board) ;
            moveIndex ++ ;
            whoseTurn = COMPUTER ;
        }
    }
    if(gameOver(board) == false && moveIndex == SIDE*SIDE)
    cout << "Match Draw! No one WINS!" << endl ;
    else
    {
        if(whoseTurn == COMPUTER) whoseTurn = HUMAN ;
        else if(whoseTurn == HUMAN) whoseTurn = COMPUTER ;
        declareWinner(whoseTurn) ;
    }
    return ;
}

int main()
{
    playTicTacToe(COMPUTER) ;
    return 0 ;
}