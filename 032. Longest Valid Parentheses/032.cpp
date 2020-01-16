/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
Example 2:

Input: ")()())"
Output: 4
Ex
*/

#include <vector>
#include <string>
#include <iostream>

using namespace std;

/*          dp[i-1] + 2  if A[i] == ')' && A[i-dp[i-1]-1] == '('
           / 
    dp[i]=   0           if A[i] != ')'
           \
            dp[i-1] + 2 + dp[i-dp[i-1]-1] + dp[i-dp[i-2]-1]  if A[i] == ')' && A[i-dp[i-1]-1] == '('
*/
class Solution {
public:
    int longestValidParentheses(string s)
    {
        if (s.size() < 2) return 0;

        vector<int> dp(s.size(), 0);
        int longest = 0;

        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == ')')
            {
                int k = i - dp[i - 1];
                if (k > 0)
                {
                    if (s[k - 1] == '(')
                    {
                        dp[i] = dp[i - 1] + 2;
                        if (k - 2 >= 0) //这个if一定是嵌套在上层if里面的
                        {
                            dp[i] += dp[k - 2];
                        }
                    }
                }
            }

            longest = longest > dp[i] ? longest : dp[i];
        }
        return longest;
    }
};

int main()
{
    auto sol = new Solution();
    //cout << sol->longestValidParentheses(")()())") << endl;
    cout << sol->longestValidParentheses("()()))))()()(") << endl;
}