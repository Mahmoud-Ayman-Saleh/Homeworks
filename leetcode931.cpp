#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
using namespace std;


const int MAX = 100 + 1;
int memory[MAX][MAX];
vector<vector<int>> grid;


class Solution
{
private:
    int dp(int r, int c)
    {
        int rows = grid.size(), cols = grid[0].size();

        if (c < 0 || c >= cols) return INT_MAX / 2;

        if (r == rows - 1) return grid[r][c];

        auto &ret = memory[r][c];
        if (ret != -1) return ret;

        int p1 = dp(r + 1, c - 1);
        int p2 = dp(r + 1, c);
        int p3 = dp(r + 1, c + 1);

        return ret = grid[r][c] + min(min(p1, p2), p3);
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        grid = matrix;
		memset(memory, -1, sizeof(memory));

        int ans = INT_MAX;

        for (int j = 0; j < matrix.size(); j++)
        {
            ans = min(ans, dp(0, j));
        }
        return ans;
    }
};