
void DFS(vector<vector<char> > &grid, int i, int j)
{
    grid[i][j] = '0';

    if ((i - 1) >= 0 && grid[i-1][j] == '1')
        DFS(grid, i - 1, j);
    if ((j + 1) < grid[0].size() && grid[i][j+1] == '1')
        DFS(grid, i, j + 1);
    if ((i + 1) < grid.size() && grid[i+1][j] == '1')
        DFS(grid, i + 1, j);

    if ((j - 1) >= 0 && grid[i][j-1] == '1')
        DFS(grid, i, j - 1);

    return;
}

int numIslands(vector<vector<char> > &grid) 
{
    int cnt = 0;
    
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == '1') {
                cnt++;
                DFS(grid, i, j);
            }
        }
    }

    return cnt;
}
