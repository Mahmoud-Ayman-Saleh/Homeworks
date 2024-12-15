#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <cassert>
using namespace std;

const int MAX_N = 30 + 1;
const int MAX_I = 30 + 1;
const int MAX_T = 1000 + 1;
int memory[MAX_N][MAX_T][MAX_I];
vector<int> arr;


class Solution 
{
private:

    int dp(int idx, int n, int target)
    {
        if (target < 0) return 0;
        if (target == 0) return 1;
        if (n == 0) return 0;

        auto &ret = memory[idx][n][target];
        if (ret != -1) return ret;
        

        ret = 0;
        for (auto &i : arr)
        {
            ret += dp(idx+1, n-1, target-i);
        }
        return ret;
    }

public:
    int numRollsToTarget(int n, int k, int target)
    {
        for (int i = 1; i <= k; i++)
        {
            arr.push_back(i);
        }

        memset(memory, -1, sizeof(memory));
        return dp(0 ,n, target);
    }
};