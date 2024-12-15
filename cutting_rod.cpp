#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_N = 300 + 1;
const int MAX_T = 5000 + 1;
int memory[MAX_N][MAX_T];
vector<int> arr;  // Global array for prices
int n;            // Global rod length

class Solution
{
private:
    int dp(int idx, int len)
    {
        if (len == 0) return 0;  // No rod left to cut
        if (idx > n) return 0;   // No more pieces to consider

        auto &ret = memory[idx][len];
        if (ret != -1) return ret;

        // Option 1: Skip current length
        int leave = dp(idx + 1, len);

        // Option 2: Take current length if possible
        int take = 0;
        if (len >= idx) take = arr[idx] + dp(idx, len - idx);

        ret = max(leave, take);  // Choose the better option
        return ret;
    }

public:
    int cutting_rod()
    {
        memset(memory, -1, sizeof(memory));  // Reset memory
        return dp(1, n);
    }
};

int main()
{
    cin >> n;
    arr.resize(n + 1);  // Resize to include prices 1 through n
    for (int i = 1; i <= n; ++i) cin >> arr[i];

    Solution s;
    cout << s.cutting_rod() << endl;
}
