#include <iostream>
#include <cstring>
#include "gomoku.h"

int main(int argc, char *argv[]){
    chessBoard go;
    if(argc != 2){
        cout << "arg error" << endl;
        return -1;
    }
    if(!strcmp(argv[1], "-s")){

    }
    else if(!strcmp(argv[1], "-m")){
        while(1){
            go.runMGame();
            cout << "enter \'r\' to play again, enter any other key to exit:" << endl;
            char c;
            cin >> c;
            if(c!='r'){
                break;
            }
            go.refresh();
        }
    }
    return 0;
}

