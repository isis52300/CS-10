//
//  main.cpp
//  Tic-Tac-Toe
//
//  Created by Isis Dumas on 12/1/18.
//  Copyright © 2018 Isis Dumas. All rights reserved.
//

#include <vector>
#include <iostream>
using namespace std;

void drawBoard(const vector < char >&gameBoard) {
    for (int i = 0; i < 9; i += 3) {
        cout << "  " << gameBoard.at(i) << "  |  " << gameBoard.at(i + 1) << "  |  "
        << gameBoard.at(i + 2) << "  " << endl;
        if (i < 6) {
            cout << "-----|-----|-----" << endl;
        }
    }
    cout << endl;
    
    return;
}

void initVector(vector <char> &v) {
    for (unsigned i = 0; i < v.size(); ++i) {
        v.at(i) = static_cast<char>(97 + i);
    }
    
    return;
}

int convertPosition(char boardPosition) {
    return static_cast<int> (boardPosition) - 97;
}

bool validPlacement(const vector<char>  &gameBoard, int positionIndex) {
    
    if (gameBoard.at(positionIndex) != 'X' && gameBoard.at(positionIndex) != 'O') {
        return true;
    }
    else {
        return false;
    }
}

int getPlay(const vector<char> &gameBoard) {
    
    char position = ' ';
    unsigned int conversion;
    
    cout << "Please choose a position: " << endl;
    cin >> position;
    conversion = convertPosition(position);
    
    while (conversion >= gameBoard.size()) {
        cout << "Please choose a position: " << endl;
        cin >> position;
        conversion = convertPosition(position);
    }
    
    while (!validPlacement(gameBoard, conversion)) {
        cout << "Please choose a position: " << endl;
        cin >> position;
        conversion = convertPosition(position);
    }
    
    return convertPosition(position);
}

bool gameWon(const vector<char> &gameBoard) {
    
    if ((gameBoard.at(0) == gameBoard.at(1) && gameBoard.at(1) == gameBoard.at(2)) ||
        (gameBoard.at(3) == gameBoard.at(4) && gameBoard.at(4) == gameBoard.at(5)) ||
        (gameBoard.at(6) == gameBoard.at(7) && gameBoard.at(7) == gameBoard.at(8)) ||
        (gameBoard.at(0) == gameBoard.at(3) && gameBoard.at(3) == gameBoard.at(6)) ||
        (gameBoard.at(1) == gameBoard.at(4) && gameBoard.at(4) == gameBoard.at(7)) ||
        (gameBoard.at(2) == gameBoard.at(5) && gameBoard.at(5) == gameBoard.at(8)) ||
        (gameBoard.at(0) == gameBoard.at(4) && gameBoard.at(4) == gameBoard.at(8)) ||
        (gameBoard.at(2) == gameBoard.at(4) && gameBoard.at(4) == gameBoard.at(6))) {
        return true;
    }
    else {
        return false;
    }
}

bool boardFull(const vector<char> &gameBoard) {
    
    bool place0 = validPlacement(gameBoard, 0);
    bool place1 = validPlacement(gameBoard, 1);
    bool place2 = validPlacement(gameBoard, 2);
    bool place3 = validPlacement(gameBoard, 3);
    bool place4 = validPlacement(gameBoard, 4);
    bool place5 = validPlacement(gameBoard, 5);
    bool place6 = validPlacement(gameBoard, 6);
    bool place7 = validPlacement(gameBoard, 7);
    bool place8 = validPlacement(gameBoard, 8);
    
    if (!place0 & !place1 & !place2 & !place3 & !place4 &
        !place5 & !place6 & !place7 & !place8) {
        return true;
    }
    
    return false;
}


int main() {
    vector<char> gameBoard(9);
    int curPlay;
    int whosTurn = 0;
    bool winner;
    bool full;
    
    initVector(gameBoard);
    drawBoard(gameBoard);
    winner = gameWon(gameBoard);
    full = boardFull(gameBoard);
    
    while (!winner & !full) {
        curPlay = getPlay(gameBoard);
        if (whosTurn % 2 == 0) {
            gameBoard.at(curPlay) = 'X';
        }
        else {
            gameBoard.at(curPlay) = 'O';
        }
        drawBoard(gameBoard);
        cout << endl;
        ++whosTurn;
        winner = gameWon(gameBoard);
        full = boardFull(gameBoard);
    }
    
    if (winner) {
        if (whosTurn % 2 == 0) {
            cout << "Player 2 Wins!!";
        }
        else {
            cout << "Player 1 Wins!!";
        }
    }
    else if (full) {
        cout << "No one wins";
    }
    
    return 0;
}
