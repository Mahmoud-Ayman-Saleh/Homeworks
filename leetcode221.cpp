#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <cassert>
using namespace std;

const int MAX = 300 + 1;
int memory[MAX][MAX];
vector<vector<char>> matrix;

class Solution
{
private:

    int dp(int r, int c)
    {
        if (r < 0 || c < 0 || r >= matrix.size() || c >= matrix[0].size() || matrix[r][c] == '0')
        {
            return 0;	// invalid or no cell 
        }

        auto &ret = memory[r][c];
        if (ret != -1) return ret;

        int right = dp(r, c+1);
        int down = dp(r+1, c);
        int diagonal = dp(r+1, c+1);
        
        ret = 1 + min(diagonal, min(right, down));
        return ret;
    }

public:
    int maximalSquare(vector<vector<char>>& _matrix)
    {
        matrix = _matrix;
		memset(memory, -1, sizeof(memory));

        int side = 0;

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                side = max(side, dp(i, j));
            }
        }

        return side * side;
    }
};

