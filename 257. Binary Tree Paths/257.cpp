/*
Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3
*/

#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    void dfs(TreeNode *root, string pre, vector<string> &result)
    {
        if (root == nullptr)
        {
            return;
        }

        pre += "->" + to_string(root->val);
        if (root->left == nullptr && root->right == nullptr)
        {
            result.push_back(pre.substr(2, -1));
            return;
        }

        dfs(root->left, pre, result);
        dfs(root->right, pre, result);

    }
    vector<string> binaryTreePaths(TreeNode* root)
    {
        vector<string> result;
        dfs(root, "", result);

        return result;
    }
};

int main()
{
    return 0;
}