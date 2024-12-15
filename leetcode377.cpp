#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <cassert>
using namespace std;

const int MAX_T = 5000 + 1;
int memory[MAX_T];
vector<int> arr;

class Solution
{

private:

    int dp(int target)
    {
        if (target < 0) return 0;
        if (target == 0) return 1;

        auto &ret = memory[target];
        if (ret != -1) return ret;


        ret = 0;
        for (auto &i : arr)
        {
            ret += dp(target - i);
        }

        return ret;
    }

public:
    int combinationSum4(vector<int>& nums, int target)
    {
        arr = nums;
		memset(memory, -1, sizeof(memory));
        return dp(target);
    }
};

int main()
{
    Solution s;
    vector<int> v = {1, 2, 3};
    cout << s.combinationSum4(v, 4);
}