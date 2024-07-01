class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int p1 = 0;
        int p2 = 0;
        if(arr.size() < 3) return false;
        int odd = 0;
        while(p2 < arr.size() && p1 < arr.size()) {
            if(arr[p2] % 2 == 0) {
                p2++;
                p1 = p2;
                odd = 0;
            }
            else {
                p2++;      
                odd++;          
            }
            if(odd == 3) return true;
      
        }
        return false;
    }
};