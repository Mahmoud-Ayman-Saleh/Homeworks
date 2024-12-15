#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
using namespace std;

const int MOD = 1000000007;

const int MAX = 50 + 1;
int memory[MAX][MAX][MAX];
int rows, cols, max_moves;



class Solution
{
private:
    int dp(int r, int c, int moves)
    {
        if (moves > max_moves) return 0;
        if (r < 0 || r >= rows || c < 0 || c >= cols) return 1;

        auto &ret = memory[r][c][moves];
        if (ret != -1) return ret;

        ret = 0;

        ret += dp(r, c - 1, moves + 1);
        ret %= MOD;
        
        ret += dp(r, c + 1, moves + 1);
        ret %= MOD;	// apply after each step

        ret += dp(r + 1, c, moves + 1);
        ret %= MOD;

        ret += dp(r - 1, c, moves + 1);
        ret %= MOD;

        return ret;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        rows = m, cols = n, max_moves = maxMove;
		memset(memory, -1, sizeof(memory));
		return dp(startRow, startColumn, 0);
    }
};