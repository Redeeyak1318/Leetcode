int projectionArea(int** grid, int gridSize, int* gridColSize) {
    int top_area = 0;
    int side_area = 0;
    int front_area = 0;

    for (int i = 0; i < gridSize; i++) {
        int row_max = 0;
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] > 0) {
                top_area++;
            }
            row_max = MAX(row_max, grid[i][j]);
        }
        side_area += row_max;
    }

    for (int j = 0; j < gridColSize[0]; j++) {
        int col_max = 0;
        for (int i = 0; i < gridSize; i++) {
            col_max = MAX(col_max, grid[i][j]);
        }
        front_area += col_max;
    }

    return top_area + side_area + front_area;
}