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
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *curr = head;
        ListNode *res = curr->next;
        ListNode *prev = NULL;
        while (curr->next != NULL)
        {
            ListNode *next = curr->next->next;
            if (prev != NULL)
                prev->next = curr->next;
            curr->next->next = curr;
            curr->next = next;
            prev = curr;
            if (curr->next != NULL)
                curr = curr->next;
        }
        return res;
    }
};