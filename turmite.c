#include <stdio.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 40

typedef enum { WHITE, BLACK } CellState;

typedef struct {
    int x;
    int y;
    int direction;
} Turmite;

void initializeGrid(CellState grid[WIDTH][HEIGHT]) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            grid[i][j] = WHITE;
        }
    }
}

void printGrid(const CellState grid[WIDTH][HEIGHT]) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            printf("%c", grid[i][j] == WHITE ? ' ' : '#');
        }
        printf("\n");
    }
}

void turmiteStep(Turmite *turmite, CellState grid[WIDTH][HEIGHT]) {
    int x = turmite->x;
    int y = turmite->y;

    if (grid[x][y] == WHITE) {
        grid[x][y] = BLACK;
        turmite->direction = (turmite->direction + 1) % 4;
    } else {
        grid[x][y] = WHITE;
        turmite->direction = (turmite->direction + 3) % 4;
    }

    switch (turmite->direction) {
        case 0: // Up
            turmite->y = (y - 1 + HEIGHT) % HEIGHT;
            break;
        case 1: // Right
            turmite->x = (x + 1) % WIDTH;
            break;
        case 2: // Down
            turmite->y = (y + 1) % HEIGHT;
            break;
        case 3: // Left
            turmite->x = (x - 1 + WIDTH) % WIDTH;
            break;
    }
}

int main() {
    CellState grid[WIDTH][HEIGHT];
    Turmite turmite = {WIDTH / 2, HEIGHT / 2, 0};

    initializeGrid(grid);

    for (int i = 0; i < 1000; i++) {
        turmiteStep(&turmite, grid);
    }

    printGrid(grid);

    return 0;
}

