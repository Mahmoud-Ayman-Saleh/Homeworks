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
    int answer(int r, int c, int moves)
    {
        if (moves == -1) return 0;
        if (r < 0 || r >= rows || c < 0 || c >= cols) return 1;
        return memory[r][c][moves];
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
		memset(memory, -1, sizeof(memory));
        rows = m, cols = n, max_moves = maxMove;

        for (int move = 0; move <= max_moves; move++)
        {
            for (int r = 0; r < rows; r++)
            {
                for (int c = 0; c < cols; c++)
                {
                    int ret = 0;

                    ret += answer(r, c - 1, move - 1);
                    ret %= MOD;
                    
                    ret += answer(r, c + 1, move - 1);
                    ret %= MOD;	// apply after each step

                    ret += answer(r + 1, c, move - 1);
                    ret %= MOD;

                    ret += answer(r - 1, c, move - 1);
                    ret %= MOD;

                    memory[r][c][move] = ret;

                }
            }
        }
        return answer(startRow, startColumn, maxMove);

    }
};