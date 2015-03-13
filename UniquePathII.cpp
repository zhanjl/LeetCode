#include <iostream>
#include <vector>
using namespace std;
int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid)
{
    int solution[100];
    int m, n;
    m = obstacleGrid.size();
    n = obstacleGrid[0].size();
    
    //初始化第一行
    if (obstacleGrid[0][0] == 1) {
        solution[0] = 0;
    } else {
        solution[0] = 1;
    }
    for (int i = 1; i < n; i++) {
        if ((solution[i-1] == 1) && (obstacleGrid[0][i] == 0)) {
            solution[i] = 1;
        } else {
            solution[i] = 0;
        }
    }

    for (int i = 1; i < m; i++) {
        if ((solution[0] == 1) && (obstacleGrid[i][0] == 0)) {
            solution[0] = 1;
        } else {
            solution[0] = 0;
        }
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[i][j] == 1) {
                solution[j] = 0;
            } else {
                solution[j] += solution[j-1];
            }
        }
    }

    return solution[n-1];
}

int main()
{
    vector<vector<int> > grid;
    grid.push_back(vector<int>(1, 0));
    grid.push_back(vector<int>(1, 1));
    cout << uniquePathsWithObstacles(grid) << endl;
    return 0;
}
