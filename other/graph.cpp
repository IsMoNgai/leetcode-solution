#include <iostream>
#include <map>
#include <list>
#include <stack>
#include <queue>

using namespace std;

class Graph {
    public:
        map<int, bool> visited;
        map<int, list<int>> adj;

        void dfs(int v);

        void bfs(int v);

        void addEdge(int v, int w);

        void printGraph();
};

void Graph::printGraph() {
    for(auto i = adj.begin(); i != adj.end(); i++) {
        cout << i->first << " : ";
        for(auto it = i->second.begin(); it != i->second.end(); it++) {
            cout << *it << " ";
        } 
        cout << endl;
    }
}

void Graph::dfs(int v) {
    stack<int> s;
    s.push(v);
    while(s.size() > 0) {
        int x = s.top();
        s.pop();
        if(!visited[x]) {
            cout << x << " ";
            visited[x] = true;
            for(int i : adj[x]) {
                if(!visited[i]) {
                    s.push(i);
                }
            }
        }
    }
}

void Graph::bfs(int v) {
    queue<int> q;
    q.push(v);
    while(q.size() > 0) {
        int x = q.front();
        q.pop();
        if(!visited[x]) {
            //visit
            cout << x << " ";
            visited[x] = true;
            for(int i : adj[x]) {
                if(!visited[i]) {
                    q.push(i);
                }
            }
        }
    }
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
    visited[v] = false;
    visited[w] = false;
}

int main() {
    Graph g;
    g.addEdge(1,0);
    g.addEdge(0,2);
    g.addEdge(2,4);
    g.addEdge(3,2);
    g.addEdge(0,3);


    g.bfs(2);
}
