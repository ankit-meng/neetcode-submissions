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
    void reorderList(ListNode* head) {
        vector<ListNode*> nodes;

        ListNode* temp = head;

        while (temp != nullptr) {
            nodes.push_back(temp);
            temp = temp->next;
        }

        int left = 1;
        int right = nodes.size() - 1;

        ListNode* curr = head;

        while (left <= right) {
            curr->next = nodes[right];
            curr = nodes[right];
            right--;

            if (left <= right) {
                curr->next = nodes[left];
                curr = nodes[left];
                left++;
            }
        }

        curr->next = nullptr;
    }
};
