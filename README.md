#leetcode 刷题

    
###单链表中间节点
	if(head == NULL || head -> next == NULL) return head == NULL ? NULL : new TreeNode(head -> val);
	// 找到中间节点
	ListNode *f = head -> next -> next；
	ListNode *s = head;
	while(f != NULL && f -> next != NULL)
	{
    	f = f -> next -> next;
    	s = s -> next;
	}


###二叉树后序非递归遍历

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