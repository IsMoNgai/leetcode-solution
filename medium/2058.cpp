#include <iostream>
#include <vector>
#include <climits>

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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* ptr = head;
        int pos = 0;
        int prev = -1;
        vector<int> coord;

        while(ptr->next) {
            if(prev != -1) {
                int next = ptr->next->val;
                if(ptr->val < next && ptr->val < prev){
                    coord.push_back(pos);
                }
                if(ptr->val > next && ptr->val > prev){
                    coord.push_back(pos);
                }
            }
            pos++;
            prev = ptr->val;
            ptr = ptr->next;
        }
        if(prev == -1 || coord.size() < 2) return {-1,-1};
        int maxD = coord[coord.size()-1] - coord[0];
        int minD = INT_MAX;
        
        for(int i = 0; i < coord.size()-1; i++) {
            minD = min(minD, coord[i+1] - coord[i]);
        }
        return {minD, maxD};
    }
};