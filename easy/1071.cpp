#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int a = str2.size();
        int b = str1.size();
        while(b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        int gcd = a;
        string ans = str1.substr(0, gcd);
        str1 + str2 == str2 + str1 ? ans = ans : ans = "";
        return ans;
    }
};