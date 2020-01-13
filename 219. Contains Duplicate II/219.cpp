/*
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false
*/

#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

// 根据提议，下标差的绝对值不大于k

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> status;
        for (int i = 0; i < nums.size(); i++)
        {
            if (status.find(nums[i]) != status.end())
            {
                if (i - status[nums[i]] <= k)
                {
                    return true;
                }
                else
                {
                    status[nums[i]] = i;
                }
            }
            else
            {
                status[nums[i]] = i;
            }
        }
        return false;
    }
};

int main()
{
    auto sol = new Solution();
    vector<int> nums{ 1,2,3,1,2,3 };
    cout << sol->containsNearbyDuplicate(nums, 2) << endl;
}