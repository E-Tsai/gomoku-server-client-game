#include "gomoku.h"
#include <ctype.h>

bool chessBoard::isValid(int row, int col){
    return isdigit(row) && isdigit(col) && row > -1 && col > -1 &&
           row < length && col < length; 
}

bool chessBoard::isUnoccupied(int row, int col){
    return board[row][col]==0; 
}

// bool judge(){

// }

void chessBoard::printBoard(){
    int i, j;
    string split = "-------------------------------------------------";
    // first line
    cout << "   ";
    for(i = 0; i < length; i++){
        cout << "|" << i+1;
        if(i < 9){
            cout << ' ';
        }
    }
    cout << "|" << endl << split << endl;

    for(i = 0; i < length; i++){
        cout << "|" << i+1;
        if(i < 9){
            cout << ' ';
        }
        cout << '|';
        for(j = 0; j < length; j++){
            if(!board[i][j]){
                cout << "  |";
            }
            else if(board[i][j]==1){
                cout << "\033[1m\033[31m o" <<  "\033[0m|";
            }
            else{
                cout << "\033[1m\033[32m x" << "\033[0m|";
            }
        }
        cout << endl << split << endl;
    }
}

int chessBoard::judge(int i, int j){
    // every new square has four directions to check
    int type = board[i][j];

    // horizontal
    int l = i, r = i;
    while(isValid(l-1, j) && board[l-1][j] == type){
        l--;
    }
    while(isValid(r+1, j) && board[r+1][j] == type){
        r++;
    }
    if(r-l > 3){
        return type;
    }

    // vertical
    int u = j, d = j;
    while(isValid(i, u-1) && board[i][u-1] == type){
        u--;
    }
    while(isValid(i, d+1) && board[i][d+1] == type){
        d++;
    }
    if(d-u > 3){
        return type;
    }

    // top left
    l = r = i; u = d = j;
    while(isValid(l-1, u-1) && board[l-1][u-1] == type){
        l--; u--;
    }
    while(isValid(r+1, d+1) && board[r+1][d+1] == type){
        r++; d++;
    }
    if(r-l > 3){
        return type;
    }

    // top right
    l = r = i; u = d = j;
    while(isValid(l-1, d+1) && board[l-1][d+1] == type){
        l--; d++;
    }
    while(isValid(r+1, u-1) && board[r+1][u-1] == type){
        r++; u--;
    }
    if(r-l > 3){
        return type;
    }

    return 0;
}

void chessBoard::reprint(){
    system("reset");
    printBoard();
}

int chessBoard::playMChess(){
    int i, j;
    if(turn%2){            //white
        cout << "player1: ";
        cin >> i >> j; 
        i--; j--;
        while(!isValid(i, j) || !isUnoccupied(i, j)){
            cout << "please choose an unoccupied and valid square ([i j]): " << endl;
            cout << "player1: ";
            cin >> i >> j;
            i--; j--;
        }
        cout << endl;
        board[i][j] = 1;
    }
    else{                   //black
        cout << "player2: ";
        cin >> i >> j; 
        i--; j--;
        while(!isValid(i, j) || !isUnoccupied(i, j)){
            cin.clear();
            cout << "please choose an unoccupied and valid square([i, j]): ";
            cin >> i >> j;
            i--; j--;
        }
        cout << endl;
        board[i][j] = 2;
    }
    reprint();
    if(judge(i, j) == 1){
        cout << "player 1 won!" << endl;
        return 1;
    }
    else if(judge(i, j) == 2){
        cout << "player 2 won!" << endl;
        return 1;
    }
    return 0;
}

int chessBoard::runMGame(){
    printBoard();
    while(1){
        turn++;
        if(playMChess()) break;
    }
    return 0;
}

void chessBoard::refresh(){
    system("reset");
    turn = 0;
    for(int i = 0; i < length; i++){
        for(int j = 0; j < length; j++){
            board[i][j] = 0;
        }
    }
}

