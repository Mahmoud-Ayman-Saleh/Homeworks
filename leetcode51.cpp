#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<bool> columns, normal_diagonal, anti_diagonal;
vector<string> empty_grid;
vector<vector<string>> solutions;

class Solution
{
void backtracking(int r)
{
    if (r == n)
    {
        solutions.push_back(empty_grid);
        return;
    }
    for (int c = 0; c < n; c++)
    {
        int x = r+c;
        int y = n - 1+ r-c;
        if (columns[c] || normal_diagonal[y] || anti_diagonal[x]) continue;

        empty_grid[r][c] = 'Q';
        columns[c] = normal_diagonal[y] = anti_diagonal[x] = true;
        backtracking(r+1);
        columns[c] = normal_diagonal[y] = anti_diagonal[x] = false;
        empty_grid[r][c] = '.';
    }
}
public:
    vector<vector<string>> solveNQueens(int _n)
    {
        n = _n;
        columns = vector<bool>(n);
        normal_diagonal = vector<bool>(2 * n - 1);
        anti_diagonal = vector<bool>(2 * n - 1);
        empty_grid = vector<string>(n, string(n, '.'));
        backtracking(0);
        return solutions;
    }
};