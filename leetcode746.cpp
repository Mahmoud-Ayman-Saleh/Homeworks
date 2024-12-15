#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <cassert>
#include <numeric>
using namespace std;

const int MAX = 1000 + 1;
int memory[MAX];
vector<int> _cost;

class Solution
{
public:

    int dp(int idx)
    {
        if (idx >= _cost.size()) return 0;

        auto &ans = memory[idx];
        if (ans != -1) return ans;

        ans = _cost[idx] + min(dp(idx+1), dp(idx+2));
        return ans;
    }


    int minCostClimbingStairs(vector<int>& cost)
    {
        _cost = cost;
        memset(memory, -1, sizeof(memory));
        return min(dp(0), dp(1));
    }
};