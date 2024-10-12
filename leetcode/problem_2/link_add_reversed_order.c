#include <stdlib.h>
/////////////////////////////

struct ListNode {
   int val;
   struct ListNode *next;
};


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int sum = 0;
    struct ListNode *p = l1, *q = l2, *ans = NULL, *m = NULL;
    ans = (struct ListNode*)malloc(sizeof(struct ListNode));
    ans->next = NULL;
    struct ListNode *r = ans;
    while(p != NULL || q != NULL || sum) {
        sum += ((p ? p->val : 0) + (q ? q->val : 0));
        if (p) p = p->next;
        if (q) q = q->next;
        struct ListNode *w = NULL;
        w = (struct ListNode*)malloc(sizeof(struct ListNode));
        w->val = (sum % 10); w->next = NULL;
        r->next = w;
        r = r->next;
        sum /= 10;
    }
    return ans->next;
}