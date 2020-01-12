/*
Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
 /  \
15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
*/

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
#if 0
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) return 0;

        using QueueNode = pair<TreeNode *, bool>;
        queue<QueueNode> q;

        q.push(make_pair(root, false));

        int sum = 0;

        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                auto node = q.front();
                q.pop();

                if (node.first->left != nullptr)
                {
                    q.push(make_pair(node.first->left, true));
                }
                if (node.first->right != nullptr)
                {
                    q.push(make_pair(node.first->right, false));
                }

                if (node.first->left == nullptr && node.first->right == nullptr)
                {
                    if (node.second)
                    {
                        sum += node.first->val;
                    }
                }
            }
        }

        return sum;
    }
#else
    int sumOfLeftLeaves(TreeNode* root, bool isLeft)
    {
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr)
        {
            if (isLeft)
            {
                return root->val;
            }
            else
            {
                return 0;
            }
        }

        return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
    }

    int sumOfLeftLeaves(TreeNode* root)
    {
        return sumOfLeftLeaves(root, false);
    }
#endif
};

int main()
{

}