#include <iostream>
#include <vector>
#include <stack>
using namespace std;


/*Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1, null, 2, 3]
	1
	\
	2
	/
	3

	Output: [1, 3, 2]
	Follow up : Recursive solution is trivial, could you do it iteratively ?
*/


struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:
#if 0
	vector<int> inorderTraversal(TreeNode* root)
	{
		vector<int> result;

		if (root == NULL) return result;

		result = this->inorderTraversal(root->left);
		
		result.push_back(root->val);

		auto res = this->inorderTraversal(root->right);
		
		result.insert(result.end(), res.begin(), res.end());

		return result;
	}
#else
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> result;
        stack<TreeNode *> st;
        TreeNode *p = root;

        while (!st.empty() || p != nullptr)
        {
            if (p != nullptr)
            {
                st.push(p);
                p = p->left;
            }
            else
            {
                p = st.top(), st.pop();
                result.push_back(p->val);
                p = p->right;
            }
        }
        return result;
    }
#endif
};

int main()
{
	auto sol = new Solution();
	TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(4);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(3);

	auto res = sol->inorderTraversal(root);
	for (auto r : res)
	{
		cout << r << " ";
	}
	cout << endl;
}