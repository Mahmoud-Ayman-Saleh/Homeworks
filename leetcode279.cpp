#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <cassert>
#include <numeric>
using namespace std;
const int MAX = 10000+1;
int memory[MAX];


class Solution
{
public:

    int dp(int n)
    {
        if (n <= 0) return 0;

        auto &ans = memory[n];
        if (ans != -1) return ans;

        ans = INT_MAX;

        for (int i = 1; i*i <= n; i++)
        {
            ans = min(ans,1+ dp(n - i*i));
        }

        return ans;
    }

    int numSquares(int n)
    {
        memset(memory, -1, sizeof(memory));
        return dp(n);
    }
};