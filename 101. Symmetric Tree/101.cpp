/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3


But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3


Note:
Bonus points if you could solve it both recursively and iteratively.
*/

#include <queue>
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
    bool isSymmetric(TreeNode* r1, TreeNode*r2)
    {
        if (r1 == nullptr && r2 == nullptr) return true;
        if (r1 == nullptr) return false;
        if (r2 == nullptr) return false;

        if (r1->val != r2->val) return false;

        return isSymmetric(r1->left, r2->right) && isSymmetric(r1->right, r2->left);
    }

    bool isSymmetric(TreeNode* root)
    {
        return isSymmetric(root, root);
    }
#else
    bool isSymmetric(TreeNode* root)
    {
        if (root == nullptr) return true;

        TreeNode *left = root->left;
        TreeNode *right = root->right;

        vector<TreeNode *> q;
        q.push_back(root);

        while (!q.empty())
        {
            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                left = q[i];
                right = q[size - i - 1];

                if (left->val != right->val)
                    return false;

                if (left->left != nullptr && right->right != nullptr)
                {
                    q.push_back(left->left);
                }

                if (left->right != nullptr && right->left != nullptr)
                {
                    q.push_back(left->right);
                }

                if (left->left != nullptr && right->right == nullptr) return false;
                if (left->left == nullptr && right->right != nullptr) return false;

                if (left->right != nullptr && right->left == nullptr) return false;
                if (left->right == nullptr && right->left != nullptr) return false;
                    
            }
            q.erase(q.begin(), q.begin() + size);
        }
        return true;
    }
#endif
};

int main()
{
    auto sol = new Solution();
 
   /* auto root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    */
    auto root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(3);
    

    cout << sol->isSymmetric(root) << endl;
}