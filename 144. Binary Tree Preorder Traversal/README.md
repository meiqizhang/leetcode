##二叉树先序遍历非递归算法

    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> result;
        stack<TreeNode *> st;
        TreeNode *p = root;

        while (!st.empty() || p != nullptr)
        {
            if (p != nullptr)
            {
                result.push_back(p->val);
                st.push(p);
                p = p->left;
            }
            else
            {
                p = st.top(), st.pop();
                p = p->right;
            }
        }

        return result;
    }

`if`首先访问到的跟节点，所以先visit，由于后面在访问右子树时还需要跟节点，所以先将跟节点入栈，紧接循环着访问左子树。当`else`时表明左子树已经完成访问，所以取栈顶，访问右子树
