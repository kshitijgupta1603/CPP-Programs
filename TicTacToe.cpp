#include <iostream>
#include <vector>

using namespace std;

// Function to display the Tic-Tac-Toe board

void displayBoard(const vector<vector<char>>& board) {
    cout << "\nTic-Tac-Toe Game\n\n";
    cout << "Player 1 (X) - Player 2 (O)\n\n";
    // cout << "  1 | 2 | 3 \n";
    // cout << " ---|---|---\n";
    cout << "  " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " \n";
    cout << " ---|---|---\n";
    cout << "  " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " \n";
    cout << " ---|---|---\n";
    cout << "  " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " \n";
    // cout << "    |   |   \n";
}

// Function for a player's turn

void playerTurn(vector<vector<char>>& board, char& turn) {
    int choice;
    int row, col;

    if (turn == 'X') {
        cout << "\nPlayer 1's (X) turn: ";
    } else {
        cout << "\nPlayer 2's (O) turn: ";
    }
    cin >> choice;

    // Map the user input to the row and column

    switch (choice) {
        case 1: row = 0; col = 0; break;
        case 2: row = 0; col = 1; break;
        case 3: row = 0; col = 2; break;
        case 4: row = 1; col = 0; break;
        case 5: row = 1; col = 1; break;
        case 6: row = 1; col = 2; break;
        case 7: row = 2; col = 0; break;
        case 8: row = 2; col = 1; break;
        case 9: row = 2; col = 2; break;
        default:
            cout << "Invalid move! Try again.\n";
            playerTurn(board, turn);
            return;
    }

    // Check if the chosen cell is empty
    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = turn;
    } else {
        cout << "Box already filled! Try again.\n";
        playerTurn(board, turn);
    }
}

// Function to check if a player has won

bool checkWin(const vector<vector<char>>& board) {
    // Check rows
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return true;
        }
    }

    // Check columns

    for (int i = 0; i < 3; ++i) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return true;
        }
    }

    // Check diagonals

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return true;
    }

    return false;
}

// Function to check if the game is a draw

bool checkDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false; // There are still empty cells
            }
        }
    }
    return true; // No empty cells, it's a draw
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char turn = 'X';
    bool draw = false;

    cout << "Welcome to Tic-Tac-Toe!\n";

    while (true) {
        displayBoard(board);
        playerTurn(board, turn);

        // Check if the current player has won

        if (checkWin(board)) {
            displayBoard(board);
            cout << "\nPlayer " << turn << " wins!\n";
            break;
        }

        // Check for draw condition

        if (checkDraw(board)) {
            displayBoard(board);
            cout << "\nGame Over! It's a draw!\n";
            break;
        }

        // Switch player turn
        
        turn = (turn == 'X') ? 'O' : 'X';
    }

    return 0;
}