#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int tnow = customers[0][0];
        double avg = 0;
        for(auto t : customers) {
            int twait;
            if(tnow > t[0]) {
                tnow += t[1];
                twait = tnow-t[0];
            } else {
                tnow = t[1] + t[0];
                twait = t[1];
            }
            avg += twait;
        }
        return avg/customers.size();
    }
};