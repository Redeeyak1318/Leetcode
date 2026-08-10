class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int top_area = 0;
        int side_area = 0;
        int front_area = 0;

        for (int i = 0; i < n; i++) {
            int row_max = 0;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    top_area++;
                }
                row_max = std::max(row_max, grid[i][j]);
            }
            side_area += row_max;
        }

        for (int j = 0; j < n; j++) {
            int col_max = 0;
            for (int i = 0; i < n; i++) {
                col_max = std::max(col_max, grid[i][j]);
            }
            front_area += col_max;
        }

        return top_area + side_area + front_area;
    }
};