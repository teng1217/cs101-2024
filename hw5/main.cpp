#include <iostream>
#include <vector>

class TicTacToe {
private:
    std::vector<std::vector<char>> board; // 棋盤
    int currentPlayer; // 當前玩家（1 或 2）
    bool gameEnd; // 遊戲是否結束

public:
    TicTacToe() {
        board = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
        currentPlayer = 1;
        gameEnd = false;
    }

    void printBoard() {
    std::cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " \n";
    std::cout << "---+---+---\n";
    std::cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " \n";
    std::cout << "---+---+---\n";
    std::cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " \n";
}


    bool isValidMove(int move) {
        if (move < 1 || move > 9) {
            std::cout << "Invalid value, please enter again\n";
            return false;
        }
        int row = (move - 1) / 3;
        int col = (move - 1) % 3;
        if (board[row][col] == 'X' || board[row][col] == 'O') {
            std::cout << "==> Invalid value, please enter again\n";
            return false;
        }
        return true;
    }

    void makeMove(int move) {
        char symbol = (currentPlayer == 1) ? 'X' : 'O';
        int row = (move - 1) / 3;
        int col = (move - 1) % 3;
        board[row][col] = symbol;
    }

    bool checkWin(char symbol) {
        // Check rows, columns, and diagonals for a win
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) return true; // Row
            if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) return true; // Column
        }
        if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) return true; // Diagonal
        if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) return true; // Diagonal
        return false;
    }

    void run() {
        std::cout << "-- Tic Tac Toe -- CSIE@CGU\n";
        std::cout << "Player 1 (X) - Player 2 (O)\n";

        printBoard();
        int movesLeft = 9; // 初始可用的步數
        while (!gameEnd) {
            int move;
            std::cout << "==> Player " << currentPlayer << " (" << ((currentPlayer == 1) ? 'X' : 'O') << "), enter a number:";
            std::cin >> move;
            if (isValidMove(move)) {
                makeMove(move);
                printBoard();
                --movesLeft; // 每次合法移動後，可用步數減1
                if (checkWin((currentPlayer == 1) ? 'X' : 'O')) {
                    std::cout << "==> Player " << currentPlayer << " wins!\n";
                    gameEnd = true;
                } else if (movesLeft == 0) { // 所有步數用盡，並且沒有任何一方獲勝
                    std::cout << "==> Game draw\n";
                    gameEnd = true;
                } else if (currentPlayer == 1) {
                    currentPlayer = 2;
                } else {
                    currentPlayer = 1;
                }
            }
        }
    }


};

int main() {
    TicTacToe game;
    game.run();
    return 0;
}
