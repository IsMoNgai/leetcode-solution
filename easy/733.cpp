#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void print2D(vector<vector<int>> arr) {
    for(auto x : arr) {
        for(int y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
}

void print2D(vector<vector<bool>> arr) {
    for(auto x : arr) {
        for(int y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
}

void floodfill(vector<vector<int>> &image, int sr, int sc, int color) {
    int row = image.size();
    int col = image[0].size();
    vector<vector<bool>> visited(row, vector<bool>(col, false));    

    queue<vector<int>> q;
    q.push(vector<int>{sr,sc});

    int oldColor = image[sr][sc];
    // image[row][col]

    while(q.size() > 0) {
        vector<int> vec = q.front();

        // cout << "(" << vec[0] << "," << vec[1] << ")" << endl;
        // cout << "image" << endl;
        // print2D(image);
        // cout << "visited" << endl;
        // print2D(visited);
        
        q.pop();
        if(!visited[vec[0]][vec[1]]) {
            //visited
            image[vec[0]][vec[1]] = color;

            visited[vec[0]][vec[1]] = true;

            //down
            if (vec[0] + 1 < row && image[vec[0] + 1][vec[1]] == oldColor && !visited[vec[0] + 1][vec[1]]) { // Corrected boundary check
                q.push(vector<int>{vec[0] + 1, vec[1]});
            }
            //up
            if(vec[0]-1 >= 0 && image[vec[0]-1][vec[1]] == oldColor && !visited[vec[0]-1][vec[1]]) {
                q.push(vector<int>{vec[0]-1, vec[1]});
            }
            //right
            if(vec[1]+1 < col && image[vec[0]][vec[1]+1] == oldColor && !visited[vec[0]][vec[1]+1]) {
                q.push(vector<int>{vec[0], vec[1]+1});
            }
            //left
            if(vec[1]-1 >= 0 && image[vec[0]][vec[1]-1] == oldColor && !visited[vec[0]][vec[1]-1]) {
                q.push(vector<int>{vec[0], vec[1]-1});
            }
        }
    }

}

int main() {
    vector<vector<int>> image = {
        {1,1,1},
        {1,1,0},
        {1,0,1},
    };
    // vector<vector<int>> res = {
    //     {0,0,0},
    //     {0,0,0},
    //     {0,0,0}
    // };

    floodfill(image, 1, 1, 2);

    print2D(image);

}