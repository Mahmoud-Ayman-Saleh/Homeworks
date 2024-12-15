#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <cassert>
#include <numeric>
using namespace std;
const int MAX = 5000 + 1;
int memory[MAX][2][3];
vector<int> arr;

enum
{
    NOTHING = 0, BUY = 1, SELL = 2
};

class Solution 
{
public:

    int dp(int idx, int have_stock, int last_transaction)
    {
        if (idx == arr.size()) return 0;

        auto &ans = memory[idx][have_stock][last_transaction];
		if (ans != -1) return ans;

        int cooldown = dp(idx + 1, have_stock, NOTHING);
        int buy = 0, sell = 0;

        if (have_stock)
        {
            sell = arr[idx] + dp(idx+1, 0, SELL);
        }
        else if (last_transaction != SELL)
        {
            buy = -arr[idx] + dp(idx+1, 1, BUY);
        }
        ans = max(max(sell, buy), cooldown);
        return ans;
    }

    int maxProfit(vector<int>& prices)
    {
        arr = prices;
        memset(memory, -1, sizeof(memory));
        return dp(0, 0, NOTHING);
    }
};