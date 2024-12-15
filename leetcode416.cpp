#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <cassert>
#include <numeric>
using namespace std;

vector<int> numList;
const int MAX_N = 200; // Max N = 500, for safe indexing
const int MAX_T = 100*200+1; // Max Target = 2000
int memory[MAX_N][MAX_T];


class Solution
{
public:

    bool dp(int idx, int remain)
    {
        if (remain < 0) return false;
        if (remain == 0) return true;
        if (idx == numList.size() && remain != 0) return false;

        auto &ret = memory[idx][remain];
        if (ret != -1)
        {
            return ret;
        }

        ret = dp(idx + 1, remain) || dp(idx+1, remain - numList[idx]);
        return ret;
    }


    bool canPartition(vector<int>& nums)
    {
        numList = nums;
        memset(memory, -1, sizeof(memory));
        int total_sum = accumulate(numList.begin(), numList.end(), 0);
        if (total_sum % 2 != 0)
        {
            return false;
        }

        return dp(0, total_sum/2);
    }
};
