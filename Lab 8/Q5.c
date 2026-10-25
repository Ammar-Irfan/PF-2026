#include <stdio.h>

void printGrid(int (*grid)[5]) {
    int r, c;
    for (r = 0; r < 5; r++) {
        for (c = 0; c < 5; c++) {
            printf("%d", grid[r][c] & 1);
        }
        printf("\n");
    }
}

int countNeighbours(int (*grid)[5], int row, int col) {
    int count = 0;
    int dr, dc, nr, nc;
    for (dr = -1; dr <= 1; dr++) {
        for (dc = -1; dc <= 1; dc++) {
            if (dr == 0 && dc == 0) continue;
            nr = row + dr;
            nc = col + dc;
            if (nr >= 0 && nr < 5 && nc >= 0 && nc < 5) {
                count += (grid[nr][nc] & 1);
            }
        }
    }
    return count;
}

void nextGeneration(int (*grid)[5]) {
    int r, c, neighbours, current, alive;
    for (r = 0; r < 5; r++) {
        for (c = 0; c < 5; c++) {
            neighbours = countNeighbours(grid, r, c);
            current = grid[r][c] & 1;
            if (current == 1) {
                if (neighbours < 2 || neighbours > 3) {
                    alive = 0;
                } else {
                    alive = 1;
                }
            } else {
                if (neighbours == 3) {
                    alive = 1;
                } else {
                    alive = 0;
                }
            }
            grid[r][c] = current | (alive << 1);
        }
    }
    for (r = 0; r < 5; r++) {
        for (c = 0; c < 5; c++) {
            grid[r][c] >>= 1;
        }
    }
}

int main() {
    int gens, g, r, c;
    int grid[5][5] = {0};
    grid[1][2] = 1;
    grid[2][2] = 1;
    grid[3][2] = 1;

    while (1) {
        printf("Enter number of generations (0-50): ");
        if (scanf("%d", &gens) != 1) return 0;
        if (gens >= 0 && gens <= 50) break;
        printf("Invalid number\n");
    }

    for (g = 0; g <= gens; g++) {
        printf("Generation %d:\n", g);
        printGrid(grid);
        if (g < gens) {
            nextGeneration(grid);
        }
    }
    return 0;
}