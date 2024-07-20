class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        map<int, vector<int>> collision;
        for(int i = 0; i < positions.size(); i++) {
            if(directions[i] == 'R') {
                for(int j = 0; j < positions.size(); j++) {
                    if(directions[j] == 'L') {
                        if(positions[i] < positions[j]) collision[i].push_back(j); 
                    }
                }
            } else {
                for(int j = 0; j < positions.size(); j++) {
                    if(directions[j] == 'R') {
                        if(positions[i] > positions[j]) collision[i].push_back(j); 
                    }
                }
            }
        }

        for(auto i : collision) {
            for(int j : i.second) {
                cout << j << " ";
                if(healths[i.first] > 0 && healths[j] > 0) {
                    int temp = healths[i.first];
                    healths[i.first] -= healths[j];
                    healths[j] -= temp;                    
                }
                if(healths[j])
            }
            cout << endl;
        }
        return healths;
    }
};

/*
self R move:
    opposite: L move 
    self pos < L move pos
    collision
self L move:
    oppo: R
    self pos < 

*/