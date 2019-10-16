#ifndef _GOMOKU_H_
#define _GOMOKU_H_
#include <iostream>
using namespace std;

const int length = 15;
typedef pair<int, int> pos; 

class chessBoard{
public:
    enum status{
        live_5  =   100000,     // ooooo
        live_4  =   100000,     // +oooo+
        sleep_4 =   1000,       // +oooo oo+oo
        live_3  =   1000,       // +ooo++ +oo+o+ 
        live_2  =   100,        // +o+o+ ++oo+
        sleep_3 =   100,        // +o+oo 
        live_1  =   10,         // +++o+ ++o++
        sleep_2 =   10,         // +++oo
        sleep_1 =   5,          // ++++o

        others  =   0
};
    int board[length][length] = {0};
    int turn = 0;

    int     runMGame();
    int     playMChess();
    bool    isValid(int row, int col);
    bool    isUnoccupied(int row, int col);
    int    judge(int i, int j);


    //console output
    void    printBoard();
    void    reprint();

    void    refresh();


};


#endif