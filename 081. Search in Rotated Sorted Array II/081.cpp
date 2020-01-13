/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

You are given a target value to search. If found in the array return true, otherwise return false.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
Follow up:

This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
Would this affect the run-time complexity? How and why?
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool search(vector<int>& nums, int target)
    {
        if (nums.size() < 1) return false;

        int low = 0;
        int high = nums.size() - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
            {
                return true;
            }

            if (nums[mid] == nums[low] && nums[mid] == nums[high])
            {
                for (int i = low; i < high; i++)
                {
                    if (nums[i] == target)
                    {
                        return true;
                    }
                }
                return false;
            }

            if (nums[mid] >= nums[low]) //×ó¶ËÓÐÐò
            {
                if (target >= nums[low] && target <= nums[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else
            {
                if (target >= nums[mid] && target <= nums[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};

int main()
{
    auto sol = new Solution();
    //vector<int>nums{ 2,5,6,0,0,1,2 };
    vector<int>nums{ 1,3,1,1,1 };
    for (auto n : nums)
    {
        cout << sol->search(nums, n) << endl;
    }
}