 /* Definition for singly-linked list.*/
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        ListNode* ret = nullptr;
        ListNode* ptrRet = ret; 
        bool carry = false;
        // Edge case: one of the number is nullptr.
        while (ptr1 != nullptr || ptr2 != nullptr || carry)
        {
            auto val1 = (ptr1 == nullptr) ? 0 : ptr1->val;
            auto val2 = (ptr2 == nullptr) ? 0 : ptr2->val;
            auto totalVal = (val1 + val2 + ((carry) ? 1 : 0));
            auto addedVal = totalVal % 10;
            carry = totalVal >= 10;
            if (ptrRet == nullptr)
            {
                ptrRet = new ListNode(addedVal);
                ret = ptrRet;
            }
            else
            {
                ptrRet->next = new ListNode(addedVal);
                ptrRet = ptrRet->next;
            }
            ptr1 = (ptr1 == nullptr) ? nullptr : ptr1->next;
            ptr2 = (ptr2 == nullptr) ? nullptr : ptr2->next;
        }
        return ret;
    }
};