#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* result = new ListNode(0);
        ListNode* ptr = result;
        head = head->next;
        while(head->next) {
            if(head->val == 0) {
                ListNode* temp = new ListNode(0);
                ptr->next = temp;
                ptr = ptr->next;
            } else {
                ptr->val += head->val;
            }
            // cout << ptr->val << endl;
            head = head->next;
        }
        return result;
    }
};