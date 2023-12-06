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
    ListNode *deleteMiddle(ListNode *head)
    {
        ListNode *s = new ListNode(0, head);
        ListNode *f = head;

        if (f->next == NULL)
            head = NULL;

        while (f->next != NULL)
        {
            s = s->next;
            f = f->next;
            if (f->next != NULL)
                f = f->next;
        }
        ListNode *n = s->next->next;
        s->next = n;

        return head;
    }
};