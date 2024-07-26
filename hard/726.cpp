#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>

using namespace std;

class Solution {
public:
    string countOfAtoms(string formula) {
        int i = 0;
        stack<map<string,int>> s;
        map<string, int> starter = {};
        s.push(starter);
        while(i < formula.size()){
            if(formula[i] >= 'A' && formula[i] <= 'Z') {
                string str = "";
                int num = 0;
                str += formula[i];
                if(i+1 < formula.size() && (formula[i+1] >= 'a' && formula[i+1] <= 'z')) {
                    str += formula[i+1];
                    i++;
                }
                while(i+1 < formula.size() && (formula[i+1] >= '0' && formula[i+1] <= '9')) {
                    num = num*10 + (formula[i+1] - '0');
                    i++;
                }
                if(num == 0) num = 1;
                s.top()[str] += num;
            }
            else if(formula[i] == '(') {
                map<string, int> m;
                s.push(m);
            }
            else if(formula[i] == ')') {
                int num = 0;
                while(i+1 < formula.size() && (formula[i+1] >= '0' && formula[i+1] <= '9')) {
                    num = num*10 + (formula[i+1] - '0');
                    i++;
                }
                if(num == 0) num = 1;
                map<string, int> m = s.top();
                s.pop();
                for(auto j : m) {
                    s.top()[j.first] += j.second*num;
                }
            }
            i++;
        }
        string res = "";
        for(auto k : s.top()) {
            res += k.first;
            if(k.second != 1) res += to_string(k.second);
        }
        return res;
    }
};
