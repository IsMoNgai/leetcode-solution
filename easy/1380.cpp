#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        /*
        find min of each row
        pos of these numbers [check col]
        O[n^2 + d^2]
        */
        vector<int> lucky;
        vector<pair<int, int>> minPos;
        for(int j = 0; j < matrix.size(); j++) {
            int minInRow = INT_MAX;
            pair<int, int> pos;
            for(int i = 0; i < matrix[j].size(); i++) {
                if(minInRow > matrix[j][i]) {
                    minInRow = matrix[j][i];
                    pos.first = j;
                    pos.second = i;
                }
            }
            minPos.push_back(pos);
        }

        for(auto pos : minPos) {
            int maxInCol = 0;
            for(int j = 0; j < matrix.size(); j++) {
                if(maxInCol < matrix[j][pos.second]) {
                    maxInCol = matrix[j][pos.second];
                }
            }
            if(maxInCol == matrix[pos.first][pos.second]) {
                lucky.push_back(maxInCol);
            }
        }
        return lucky;
    }
};