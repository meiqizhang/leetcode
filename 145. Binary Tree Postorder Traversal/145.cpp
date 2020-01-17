/*
Given a binary tree, return the postorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
 1
  \
  2
 /
3

Output: [3,2,1]
Follow up: Recursive solution is trivial, could you do it iteratively?
*/
#include <iostream>
#include <stack>
#include <vector>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:

    void print(vector<int> &res)
    {
        for (auto iter : res)
        {
            cout << iter << " ";
        }
        cout << endl;
    }
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> result;
        if (root == nullptr)
        {
            return result;
        }

        using StackNode = pair<TreeNode *, bool>;
        stack<StackNode> st;
        StackNode p = make_pair(root, false);

        while (!st.empty() || p.first != nullptr)
        {
            if (p.first != nullptr)
            {
                st.push(p);
                p = make_pair(p.first->left, false);
            }
            else
            {
                StackNode &top = st.top();
                if (!top.second && top.first->right != nullptr)
                {
                    top.second = true;
                    p = make_pair(top.first->right, false);
                }
                else
                {
                    result.push_back(top.first->val);
                    st.pop();
                }
            }
        }
        return result;
    }
};

int main()
{
    auto sol = new Solution();
    auto root = new TreeNode(1);

    root->left = new TreeNode(4);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    sol->print(sol->postorderTraversal(root));
}