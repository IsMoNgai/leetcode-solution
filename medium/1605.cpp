#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>> res(rowSum.size(), vector<int>(colSum.size(), 0));

        for(int i = 0; i < rowSum.size(); i++) {
            res[i][0] = rowSum[i];
        }

        for(int j = 0; j < colSum.size()-1; j++) {
            // compute sum of col
            long long int sum = 0;
            for(int i = 0; i < rowSum.size(); i++) {
                sum += res[i][j];
            }
            if(sum >= colSum[j]) {
                int next = 0;
                for(int i = 0; i < rowSum.size(); i++) {
                    if(i == 0) {
                        sum -= colSum[j];
                    } else {
                        sum -= next;
                    }
                    next = min(static_cast<long long>(sum), static_cast<long long>(res[i][j]));
                    res[i][j+1] = next;
                    res[i][j] -= next;
                }                  
            }
        }

        return res;
    }
};