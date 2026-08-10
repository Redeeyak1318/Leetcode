class Solution:
    def projectionArea(self, grid: List[List[int]]) -> int:
        n = len(grid)
        top_area = 0
        side_area = 0
        front_area = 0
        
        for i in range(n):
            row_max = 0
            for j in range(n):
                if grid[i][j] > 0:
                    top_area += 1
                if grid[i][j] > row_max:
                    row_max = grid[i][j]
            side_area += row_max
            

        for j in range(n):
            col_max = 0
            for i in range(n):
                if grid[i][j] > col_max:
                    col_max = grid[i][j]
            front_area += col_max
            
        return top_area + side_area + front_area