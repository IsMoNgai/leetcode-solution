#include <iostream>
#include <vector>
#include <deque>

using namespace std;


class Solution {
public:
    int findTheWinner(int n, int k) {
        deque<int> d;
        for(int i = 1; i <= n; i++) {
            d.push_back(i);
        }
        while(d.size() != 1){
            for(int i = 0; i < k-1; i++) {
                d.push_back(d.front());
                d.pop_front();
            }
            d.pop_front();
        }
        return d.front();
    }
};