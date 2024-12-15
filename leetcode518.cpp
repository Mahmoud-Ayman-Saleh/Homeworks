#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <cassert>
using namespace std;

const int MAX_N = 300+1;
const int MAX_T = 5000 + 1;
int memory[MAX_N][MAX_T];

vector<int> arr;



class Solution
{

private:
    int dp(int idx, int amount)
    {
        if (amount < 0) return 0;
        if (amount == 0) return 1;
        if (idx == arr.size()) return 0;

        auto &ret = memory[idx][amount];
        if (ret != -1) return ret;

        int take = dp(idx, amount - arr[idx]);
        int leave = dp(idx+1, amount);

        ret = take + leave;
        return ret;
    }

public:
    int change(int amount, vector<int>& coins)
    {
        arr = coins;
        memset(memory, -1, sizeof(memory));
        return dp(0, amount);
    }
};

int main()
{
    Solution solution;
    vector<int> coins = {1, 2, 5};
    cout << solution.change(5, coins) << endl;
}


