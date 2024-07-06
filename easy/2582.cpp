class Solution {
public:
    int passThePillow(int n, int time) {
        int pos = 1;
        bool dir = true; //forward
        while(time > 0) {
            if(dir) {
                pos++;
            } else {
                pos--;
            }
            if(pos == n || pos == 1) {
                dir = !dir;
            }
            time--;
        }
        return pos;
    }
};