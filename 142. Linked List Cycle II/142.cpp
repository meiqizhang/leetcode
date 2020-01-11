/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

Note: Do not modify the linked list.



Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.


Example 2:

Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.


Example 3:

Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.

*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head == nullptr) return nullptr;
        if (head->next == head) return head;

        ListNode *fast = head->next;
        ListNode *slow = head;
        ListNode *meet = nullptr;

        while (fast != nullptr)
        {
            if (fast == slow)
            {
                meet = fast;
                break;
            }
            slow = slow->next;

            fast = fast->next;
            if (fast != nullptr)
                fast = fast->next;
        }

        if (meet == nullptr) return nullptr;

        ListNode *p = head;
        ListNode *q = meet->next;
        int index = 0;

        while (p != q)
        {
            index++;
            p = p->next;
            q = q->next;
        }

        return p;
    }
};

int main()
{
    return 0;
}