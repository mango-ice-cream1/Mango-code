
//�����㷨��-����ת����

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {

    int s[100000] = { 0 };
    int i = 0;
    struct ListNode* p = head;


    while (p != NULL)
    {
        s[i++] = p->val;
        p = p->next;
    }
    int j = 0;
    i--;
    for (j = 0; j < i; j++, i--)
    {
        if (s[j] != s[i])
        {
            return false;
        }
    }
    return true;

}