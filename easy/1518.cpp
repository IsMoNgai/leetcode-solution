#include <iostream>

using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drank = numBottles;
        int emptyBottles = numBottles;
        while(emptyBottles >= numExchange) {
            numBottles = emptyBottles/numExchange;
            emptyBottles = emptyBottles%numExchange;
            drank += numBottles;
            emptyBottles += numBottles;
        }
        return drank;
    }
};