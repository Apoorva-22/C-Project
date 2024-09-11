#include <iostream>

using namespace std;

const int BOARD_SIZE = 3;
char board[BOARD_SIZE][BOARD_SIZE];  
char currentPlayer = 'X';  

void initializeBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '1' + i * BOARD_SIZE + j;  
        }
    }
}

void displayBoard() {
    cout << "\n";
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            cout << board[i][j] << " ";
            if (j < BOARD_SIZE - 1) cout << "| ";  
        }
        cout << "\n";
        if (i < BOARD_SIZE - 1) cout << "--|---|--\n";  
    }
    cout << "\n";
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

bool checkWin() {
    
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;

    return false;
}

bool checkDraw() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') return false;
        }
    }
    return true;
}

bool makeMove(int move) {
    int row = (move - 1) / BOARD_SIZE;
    int col = (move - 1) % BOARD_SIZE;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentPlayer; 
        return true;
    } else {
        return false; 
    }
}

int main() {
    int move;
    bool gameWon = false, gameDraw = false;

    initializeBoard();

    cout << "Tic-Tac-Toe Game\n";
    displayBoard();

    while (!gameWon && !gameDraw) {
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        if (move >= 1 && move <= 9) {
            if (makeMove(move)) {
                displayBoard();

                gameWon = checkWin();
                if (gameWon) {
                    cout << "Player " << currentPlayer << " wins!\n";
                } else {
                    gameDraw = checkDraw();
                    if (gameDraw) {
                        cout << "It's a draw!\n";
                    } else {
                        switchPlayer();
                    }
                }
            } else {
                cout << "Invalid move. Try again.\n";
            }
        } else {
            cout << "Invalid input. Enter a number between 1 and 9.\n";
        }
    }

    return 0;
}
