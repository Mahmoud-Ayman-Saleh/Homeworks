#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <string>
using namespace std;

const int MAX = 100 + 1;
int memory[MAX];
string text;


class Solution
{

private:

    int can2digits(int idx)
    {
        if (idx + 1 >= text.size()) return false;
        int value = stoi(text.substr(idx, 2));
        return 1 <= value && value <= 26;
    }

    int dp(int idx)
    {
        if (idx == (int) text.size()) return 1;

        if (text[idx] == '0') return 0;

        auto &ret = memory[idx];
        if (ret != -1) return ret;

        ret = dp(idx + 1);
        if (can2digits(idx))
        {
            ret += dp(idx + 2);
        }
        return ret;
    }

public:

    int numDecodings(string s)
    {
        text = s;
        memset(memory, -1, sizeof(memory));
        return dp(0);
    }
};