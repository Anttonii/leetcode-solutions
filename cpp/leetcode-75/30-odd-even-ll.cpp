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
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *os = head;
        ListNode *o = head;

        ListNode *es = head->next;
        ListNode *e = head->next;
        while (o->next != NULL && e->next != NULL)
        {
            o->next = e->next;
            o = o->next;

            if (o->next != NULL)
            {
                e->next = o->next;
                e = e->next;
            }
        }
        e->next = NULL;
        o->next = es;

        return os;
    }
};