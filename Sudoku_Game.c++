#include <bits/stdc++.h>
using namespace std;

#define N 9

// Print Sudoku grid
void printGrid(int grid[N][N]) {
    cout << "\n------ Sudoku Board ------\n";
    for (int i = 0; i < N; i++) {
        if (i % 3 == 0 && i != 0) cout << "-------------------------\n";
        for (int j = 0; j < N; j++) {
            if (j % 3 == 0 && j != 0) cout << " | ";
            if (grid[i][j] == 0) cout << ". ";
            else cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

// Check if placing num in grid[row][col] is valid
bool isSafe(int grid[N][N], int row, int col, int num) {
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num || grid[x][col] == num) return false;
    }
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) return false;
        }
    }
    return true;
}

// Check if Sudoku is completely filled
bool isCompleted(int grid[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (grid[i][j] == 0) return false;
    return true;
}

int main() {
    // Initial puzzle (0 = empty cell)
    int grid[N][N] = {
        {5,3,0, 0,7,0, 0,0,0},
        {6,0,0, 1,9,5, 0,0,0},
        {0,9,8, 0,0,0, 0,6,0},

        {8,0,0, 0,6,0, 0,0,3},
        {4,0,0, 8,0,3, 0,0,1},
        {7,0,0, 0,2,0, 0,0,6},

        {0,6,0, 0,0,0, 2,8,0},
        {0,0,0, 4,1,9, 0,0,5},
        {0,0,0, 0,8,0, 0,7,9}
    };

    cout << "Welcome to Sudoku Game!\n";
    cout << "Enter moves in format: row col number (e.g., 1 3 4)\n";
    cout << "Type 0 0 0 to quit.\n";

    while (true) {
        printGrid(grid);

        int r, c, num;
        cout << "\nYour Move (row col number): ";
        cin >> r >> c >> num;

        if (r == 0 && c == 0 && num == 0) {
            cout << "Game exited!\n";
            break;
        }

        // Validate input
        if (r < 1 || r > 9 || c < 1 || c > 9 || num < 1 || num > 9) {
            cout << "❌ Invalid input! Use 1-9 only.\n";
            continue;
        }

        // Adjust for 0-indexing
        r--; c--;

        if (grid[r][c] != 0) {
            cout << "❌ Cell already filled! Choose another.\n";
            continue;
        }

        if (isSafe(grid, r, c, num)) {
            grid[r][c] = num;
            cout << "✅ Move accepted!\n";
        } else {
            cout << "❌ Invalid move! Rule broken.\n";
        }

        if (isCompleted(grid)) {
            cout << "\n🎉 Congratulations! You completed the Sudoku!\n";
            printGrid(grid);
            break;
        }
    }

    return 0;
}
