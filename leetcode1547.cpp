#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

const int MAX = 100 + 2 + 1;
int memory[MAX][MAX];

vector<int> cuts;


class Solution
{
public:

    int dp(int start, int end)
    {
        if (start + 1 == end)	// 2 Consecutive points. Nothing in between
		{
            return 0;  // No cuts
        }

        auto &ret = memory[start][end];
        if (ret != -1) return ret;

        ret = INT_MAX;

        for (int splits = start + 1; splits < end; splits++)
        {
            int left = dp(start, splits);
            int right = dp(splits, end);
            int cut_cost = cuts[end] - cuts[start];
            ret = min(ret, cut_cost + right + left);
        }

        return ret;
    }

    int minCost(int n, vector<int>& _cuts)
    {
        cuts = _cuts;
		cuts.push_back(0); // trick
		cuts.push_back(n); // trick
		sort(cuts.begin(), cuts.end()); // trick

		memset(memory, -1, sizeof(memory));

		return dp(0, (int) cuts.size() - 1);
    }
};

int main()
{
    Solution s;
    vector<int> arr = {1, 3, 4, 5};
    cout << s.minCost(7 ,arr);
}