#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm> // Added to use the max function
using namespace std;

const int MAX = 100 + 1;
int memory[MAX][2];
vector<int> arr;

enum
{
    NOTHING = 0, ROBBING = 1
};

class Solution
{
public:

    int dp(int idx, int prev_action)
    {
        if (idx == arr.size()) return 0;
        auto &ret = memory[idx][prev_action];
        if (ret != -1) return ret;

        int do_nothing = dp(idx+1, NOTHING);
        int robbing = 0;
        if (prev_action == NOTHING)
        {
            robbing = arr[idx] + dp(idx+1, ROBBING);
        }
        ret = max(do_nothing, robbing);
        return ret;

    }

    int rob(vector<int>& nums)
    {
        arr = nums;
        memset(memory, -1, sizeof(memory));
        return dp(0, NOTHING);
    }
};