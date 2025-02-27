#include <iostream>
using namespace std;

class TicTacToe {
private:
    char board[3][3];
    char currentPlayer;

public:
    TicTacToe() {
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                board[i][j] = '-';
            }
        }
        currentPlayer = 'X';
    }

    void displayBoard() {
        cout << "Tic-Tac-Toe Board:\n\n";
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    bool checkWin() {
        for(int i=0; i<3; i++) {
            if(board[i][0] != '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                return true;
            }
            if(board[0][i] != '-' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
                return true;
            }
        }
        if(board[0][0] != '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            return true;
        }
        if(board[0][2] != '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            return true;
        }
        return false;
    }

    bool checkTie() {
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(board[i][j] == '-') {
                    return false;
                }
            }
        }
        return true;
    }

    void switchPlayer() {
        if(currentPlayer == 'X') {
            currentPlayer = 'O';
        }
        else {
            currentPlayer = 'X';
        }
    }

    bool makeMove(int row, int col) {
        if(row < 0 || row > 2 || col < 0 || col > 2) {
            return false;
        }
        if(board[row][col] != '-') {
            return false;
        }
        board[row][col] = currentPlayer;
        return true;
    }

    char getCurrentPlayer() {
        return currentPlayer;
    }
};

int main() {
    TicTacToe game;
    int row, col;

    cout << "Welcome to Tic-Tac-Toe!\n\n";

    while(true) {
        game.displayBoard();

        cout << "Player " << game.getCurrentPlayer() << ", enter row (0-2): ";
        cin >> row;
        cout << "Player " << game.getCurrentPlayer() << ", enter column (0-2): ";
        cin >> col;

        if(game.makeMove(row, col)) {
            if(game.checkWin()) {
                game.displayBoard();
                cout << "Player " << game.getCurrentPlayer() << " wins!\n";
                break;
            }
            if(game.checkTie()) {
                game.displayBoard();
                cout << "It's a tie!\n";
                break;
            }
            game.switchPlayer();
        }
        else {
            cout << "Invalid move. Try again.\n";
        }
    }

    return 0;
}