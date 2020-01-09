/*
Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.

Examples:
Input: S = "a1b2"
Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

Input: S = "3z4"
Output: ["3z4", "3Z4"]

Input: S = "12345"
Output: ["12345"]
Note:

S will be a string with length between 1 and 12.
S will consist only of letters or digits.
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:

    void dfs(int index, string ans, vector<string> &result, const string &S)
    {
        if (ans.size() == S.size())
        {
            result.push_back(ans);
            return;
        }

        for (int i = index; i < S.size(); i++)
        {
            char ch = S.at(i);
            dfs(i + 1, ans + ch, result, S);

            if (ch >= 'A' && ch <= 'Z')
            {
                ch = ch - 'A' + 'a';
                dfs(i + 1, ans + ch, result, S);
            }
            else if (ch >= 'a' && ch <= 'z')
            {
                ch = ch - 'a' + 'A';
                dfs(i + 1, ans + ch, result, S);
            }
        }
    }
    vector<string> letterCasePermutation(string S) 
    {
        vector<string> result;
        dfs(0, "", result, S);
        return result;
    }
};

int main()
{
    auto sol = new Solution();
    auto result = sol->letterCasePermutation("a1b2C");
    for (auto res : result)
        cout << res << endl;

}