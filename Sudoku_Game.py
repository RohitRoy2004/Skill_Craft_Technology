N = 9

# Print Sudoku grid
def print_grid(grid):
    print("\n------ Sudoku Board ------")
    for i in range(N):
        if i % 3 == 0 and i != 0:
            print("-------------------------")
        for j in range(N):
            if j % 3 == 0 and j != 0:
                print(" | ", end="")
            if grid[i][j] == 0:
                print(". ", end="")
            else:
                print(f"{grid[i][j]} ", end="")
        print()

# Check if placing num is valid
def is_safe(grid, row, col, num):
    # Row and column check
    for x in range(N):
        if grid[row][x] == num or grid[x][col] == num:
            return False

    # 3x3 box check
    start_row = row - row % 3
    start_col = col - col % 3
    for i in range(3):
        for j in range(3):
            if grid[start_row + i][start_col + j] == num:
                return False
    return True

# Check if Sudoku is completely filled
def is_completed(grid):
    for i in range(N):
        for j in range(N):
            if grid[i][j] == 0:
                return False
    return True

def main():
    # Initial puzzle (0 = empty cell)
    grid = [
        [5,3,0, 0,7,0, 0,0,0],
        [6,0,0, 1,9,5, 0,0,0],
        [0,9,8, 0,0,0, 0,6,0],

        [8,0,0, 0,6,0, 0,0,3],
        [4,0,0, 8,0,3, 0,0,1],
        [7,0,0, 0,2,0, 0,0,6],

        [0,6,0, 0,0,0, 2,8,0],
        [0,0,0, 4,1,9, 0,0,5],
        [0,0,0, 0,8,0, 0,7,9]
    ]

    print("Welcome to Sudoku Game!")
    print("Enter moves in format: row col number (e.g., 1 3 4)")
    print("Type 0 0 0 to quit.")

    while True:
        print_grid(grid)

        try:
            r, c, num = map(int, input("\nYour Move (row col number): ").split())
        except ValueError:
            print("❌ Invalid input! Enter three numbers.")
            continue

        if r == 0 and c == 0 and num == 0:
            print("Game exited!")
            break

        # Validate input
        if r < 1 or r > 9 or c < 1 or c > 9 or num < 1 or num > 9:
            print("❌ Invalid input! Use 1-9 only.")
            continue

        # Adjust for 0-indexing
        r -= 1
        c -= 1

        if grid[r][c] != 0:
            print("❌ Cell already filled! Choose another.")
            continue

        if is_safe(grid, r, c, num):
            grid[r][c] = num
            print("✅ Move accepted!")
        else:
            print("❌ Invalid move! Rule broken.")

        if is_completed(grid):
            print("\n🎉 Congratulations! You completed the Sudoku!")
            print_grid(grid)
            break

if __name__ == "__main__":
    main()
