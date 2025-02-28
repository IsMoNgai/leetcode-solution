#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int l = 0;
        int r = matrix[0].size()-1;
        while(r >= l) {
            for(int i = 0; i < r-l; i++) {
                int t = l;
                int b = r;
                int temp = matrix[t][l+i];
                matrix[t][l + i] = matrix[b-i][l];
                matrix[b-i][l] = matrix[b][r-i];
                matrix[b][r-i] = matrix[t+i][r];
                matrix[t+i][r] = temp;            
            }
            r--;
            l++;
        }
    }
};