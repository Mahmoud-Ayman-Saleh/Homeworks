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
        if (amount < 0) return INT_MAX;
        if (amount == 0) return 0;
        if (idx ==(int) arr.size()) return INT_MAX;

        auto &ret = memory[idx][amount];
        if (ret != -1) return ret;

        int take = dp(idx, amount - arr[idx]);
        int leave = dp(idx+1, amount);

         if (take != INT_MAX)
        {
            take += 1;
        }

        // We return the minimum of taking the coin or skipping it
        ret = min(take, leave);

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
    int amount = 8;
    vector<int> coins = {1, 2, 5};
    cout << solution.change(amount, coins) << endl;
}