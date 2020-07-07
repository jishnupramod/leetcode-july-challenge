/*
You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). 
The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes" (water inside that isn't connected to the water around the island). 
One cell is a square with side length 1. 
The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

 

Example:

Input:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Output: 16
*/


class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int pm = 0;
        int rows = grid.size(); 
        int cols = grid[0].size();
        for (int i=0; i<rows; ++i) {
            for (int j=0; j<cols; ++j) {
                if (grid[i][j] == 1) {
                    pm += 4;
                    if (i > 0 and grid[i-1][j] == 1)
                        --pm;
                    if (i < rows-1 and grid[i+1][j] == 1)
                        --pm;
                    if (j > 0 and grid[i][j-1] == 1)
                        --pm;
                    if (j < cols-1 and grid[i][j+1] == 1)
                        --pm;
                }
            }
        }
        return pm;
    }
};
