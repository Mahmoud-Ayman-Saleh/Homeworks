#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

typedef long long ll;

const int MAX = 100 + 1;
ll memory[MAX][MAX];
string str;

ll dp(int start, int end) 
{
    if (start > end) 
    {
        return 0;    // Base case: empty substring
    }
    if (start == end) 
    {
        return 1;    // Single character is a palindrome by itself
    }

    auto &ret = memory[start][end];
    if (ret != -1) 
    {
        return ret;
    }

    // Calculate number of palindromic subsequences for str[start...end]
    if (str[start] == str[end]) 
    {
        ret = 1 + dp(start + 1, end) + dp(start, end - 1);  // +1 for the new palindrome created
    } 
    else 
    {
        ret = dp(start + 1, end) + dp(start, end - 1) - dp(start + 1, end - 1); // Subtract overlapping part
    }
    return ret;
}

int main() 
{
    int t; 
    cin >> t;
    while (t--) 
    {
        cin >> str;
        memset(memory, -1, sizeof(memory));
        cout << dp(0, str.size() - 1) << "\n";
    }
    return 0;
}
