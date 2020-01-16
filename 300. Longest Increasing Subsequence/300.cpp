/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?
*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:

    int lengthOfLIS(vector<int>& nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }

        vector<int> dp(nums.size(), 1);
        int longest = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            int len = 0;
            for (int k = i - 1; k >= 0; k--)
            {
                if (nums[i] > nums[k])
                {
                    len = len > dp[k] ? len : dp[k];
                }
            }
            dp[i] = len + 1;
            longest = longest > dp[i] ? longest : dp[i];
        }
        
        return longest;
    }
};

int main()
{
    auto sol = new Solution();
    //cout << sol->lengthOfLIS(vector<int>{-2, -1}) << endl;
    cout << sol->lengthOfLIS(vector<int>{10, 9, 2, 5, 3, 7, 101, 18}) << endl;
}
