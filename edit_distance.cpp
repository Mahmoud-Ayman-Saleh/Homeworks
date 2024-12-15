#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <cassert>
#include <numeric>
using namespace std;
string s1, s2;
const int MAX = 500;
int memory[MAX][MAX];

class Solution
{
public:

    int edit(int i, int j)
    {
        if (i == s1.size()) return s2.size() - j;
        if (j == s2.size()) return s1.size() - i;

        auto &ans = memory[i][j];

        if (ans != -1) return ans;

        if (s1[i] == s2[j])
        {
            ans = edit(i+1, j+1);
            return ans;
        }

        int change = 1 + edit(i+1, j+1);
        int _delete = 1 + edit(i, j+1);
        int insert = 1 + edit(i+1, j);

        ans = min(min(_delete, insert), change);
        return ans;
    }

    int minDistance(string word1, string word2)
    {
        s1 = word1;
        s2 = word2;
        memset(memory, -1, sizeof(memory));
        return edit(0, 0);
    }
};