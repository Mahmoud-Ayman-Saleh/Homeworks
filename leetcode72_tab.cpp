#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <cassert>
#include <numeric>
using namespace std;
const int MAX = 1000+3;
int memory[MAX][MAX];


class Solution
{
private:
    int answer(int i, int j)
    {
        if (i == -1) return j+1;
        if (j == -1) return i+1;
        assert(memory[i][j] != -1);
        return memory[i][j];
    }
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size(), m = word2.size();
        memset(memory, -1, sizeof(memory));
        if (n == 0 || m == 0) return max(n, m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (word1[i] == word2[j])
                {
                    memory[i][j] = answer(i-1, j-1);
                }
                else
                {
                    int change = 1 + answer(i-1, j-1);
                    int _delete = 1 + answer(i, j-1);
                    int insert = 1 + answer(i-1, j);

                    memory[i][j] = min(min(_delete, insert), change);
                }
            }
        }

        return memory[n-1][m-1];
    }
};