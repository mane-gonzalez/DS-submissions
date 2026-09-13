/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        //at this step, left has decreased so now its on the right cutting place 
        if(left == 1) {
            return reverseList(head, right).first;
        }

        head->next = reverseBetween(head->next, left - 1, right - 1);

        return head;
    }

private:
    pair<ListNode*, ListNode*> reverseList(ListNode* root, int n) {
        ListNode* originalHead = root;
        ListNode *prev = nullptr;
        ListNode *next = nullptr;

        int count = 0;
        while(root && count < n) {
            next = root->next;
            root->next = prev;
            prev = root;
            root = next;

            count++;    
        }

        originalHead->next = root;

        return {prev, root};
    }
};