#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_N = 30 + 1;
const int MAX_T = 1000 + 1;
const int MOD = 1000000007;

int k;

int memory[MAX_N][MAX_T];

class Solution 
{
private:
    int dp(int n, int target)
    {
        if (target < 0) return 0;
        if (target == 0 && n == 0) return 1; // valid choice
        if (n == 0 || target == 0) return 0; // invalid choice

        int &ret = memory[n][target];
        if (ret != -1) return ret;

        ret = 0;
        for (int i = 1; i <= k; ++i)
        {
            // trying the rest of dices
            ret = (ret + dp(n - 1, target - i)) % MOD;
        }
        return ret;
    }

public:
    int numRollsToTarget(int n, int k_, int target)
    {
        k = k_;
        memset(memory, -1, sizeof(memory));
        return dp(n, target);
    }
};


int main()
{
    Solution s;
    int n, k, target;
    cin >> n >> k >> target;
    cout << s.numRollsToTarget(n, k, target);
}
