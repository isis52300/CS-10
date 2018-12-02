//
//  main.cpp
//  Oblivian-game
//
//  Created by Isis Dumas on 12/2/18.
//  Copyright © 2018 Isis Dumas. All rights reserved.
//


#include <vector>
#include <iostream>
using namespace std;

void drawBoard(const vector < char >&gameBoard) {
    for (int i = 0; i < 36; i += 6) {
        cout << "  " << gameBoard.at(i) << "  |  "
        << gameBoard.at(i + 1) << "  |  "
        << gameBoard.at(i + 2) << "  |  "
        << gameBoard.at(i + 3) << "  |  "
        << gameBoard.at(i + 4) << "  |  "
        << gameBoard.at(i + 5) << "  "
        << endl;
        if (i < 30) {
            cout << "-----|-----|-----|-----|-----|-----" << endl;
        }
    }
    cout << endl;
    
    return;
}

int convertPosition(char boardPosition) {
    return static_cast<int> (boardPosition) - 65;
}

bool validPlacement(const vector<char>  &gameBoard, int positionIndex) {
    
    if (gameBoard.at(positionIndex) != '1'
        && gameBoard.at(positionIndex) != '2'
        && gameBoard.at(positionIndex) != '!') {
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
    bool place9 = validPlacement(gameBoard, 9);
    bool place10 = validPlacement(gameBoard, 10);
    bool place11 = validPlacement(gameBoard, 11);
    bool place12 = validPlacement(gameBoard, 12);
    bool place13 = validPlacement(gameBoard, 13);
    bool place14 = validPlacement(gameBoard, 14);
    bool place15 = validPlacement(gameBoard, 15);
    bool place16 = validPlacement(gameBoard, 16);
    bool place17 = validPlacement(gameBoard, 17);
    bool place18 = validPlacement(gameBoard, 18);
    bool place19 = validPlacement(gameBoard, 19);
    bool place20 = validPlacement(gameBoard, 20);
    bool place21 = validPlacement(gameBoard, 21);
    bool place22 = validPlacement(gameBoard, 22);
    bool place23 = validPlacement(gameBoard, 23);
    bool place24 = validPlacement(gameBoard, 24);
    bool place25 = validPlacement(gameBoard, 25);
    bool place26 = validPlacement(gameBoard, 26);
    bool place27 = validPlacement(gameBoard, 27);
    bool place28 = validPlacement(gameBoard, 28);
    bool place29 = validPlacement(gameBoard, 29);
    bool place30 = validPlacement(gameBoard, 30);
    bool place31 = validPlacement(gameBoard, 31);
    bool place32 = validPlacement(gameBoard, 32);
    bool place33 = validPlacement(gameBoard, 33);
    bool place34 = validPlacement(gameBoard, 34);
    bool place35 = validPlacement(gameBoard, 35);
    
    
    
    if (!place0 & !place1 & !place2 & !place3 & !place4 & !place5 &
        !place6 & !place7 & !place8 & !place9 & !place10 & !place11 &
        !place12 & !place13 & !place14 & !place15 & !place16 & !place17 &
        !place18 & !place19 & !place20 & !place21 & !place22 & !place23 &
        !place24 & !place25 & !place26 & !place27 & !place28 & !place29 &
        !place30 & !place31 & !place32 & !place33 & !place34 & !place35) {
        return true;
    }
    
    return false;
}

void changeSurrounding (vector<char> &v, int position) {
    
    if ((position >= 7 && position <= 10) ||
        (position >= 13 && position <= 16) ||
        (position >= 19 && position <= 22) ||
        (position >= 25 && position <= 28)) {
        v.at(position - 7) = '!';
        v.at(position - 6) = '!';
        v.at(position - 5) = '!';
        v.at(position - 1) = '!';
        v.at(position + 1) = '!';
        v.at(position + 5) = '!';
        v.at(position + 6) = '!';
        v.at(position + 7) = '!';
    }
    else if (position == 0) {
        v.at(position + 1) = '!';
        v.at(position + 6) = '!';
        v.at(position + 7) = '!';
    }
    else if (position == 5) {
        v.at(position - 1) = '!';
        v.at(position + 5) = '!';
        v.at(position + 6) = '!';
    }
    else if (position == 30) {
        v.at(position - 6) = '!';
        v.at(position - 5) = '!';
        v.at(position + 1) = '!';
    }
    else if (position == 35) {
        v.at(position - 7) = '!';
        v.at(position - 6) = '!';
        v.at(position - 1) = '!';
    }
    else if (position == 6 || position == 12 || position == 18 || position == 24) {
        v.at(position - 6) = '!';
        v.at(position - 5) = '!';
        v.at(position + 1) = '!';
        v.at(position + 6) = '!';
        v.at(position + 7) = '!';
    }
    else if (position >= 1 && position <= 4) {
        v.at(position - 1) = '!';
        v.at(position + 5) = '!';
        v.at(position + 6) = '!';
        v.at(position + 7) = '!';
        v.at(position + 1) = '!';
    }
    else if (position == 11 || position == 17 || position == 23 || position == 29) {
        v.at(position - 6) = '!';
        v.at(position - 7) = '!';
        v.at(position - 1) = '!';
        v.at(position + 5) = '!';
        v.at(position + 6) = '!';
    }
    else if (position >= 31 && position <= 34) {
        v.at(position - 1) = '!';
        v.at(position - 7) = '!';
        v.at(position - 6) = '!';
        v.at(position - 5) = '!';
        v.at(position + 1) = '!';
    }
}

int main () {
    
    vector <char> gameBoard(36);
    int position;
    int playerTurn = 0;
    
    for (unsigned i = 0; i < gameBoard.size(); ++i) {
        gameBoard.at(i) = static_cast<char>(65 + i);
    }
    drawBoard(gameBoard);
    
    while(!boardFull(gameBoard)) {
        position = getPlay(gameBoard);
        if (playerTurn % 2 == 0) {
            gameBoard.at(position) = '1';
        }
        else {
            gameBoard.at(position) = '2';
        }
        changeSurrounding(gameBoard, position);
        drawBoard(gameBoard);
        ++playerTurn;
    }
    
    if (playerTurn % 2 == 1) {
        cout << "Player 1 Wins!!" << endl;
    }
    else {
        cout << "Player 2 Wins!!" << endl;
    }
    
    return 0;
}
