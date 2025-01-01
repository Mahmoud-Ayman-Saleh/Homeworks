#include <iostream>
#include <vector>
using namespace std;
vector<int> weight, value;


// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int W, vector<int>& wt, vector<int>& val) 
{
    int n = wt.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));

    // Build table dp[][] in bottom-up manner
    for (int i = 0; i <= n; i++) 
    {
        for (int remains = 0; remains <= W; remains++) 
        {
            if (i == 0 || remains == 0) 
            {
                dp[i][remains] = 0;
            }
            else if (wt[i - 1] <= remains) 
            {
                int choice1 = val[i - 1] + dp[i - 1][remains - wt[i - 1]];
                int choice2 = dp[i - 1][remains];
                dp[i][remains] = max(choice1, choice2);
            }
            else 
            {
                dp[i][remains] = dp[i - 1][remains];
            }
        }
    }
    return dp[n][W];
}

// Driver Code
int main() 
{
    int max_weight, n;
	cin >> max_weight>>n;

	weight.resize(n);
	value.resize(n);

	for (int i = 0; i < n; ++i)
	    cin>>weight[i]>>value[i];

    cout << knapSack(max_weight, weight, value) << endl;

    return 0;
}
